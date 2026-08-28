#!/usr/bin/env ruby
# Generates DSH.xcodeproj — the Xcode project for the DSH app; it references
# the iSH-ARM64 emulator sources in ./ish-arm64.
#
# Targets:
#   DSH         the app (emulator sources + dsh-ios/app + bundled root.tar.gz)
#   DSHTests    XCTest bundle hosted in the app (unit + guest integration)
#   DSHUITests  XCUITest bundle
# Shared scheme "DSH" builds/tests all three.
#
# Re-run after adding/removing source files (idempotent: rewrites the project).
# Requires the `xcodeproj` gem (ships with CocoaPods).
require 'xcodeproj'
require 'pathname'

HERE = Pathname.new(__FILE__).expand_path.dirname
ROOT = HERE.parent                                   # repo root
ISH = (ROOT + 'ish-arm64').expand_path                # ./ish-arm64
PROJECT_PATH = ROOT + 'DSH.xcodeproj'
ISH_REL = 'ish-arm64'

abort "iSH-ARM64 sources not found at #{ISH}" unless (ISH + 'iSH.xcodeproj').exist?

# --- what the iSH-ARM64 target compiles/bundles (mirrored from its pbxproj) --
ish_project = Xcodeproj::Project.open((ISH + 'iSH.xcodeproj').to_s)
ish_target = ish_project.targets.find { |t| t.name == 'iSH-ARM64' } or abort 'iSH-ARM64 target missing'
rel = ->(ref) { Pathname.new(ref.real_path.to_s).relative_path_from(ISH).to_s }
ish_sources = ish_target.source_build_phase.files.reject { |bf| bf.file_ref.source_tree == 'DEVELOPER_DIR' }
                        .map { |bf| rel.(bf.file_ref) }.reject { |p| p.end_with?('main.m') }
ish_sources << 'app/ISHShellExecutor.m' unless ish_sources.include?('app/ISHShellExecutor.m')
ish_resources = ish_target.resources_build_phase.files.flat_map do |bf|
  ref = bf.file_ref
  if ref.isa == 'PBXVariantGroup'
    ref.children.map { |c| rel.(c) }          # Base.lproj/*.storyboard
  else
    [rel.(ref)]
  end
end.uniq
ish_resources << 'app/RootfsPatch.bundle' unless ish_resources.include?('app/RootfsPatch.bundle')
system_frameworks = ish_target.frameworks_build_phase.files.map(&:file_ref)
                              .select { |r| r.isa == 'PBXFileReference' }.map(&:path)
meson_phase = ish_target.build_phases.find { |p| p.isa == 'PBXShellScriptBuildPhase' && p.name.to_s.start_with?('Build Meson') }
mig_rule = ish_target.build_rules.first or abort 'mig build rule missing'

# --- new project ------------------------------------------------------------
FileUtils.rm_rf(PROJECT_PATH)
project = Xcodeproj::Project.new(PROJECT_PATH.to_s)
project.root_object.attributes['LastUpgradeCheck'] = '2700'

# Project-level configs come from iSH so warnings/flags match the emulator build.
ish_group = project.main_group.new_group('ish-arm64', ISH_REL)
app_group = project.main_group.new_group('app', 'app')
tests_group = project.main_group.new_group('tests', 'tests')
config_group = ish_group.new_group('xcconfig', 'app')
project_debug_cfg = config_group.new_file('ProjectDebug.xcconfig')
project_release_cfg = config_group.new_file('ProjectRelease.xcconfig')
project.build_configurations.each do |bc|
  bc.build_settings.clear
  bc.base_configuration_reference = bc.name == 'Debug' ? project_debug_cfg : project_release_cfg
end

# iSH sources/resources under the ish-arm64 group (kept in folders by path)
def ref_for(group, relpath, cache)
  cache[relpath] ||= begin
    dir, base = File.split(relpath)
    g = group
    unless dir == '.'
      dir.split('/').each do |part|
        g = g.children.find { |c| c.isa == 'PBXGroup' && c.path == part } || g.new_group(part, part)
      end
    end
    g.new_file(base)
  end
