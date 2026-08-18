//
//  DSHRootViewController.m
//  DSH
//

#import "DSHRootViewController.h"
#import "DSHHarness.h"
#import "DSHLogViewController.h"
#import "DSHStatusOverlayView.h"
#import "TerminalViewController.h"
#import "AppDelegate.h"
#import <WebKit/WebKit.h>

static NSString *const kDSHUserAgentSuffix = @" DSH-iOS/1.0";

@interface DSHRootViewController () <WKNavigationDelegate, WKUIDelegate, WKDownloadDelegate>
@property (nonatomic) WKWebView *webView;
@property (nonatomic) DSHStatusOverlayView *overlay;
@property (nonatomic) UIView *controlBar;
@property (nonatomic) NSLayoutConstraint *controlBarHeight;
@property (nonatomic) UILabel *titleLabel;
@property (nonatomic) UIView *statusDot;
@property (nonatomic) UIButton *menuButton;
@property (nonatomic) UIButton *terminalButton;
@property (nonatomic, nullable) TerminalViewController *terminalVC;
@property (nonatomic) uint16_t loadedPort;
@property (nonatomic) BOOL pageLoaded;
@property (nonatomic) NSMutableDictionary<NSValue *, NSURL *> *downloadDestinations;
@end

@implementation DSHRootViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor colorNamed:@"DSHBackground"] ?: UIColor.systemBackgroundColor;
    self.downloadDestinations = [NSMutableDictionary dictionary];

    [self buildWebView];
    [self buildControlBar];
    [self buildOverlay];

    NSNotificationCenter *nc = NSNotificationCenter.defaultCenter;
    [nc addObserver:self selector:@selector(harnessStateChanged:) name:DSHHarnessStateDidChangeNotification object:nil];
    [nc addObserver:self selector:@selector(logChanged:) name:DSHLogBufferDidChangeNotification object:nil];
    [self applyHarnessState];
}

- (void)dealloc {
    [NSNotificationCenter.defaultCenter removeObserver:self];
}

#pragma mark - Building the view

- (void)buildWebView {
    WKWebViewConfiguration *config = [WKWebViewConfiguration new];
    config.allowsInlineMediaPlayback = YES;
    config.websiteDataStore = WKWebsiteDataStore.defaultDataStore;
    config.applicationNameForUserAgent = kDSHUserAgentSuffix;
    config.defaultWebpagePreferences.allowsContentJavaScript = YES;
    self.webView = [[WKWebView alloc] initWithFrame:CGRectZero configuration:config];
    self.webView.navigationDelegate = self;
    self.webView.UIDelegate = self;
    self.webView.allowsBackForwardNavigationGestures = NO;
    self.webView.scrollView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    self.webView.scrollView.bounces = NO;
    self.webView.opaque = NO;
    self.webView.backgroundColor = UIColor.clearColor;
    self.webView.scrollView.backgroundColor = UIColor.clearColor;
    self.webView.translatesAutoresizingMaskIntoConstraints = NO;
    self.webView.accessibilityIdentifier = @"dsh.webview";
#if DEBUG
    if (@available(iOS 16.4, *))
        self.webView.inspectable = YES;
#endif
    [self.view addSubview:self.webView];
}