end
cache = {}
ish_source_refs = ish_sources.map { |p| ref_for(ish_group, p, cache) }
ish_resource_refs = ish_resources.map { |p| ref_for(ish_group, p, cache) }
patch_ref = cache['app/RootfsPatch.bundle']
patch_ref.last_known_file_type = 'wrapper.plug-in'
mig_ref = ish_group.new_file('Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/mach_exc.defs')
mig_ref.source_tree = 'DEVELOPER_DIR'
mig_ref.name = 'mach_exc.defs'
mig_ref.last_known_file_type = 'sourcecode.mig'

# libarchive comes from iSH's subproject
libarchive_ref = project.main_group.new_file("#{ISH_REL}/deps/libarchive.xcodeproj")
libarchive_project = Xcodeproj::Project.open((ISH + 'deps/libarchive.xcodeproj').to_s)
libarchive_target = libarchive_project.targets.find { |t| t.name == 'libarchive' } or abort 'libarchive target missing'

# our files
app_dir = ROOT + 'app'
app_source_refs = Dir[(app_dir + '*.{m,swift}').to_s].sort.map { |f| app_group.new_file(File.basename(f)) }
Dir[(app_dir + '*.h').to_s].sort.each { |f| app_group.new_file(File.basename(f)) }
xcconfig_ref = app_group.new_file('AppDSH.xcconfig')
app_group.new_file('Info.plist')
app_group.new_file('DSH.entitlements')
app_resource_refs = %w[DSHAssets.xcassets DSHLaunchScreen.storyboard PrivacyInfo.xcprivacy].map { |f| app_group.new_file(f) }
project.main_group.new_file('README.md')
project.main_group.new_file('Makefile')
scripts_group = project.main_group.new_group('scripts', 'scripts')
Dir[(ROOT + 'scripts/*').to_s].sort.each { |f| scripts_group.new_file(File.basename(f)) }
rootfs_group = project.main_group.new_group('rootfs', 'rootfs')
Dir[(ROOT + 'rootfs/**/*').to_s].sort.select { |f| File.file?(f) }.each do |f|
  ref_for(rootfs_group, Pathname.new(f).relative_path_from(ROOT + 'rootfs').to_s, cache)
end

# --- app target ---------------------------------------------------------------
dsh = project.new_target(:application, 'DSH', :ios, '16.0')
dsh.build_configuration_list.build_configurations.each do |bc|
  bc.build_settings.clear
  bc.base_configuration_reference = xcconfig_ref
end
rule = project.new(Xcodeproj::Project::Object::PBXBuildRule)
rule.compiler_spec = mig_rule.compiler_spec
rule.file_type = mig_rule.file_type
rule.is_editable = mig_rule.is_editable
rule.output_files = mig_rule.output_files.dup
rule.script = mig_rule.script
dsh.build_rules << rule

(ish_source_refs + app_source_refs).each { |r| dsh.source_build_phase.add_file_reference(r, true) }
mig_bf = dsh.source_build_phase.add_file_reference(mig_ref, true)
mig_bf.settings = { 'ATTRIBUTES' => ['Server'] }

system_frameworks.each do |path|
  ref = project.frameworks_group.new_file(path)
  ref.source_tree = 'SDKROOT'
  dsh.frameworks_build_phase.add_file_reference(ref, true)
end
dsh.add_dependency(libarchive_target)
product_group = project.root_object.project_references.find { |r| r[:project_ref] == libarchive_ref }[:product_group]
libarchive_product = product_group.children.find { |c| c.path.to_s == 'libarchive.a' } or abort 'libarchive.a proxy missing'
dsh.frameworks_build_phase.add_file_reference(libarchive_product, true)

(ish_resource_refs + app_resource_refs).each { |r| dsh.resources_build_phase.add_file_reference(r, true) }