- (void)buildControlBar {
    UIView *bar = [UIView new];
    bar.translatesAutoresizingMaskIntoConstraints = NO;
    bar.backgroundColor = UIColor.clearColor;
    bar.accessibilityIdentifier = @"dsh.controlbar";
    self.controlBar = bar;
    [self.view addSubview:bar];

    UIView *dot = [UIView new];
    dot.translatesAutoresizingMaskIntoConstraints = NO;
    dot.layer.cornerRadius = 4;
    dot.backgroundColor = UIColor.systemOrangeColor;
    dot.accessibilityIdentifier = @"dsh.statusdot";
    dot.isAccessibilityElement = YES;
    dot.accessibilityLabel = @"Harness status";
    self.statusDot = dot;

    UILabel *title = [UILabel new];
    title.translatesAutoresizingMaskIntoConstraints = NO;
    title.text = @"DSH";
    title.font = [UIFont monospacedSystemFontOfSize:12 weight:UIFontWeightSemibold];
    title.textColor = UIColor.secondaryLabelColor;
    title.accessibilityIdentifier = @"dsh.title";
    self.titleLabel = title;

    UIButton *terminal = [self barButtonWithSymbol:@"terminal" action:@selector(presentTerminal) identifier:@"dsh.terminal"];
    terminal.accessibilityLabel = @"Terminal";
    self.terminalButton = terminal;

    UIButton *menu = [self barButtonWithSymbol:@"ellipsis.circle" action:nil identifier:@"dsh.menu"];
    menu.accessibilityLabel = @"More";
    menu.showsMenuAsPrimaryAction = YES;
    menu.menu = [self buildMenu];
    self.menuButton = menu;

    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[dot, title, [UIView new], terminal, menu]];
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    stack.axis = UILayoutConstraintAxisHorizontal;
    stack.alignment = UIStackViewAlignmentCenter;
    stack.spacing = 8;
    [bar addSubview:stack];

    self.controlBarHeight = [bar.heightAnchor constraintEqualToConstant:32];
    [NSLayoutConstraint activateConstraints:@[
        [bar.topAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.topAnchor],
        [bar.leadingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.leadingAnchor],
        [bar.trailingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.trailingAnchor],
        self.controlBarHeight,
        [stack.leadingAnchor constraintEqualToAnchor:bar.leadingAnchor constant:12],
        [stack.trailingAnchor constraintEqualToAnchor:bar.trailingAnchor constant:-8],
        [stack.topAnchor constraintEqualToAnchor:bar.topAnchor],
        [stack.bottomAnchor constraintEqualToAnchor:bar.bottomAnchor],
        [dot.widthAnchor constraintEqualToConstant:8],
        [dot.heightAnchor constraintEqualToConstant:8],

        [self.webView.topAnchor constraintEqualToAnchor:bar.bottomAnchor],
        [self.webView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [self.webView.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [self.webView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
    ]];
}

- (UIButton *)barButtonWithSymbol:(NSString *)symbol action:(nullable SEL)action identifier:(NSString *)identifier {
    UIButtonConfiguration *conf = [UIButtonConfiguration plainButtonConfiguration];
    conf.image = [UIImage systemImageNamed:symbol withConfiguration:[UIImageSymbolConfiguration configurationWithPointSize:14 weight:UIImageSymbolWeightMedium]];
    conf.contentInsets = NSDirectionalEdgeInsetsMake(2, 6, 2, 6);
    conf.baseForegroundColor = UIColor.secondaryLabelColor;
    UIButton *button = [UIButton buttonWithConfiguration:conf primaryAction:nil];
    button.translatesAutoresizingMaskIntoConstraints = NO;
    button.accessibilityIdentifier = identifier;
    if (action)
        [button addTarget:self action:action forControlEvents:UIControlEventTouchUpInside];
    return button;
}

- (UIMenu *)buildMenu {
    __weak typeof(self) weakSelf = self;
    UIAction *reload = [UIAction actionWithTitle:@"Reload" image:[UIImage systemImageNamed:@"arrow.clockwise"] identifier:@"dsh.reload" handler:^(UIAction *a) { [weakSelf reloadWebView]; }];
    UIAction *terminal = [UIAction actionWithTitle:@"Terminal" image:[UIImage systemImageNamed:@"terminal"] identifier:@"dsh.terminal.menu" handler:^(UIAction *a) { [weakSelf presentTerminal]; }];
    UIAction *log = [UIAction actionWithTitle:@"Server Log" image:[UIImage systemImageNamed:@"doc.text.magnifyingglass"] identifier:@"dsh.log" handler:^(UIAction *a) { [weakSelf presentLog]; }];
    UIAction *restart = [UIAction actionWithTitle:@"Restart Harness" image:[UIImage systemImageNamed:@"arrow.triangle.2.circlepath"] identifier:@"dsh.restart" handler:^(UIAction *a) { [weakSelf confirmRestart]; }];
    restart.attributes = UIMenuElementAttributesDestructive;
    UIAction *safari = [UIAction actionWithTitle:@"Open in Safari" image:[UIImage systemImageNamed:@"safari"] identifier:@"dsh.safari" handler:^(UIAction *a) {
        NSURL *url = DSHHarness.shared.baseURL;
        if (url) [UIApplication.sharedApplication openURL:url options:@{} completionHandler:nil];
    }];
    UIAction *about = [UIAction actionWithTitle:@"About DSH" image:[UIImage systemImageNamed:@"info.circle"] identifier:@"dsh.about" handler:^(UIAction *a) { [weakSelf presentAbout]; }];
    return [UIMenu menuWithChildren:@[reload, terminal, log, [UIMenu menuWithTitle:@"" image:nil identifier:nil options:UIMenuOptionsDisplayInline children:@[safari, restart]], about]];
}

- (void)buildOverlay {
    self.overlay = [[DSHStatusOverlayView alloc] initWithFrame:CGRectZero];
    self.overlay.translatesAutoresizingMaskIntoConstraints = NO;
    __weak typeof(self) weakSelf = self;
    self.overlay.retryHandler = ^{ [DSHHarness.shared restart]; };
    self.overlay.terminalHandler = ^{ [weakSelf presentTerminal]; };
    self.overlay.logHandler = ^{ [weakSelf presentLog]; };
    [self.view addSubview:self.overlay];
    [NSLayoutConstraint activateConstraints:@[
        [self.overlay.topAnchor constraintEqualToAnchor:self.controlBar.bottomAnchor],
        [self.overlay.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [self.overlay.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [self.overlay.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
    ]];
}

#pragma mark - Harness state

- (void)harnessStateChanged:(NSNotification *)note {
    [self applyHarnessState];
}

- (void)logChanged:(NSNotification *)note {
    [self.overlay setLogText:[DSHHarness.shared.log tail:12]];
}

- (void)applyHarnessState {
    DSHHarness *h = DSHHarness.shared;
    UIColor *dotColor;
    switch (h.state) {
        case DSHHarnessStateReady: dotColor = UIColor.systemGreenColor; break;
        case DSHHarnessStateFailed: dotColor = UIColor.systemRedColor; break;
        case DSHHarnessStateStopped: dotColor = UIColor.systemGrayColor; break;
        default: dotColor = UIColor.systemOrangeColor; break;
    }
    self.statusDot.backgroundColor = dotColor;
    self.statusDot.accessibilityValue = DSHHarnessStateName(h.state);
    self.titleLabel.text = h.port ? [NSString stringWithFormat:@"DSH · :%u", h.port] : @"DSH";

    if (AppDelegate.bootError != 0) {
        [self.overlay showFailure:[NSString stringWithFormat:@"The Linux guest failed to boot (error %d).", AppDelegate.bootError]];
        return;
    }

    switch (h.state) {
        case DSHHarnessStateIdle:
        case DSHHarnessStateStarting:
            [self.overlay showStarting:@"Starting DeepSeek Harness…"];
            break;
        case DSHHarnessStateRestarting:
            [self.overlay showStarting:@"Restarting the harness…"];
            self.pageLoaded = NO;
            break;
        case DSHHarnessStateReady:
            if (!self.pageLoaded || self.loadedPort != h.port)
                [self loadHarness];
            else
                [self.overlay hide];
            break;
        case DSHHarnessStateFailed:
            [self.overlay showFailure:h.lastError ?: @"The harness could not be started."];
            break;
        case DSHHarnessStateStopped:
            [self.overlay showFailure:@"The harness is stopped."];
            break;
    }
}

- (void)loadHarness {
    NSURL *url = DSHHarness.shared.baseURL;
    if (url == nil)
        return;
    [self.overlay showStarting:@"Loading the interface…"];
    self.loadedPort = DSHHarness.shared.port;
    self.pageLoaded = NO;
    NSMutableURLRequest *req = [NSMutableURLRequest requestWithURL:url];
    req.cachePolicy = NSURLRequestReloadIgnoringLocalCacheData;
    [self.webView loadRequest:req];
}

- (void)sceneDidBecomeActive {
    // After a suspension the page's websocket may be gone; the client
    // reconnects on its own, but a dead server needs a restart + reload.
    if (DSHHarness.shared.state == DSHHarnessStateReady && self.pageLoaded) {
        __weak typeof(self) weakSelf = self;
        [DSHHarness.shared verifyAliveWithCompletion:^(BOOL alive) {
            if (!alive) weakSelf.pageLoaded = NO;
        }];
    }
}

#pragma mark - Actions

- (void)reloadWebView {
    if (DSHHarness.shared.state == DSHHarnessStateReady)
        [self loadHarness];
    else
        [DSHHarness.shared start];
}

- (void)confirmRestart {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Restart the harness?"
                                                                   message:@"Running agent turns are interrupted; sessions are kept on disk."
                                                            preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:nil]];
    [alert addAction:[UIAlertAction actionWithTitle:@"Restart" style:UIAlertActionStyleDestructive handler:^(UIAlertAction *a) {
        [DSHHarness.shared restart];
    }]];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)presentTerminal {
    if (self.terminalVC == nil) {
        UIStoryboard *sb = [UIStoryboard storyboardWithName:@"Terminal" bundle:nil];
        TerminalViewController *vc = [sb instantiateInitialViewController];
        vc.sceneSession = nil; // never let a shell exit tear down our scene
        vc.modalPresentationStyle = UIModalPresentationPageSheet;
        [vc startNewSession];
        self.terminalVC = vc;
    }
    if (self.terminalVC.presentingViewController != nil)
        return;
    [self presentViewController:self.terminalVC animated:YES completion:nil];
}

- (void)presentLog {
    DSHLogViewController *vc = [[DSHLogViewController alloc] initWithLog:DSHHarness.shared.log];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    nav.modalPresentationStyle = UIModalPresentationPageSheet;
    [self presentViewController:nav animated:YES completion:nil];
}

- (void)presentAbout {
    DSHHarness *h = DSHHarness.shared;
    NSString *version = [NSString stringWithFormat:@"%@ (%@)",
                         [NSBundle.mainBundle objectForInfoDictionaryKey:@"CFBundleShortVersionString"],
                         [NSBundle.mainBundle objectForInfoDictionaryKey:(NSString *) kCFBundleVersionKey]];
    NSString *message = [NSString stringWithFormat:
                         @"DSH %@\n\nDeepSeek Harness running in an Alpine Linux guest (iSH ARM64 emulator) inside this app.\n\nServer: %@\nState: %@\nStartup: %.1fs · restarts: %lu",
                         version, h.baseURL.absoluteString ?: @"–", DSHHarnessStateName(h.state), h.lastStartupDuration, (unsigned long) h.restartCount];
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"About DSH" message:message preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];
    [self presentViewController:alert animated:YES completion:nil];
}

#pragma mark - Keyboard shortcuts

- (NSArray<UIKeyCommand *> *)keyCommands {
    UIKeyCommand *reload = [UIKeyCommand keyCommandWithInput:@"r" modifierFlags:UIKeyModifierCommand action:@selector(reloadWebView)];
    reload.discoverabilityTitle = @"Reload";
    UIKeyCommand *terminal = [UIKeyCommand keyCommandWithInput:@"t" modifierFlags:UIKeyModifierCommand | UIKeyModifierShift action:@selector(presentTerminal)];
    terminal.discoverabilityTitle = @"Terminal";
    return @[reload, terminal];
}

- (BOOL)canBecomeFirstResponder {
    return YES;
}

#pragma mark - WKNavigationDelegate

- (BOOL)isHarnessURL:(NSURL *)url {
    NSURL *base = DSHHarness.shared.baseURL;
    return base != nil && [url.host isEqualToString:base.host] && [url.port isEqual:base.port ?: @80];
}

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)action decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
    NSURL *url = action.request.URL;
    if (url == nil || [self isHarnessURL:url] || [url.scheme isEqualToString:@"about"] || [url.scheme isEqualToString:@"blob"] || [url.scheme isEqualToString:@"data"]) {
        decisionHandler(WKNavigationActionPolicyAllow);
        return;
    }
    // Anything leaving the local server (docs links, OAuth pages) opens in Safari.
    if ([url.scheme hasPrefix:@"http"] || [url.scheme isEqualToString:@"mailto"]) {
        [UIApplication.sharedApplication openURL:url options:@{} completionHandler:nil];
        decisionHandler(WKNavigationActionPolicyCancel);
        return;
    }
    decisionHandler(WKNavigationActionPolicyAllow);
}