meson = dsh.new_shell_script_build_phase('Build Meson (iSH-ARM64)')
meson.shell_script = <<~SH
  # Builds libish.a / libish_emu.a / libfakefs.a with meson from ./ish-arm64.
  export ISH_SRC="$SRCROOT/ish-arm64"
  export SRCROOT="$ISH_SRC"       # iSH's helper scripts locate their sources via SRCROOT
  "$ISH_SRC/app/xcode-meson.sh"
  cd "$MESON_BUILD_DIR"
  "$ISH_SRC/app/xcode-ninja.sh" $NINJA_TARGETS
SH
meson.always_out_of_date = '1'
meson.show_env_vars_in_log = '0'

copy_root = dsh.new_shell_script_build_phase('Copy DSH Root')
copy_root.shell_script = <<~SH
  set -e
  if [ ! -f "$DSH_ROOTFS_TARBALL" ]; then
    echo "error: $DSH_ROOTFS_TARBALL not found. Run: make -C \\"$SRCROOT\\" rootfs" >&2
    exit 1
  fi
  cp "$DSH_ROOTFS_TARBALL" "$BUILT_PRODUCTS_DIR/$CONTENTS_FOLDER_PATH/root.tar.gz"
  shasum -a 256 "$DSH_ROOTFS_TARBALL" | cut -d' ' -f1 > "$BUILT_PRODUCTS_DIR/$CONTENTS_FOLDER_PATH/root.tar.gz.sha256"
SH
copy_root.input_paths = ['$(DSH_ROOTFS_TARBALL)']
copy_root.output_paths = ['$(BUILT_PRODUCTS_DIR)/$(CONTENTS_FOLDER_PATH)/root.tar.gz', '$(BUILT_PRODUCTS_DIR)/$(CONTENTS_FOLDER_PATH)/root.tar.gz.sha256']

apk = dsh.new_shell_script_build_phase('Generate APK Repositories File')
apk.shell_script = "SRCROOT=\"$SRCROOT/ish-arm64\" python3 \"$SRCROOT/ish-arm64/app/gen_apk_repositories.py\"\n"
apk.input_paths = ['$(SRCROOT)/ish-arm64/app/gen_apk_repositories.py']
apk.output_paths = ['$(BUILT_PRODUCTS_DIR)/$(CONTENTS_FOLDER_PATH)/repositories.txt']

js = dsh.new_shell_script_build_phase('Compile hterm JavaScript')
js.shell_script = "cd \"$SRCROOT/ish-arm64/deps/libapps\" && ./hterm/bin/mkdist\n"
js.input_paths = ['$(SRCROOT)/ish-arm64/deps/libapps/hterm/js']
js.output_paths = ['$(SRCROOT)/ish-arm64/deps/libapps/hterm/dist/js/hterm_all.js']

phases = dsh.build_phases
ordered = [meson, dsh.source_build_phase, dsh.frameworks_build_phase, copy_root, apk, js, dsh.resources_build_phase]
ordered.each { |ph| phases.delete(ph) }
ordered.each { |ph| phases << ph }

# --- test bundles -------------------------------------------------------------
common_test_settings = {
  'PRODUCT_NAME' => '$(TARGET_NAME)',
  'IPHONEOS_DEPLOYMENT_TARGET' => '16.0',
  'SDKROOT' => 'iphoneos',
  'SUPPORTED_PLATFORMS' => 'iphoneos iphonesimulator',
  'TARGETED_DEVICE_FAMILY' => '1,2',
  'CODE_SIGN_STYLE' => 'Automatic',
  'DEVELOPMENT_TEAM' => '$(DSH_DEVELOPMENT_TEAM)',
  'GENERATE_INFOPLIST_FILE' => 'NO',
  'CLANG_ENABLE_OBJC_ARC' => 'YES',
  'CLANG_ENABLE_MODULES' => 'YES',
  'LD_RUNPATH_SEARCH_PATHS' => '$(inherited) @executable_path/Frameworks @loader_path/Frameworks',
  'ALWAYS_EMBED_SWIFT_STANDARD_LIBRARIES' => 'NO',
  'ARCHS[sdk=iphonesimulator*]' => 'arm64',
  'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'x86_64 i386',
  'HEADER_SEARCH_PATHS' => '$(inherited) $(SRCROOT)/ish-arm64 $(SRCROOT)/ish-arm64/app $(SRCROOT)/app',
}