- (void)webView:(WKWebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)response decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler {
    if (!response.canShowMIMEType) {
        decisionHandler(WKNavigationResponsePolicyDownload);
        return;
    }
    if ([response.response isKindOfClass:NSHTTPURLResponse.class]) {
        NSString *disposition = ((NSHTTPURLResponse *) response.response).allHeaderFields[@"Content-Disposition"];
        if ([disposition.lowercaseString hasPrefix:@"attachment"]) {
            decisionHandler(WKNavigationResponsePolicyDownload);
            return;
        }
    }
    decisionHandler(WKNavigationResponsePolicyAllow);
}

- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation {
    self.pageLoaded = YES;
    [self.overlay hide];
}

- (void)webView:(WKWebView *)webView didFailProvisionalNavigation:(WKNavigation *)navigation withError:(NSError *)error {
    [self handleLoadError:error];
}

- (void)webView:(WKWebView *)webView didFailNavigation:(WKNavigation *)navigation withError:(NSError *)error {
    [self handleLoadError:error];
}

- (void)handleLoadError:(NSError *)error {
    if (error.code == NSURLErrorCancelled)
        return;
    self.pageLoaded = NO;
    [DSHHarness.shared.log append:[NSString stringWithFormat:@"[dsh-ios] page load failed: %@", error.localizedDescription]];
    [self.overlay showStarting:@"Waiting for the harness…"];
    // The server was answering a moment ago; give it a beat and retry, and
    // let the harness restart it if it is really gone.
    __weak typeof(self) weakSelf = self;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t) (1.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        typeof(self) self = weakSelf;
        if (self == nil || self.pageLoaded)
            return;
        [DSHHarness.shared verifyAliveWithCompletion:^(BOOL alive) {
            if (alive) [self loadHarness];
        }];
    });
}