tests = project.new_target(:unit_test_bundle, 'DSHTests', :ios, '16.0')
tg = tests_group.new_group('DSHTests', 'DSHTests')
Dir[(ROOT + 'tests/DSHTests/*.m').to_s].sort.each { |f| tests.source_build_phase.add_file_reference(tg.new_file(File.basename(f)), true) }
Dir[(ROOT + 'tests/DSHTests/*.h').to_s].sort.each { |f| tg.new_file(File.basename(f)) }
tg.new_file('Info.plist')
tests.build_configuration_list.build_configurations.each do |bc|
  bc.build_settings.clear
  bc.build_settings.merge!(common_test_settings, {
    'PRODUCT_BUNDLE_IDENTIFIER' => 'com.xnuapp.dsh.tests',
    'INFOPLIST_FILE' => '$(SRCROOT)/tests/DSHTests/Info.plist',
    'TEST_HOST' => '$(BUILT_PRODUCTS_DIR)/DSH.app/DSH',
    'BUNDLE_LOADER' => '$(TEST_HOST)',
  })
end
tests.add_dependency(dsh)

uitests = project.new_target(:ui_test_bundle, 'DSHUITests', :ios, '16.0')
ug = tests_group.new_group('DSHUITests', 'DSHUITests')
Dir[(ROOT + 'tests/DSHUITests/*.m').to_s].sort.each { |f| uitests.source_build_phase.add_file_reference(ug.new_file(File.basename(f)), true) }
ug.new_file('Info.plist')
uitests.build_configuration_list.build_configurations.each do |bc|
  bc.build_settings.clear
  bc.build_settings.merge!(common_test_settings, {
    'PRODUCT_BUNDLE_IDENTIFIER' => 'com.xnuapp.dsh.uitests',
    'INFOPLIST_FILE' => '$(SRCROOT)/tests/DSHUITests/Info.plist',
    'TEST_TARGET_NAME' => 'DSH',
    'USES_XCTRUNNER' => 'YES',
  })
end
uitests.add_dependency(dsh)

# host-side test scripts, for browsing
scripts_tests = tests_group
%w[emu-test.sh rootfs-test.sh mock-deepseek.mjs fetch-polyfill-test.mjs].each { |f| scripts_tests.new_file(f) }
tests_group.new_group('emu', 'emu').new_file('neon_convert_test.c')

attrs = (project.root_object.attributes['TargetAttributes'] ||= {})
attrs[tests.uuid] = { 'TestTargetID' => dsh.uuid }
attrs[uitests.uuid] = { 'TestTargetID' => dsh.uuid }
project.save

# --- scheme -------------------------------------------------------------------
scheme = Xcodeproj::XCScheme.new
scheme.configure_with_targets(dsh, tests, launch_target: true)
# The emulator uses SIGUSR1/SIGTTIN/SIGPIPE as normal machinery; without this
# LLDB stops on every one of them and it looks like a crash. See .lldbinit.
scheme.launch_action.xml_element.attributes['customLLDBInitFile'] = '$(SRCROOT)/.lldbinit'
scheme.test_action.xml_element.attributes['customLLDBInitFile'] = '$(SRCROOT)/.lldbinit'
scheme.add_build_target(uitests, false)
scheme.test_action.add_testable(Xcodeproj::XCScheme::TestAction::TestableReference.new(uitests))
%w[test_action launch_action profile_action analyze_action archive_action].each do |a|
  scheme.send(a).build_configuration = 'Release'
end
scheme.save_as(PROJECT_PATH.to_s, 'DSH', true)
puts "ok: #{PROJECT_PATH} (DSH, DSHTests, DSHUITests) — open it and pick the DSH scheme"