- (void)webViewWebContentProcessDidTerminate:(WKWebView *)webView {
    [DSHHarness.shared.log append:@"[dsh-ios] web content process terminated; reloading"];
    self.pageLoaded = NO;
    [self loadHarness];
}

- (void)webView:(WKWebView *)webView navigationResponse:(WKNavigationResponse *)navigationResponse didBecomeDownload:(WKDownload *)download {
    download.delegate = self;
}

- (void)webView:(WKWebView *)webView navigationAction:(WKNavigationAction *)navigationAction didBecomeDownload:(WKDownload *)download {
    download.delegate = self;
}

#pragma mark - WKDownloadDelegate

- (void)download:(WKDownload *)download decideDestinationUsingResponse:(NSURLResponse *)response suggestedFilename:(NSString *)suggestedFilename completionHandler:(void (^)(NSURL * _Nullable))completionHandler {
    NSURL *docs = [NSFileManager.defaultManager URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask].firstObject;
    NSURL *dir = [docs URLByAppendingPathComponent:@"Downloads" isDirectory:YES];
    [NSFileManager.defaultManager createDirectoryAtURL:dir withIntermediateDirectories:YES attributes:nil error:nil];
    NSString *name = suggestedFilename.length ? suggestedFilename : @"download";
    NSURL *dest = [dir URLByAppendingPathComponent:name];
    NSUInteger n = 1;
    while ([NSFileManager.defaultManager fileExistsAtPath:dest.path]) {
        NSString *stem = name.stringByDeletingPathExtension, *ext = name.pathExtension;
        NSString *alt = ext.length ? [NSString stringWithFormat:@"%@-%lu.%@", stem, (unsigned long) n++, ext] : [NSString stringWithFormat:@"%@-%lu", stem, (unsigned long) n++];
        dest = [dir URLByAppendingPathComponent:alt];
    }
    self.downloadDestinations[[NSValue valueWithNonretainedObject:download]] = dest;
    completionHandler(dest);
}

- (void)downloadDidFinish:(WKDownload *)download {
    NSValue *key = [NSValue valueWithNonretainedObject:download];
    NSURL *dest = self.downloadDestinations[key];
    [self.downloadDestinations removeObjectForKey:key];
    if (dest == nil)
        return;
    UIActivityViewController *share = [[UIActivityViewController alloc] initWithActivityItems:@[dest] applicationActivities:nil];
    share.popoverPresentationController.sourceView = self.menuButton;
    [self presentViewController:share animated:YES completion:nil];
}

- (void)download:(WKDownload *)download didFailWithError:(NSError *)error resumeData:(NSData *)resumeData {
    [self.downloadDestinations removeObjectForKey:[NSValue valueWithNonretainedObject:download]];
    [DSHHarness.shared.log append:[NSString stringWithFormat:@"[dsh-ios] download failed: %@", error.localizedDescription]];
}

#pragma mark - WKUIDelegate

- (WKWebView *)webView:(WKWebView *)webView createWebViewWithConfiguration:(WKWebViewConfiguration *)configuration forNavigationAction:(WKNavigationAction *)navigationAction windowFeatures:(WKWindowFeatures *)windowFeatures {
    // target=_blank: keep local URLs in place, hand external ones to Safari.
    NSURL *url = navigationAction.request.URL;
    if (url == nil)
        return nil;
    if ([self isHarnessURL:url])
        [webView loadRequest:navigationAction.request];
    else
        [UIApplication.sharedApplication openURL:url options:@{} completionHandler:nil];
    return nil;
}

- (void)webView:(WKWebView *)webView runJavaScriptAlertPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(void))completionHandler {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction *a) { completionHandler(); }]];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)webView:(WKWebView *)webView runJavaScriptConfirmPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(BOOL))completionHandler {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction *a) { completionHandler(NO); }]];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction *a) { completionHandler(YES); }]];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)webView:(WKWebView *)webView runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(NSString *)defaultText initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(NSString * _Nullable))completionHandler {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:nil message:prompt preferredStyle:UIAlertControllerStyleAlert];
    [alert addTextFieldWithConfigurationHandler:^(UITextField *tf) { tf.text = defaultText; }];
    [alert addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction *a) { completionHandler(nil); }]];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction *a) { completionHandler(alert.textFields.firstObject.text); }]];
    [self presentViewController:alert animated:YES completion:nil];
}

#pragma mark - Status bar

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleDefault;
}

@end
