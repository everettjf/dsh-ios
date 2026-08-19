//
//  DSHCapabilitiesViewController.m
//  DSH
//

#import "DSHCapabilitiesViewController.h"
#import "DSHCapability.h"
#import "DSHHostBridge.h"

@interface DSHCapabilitiesViewController ()
@property (nonatomic, copy) NSArray<DSHCapability *> *capabilities;
@end

@implementation DSHCapabilitiesViewController

- (instancetype)init {
    if (self = [super initWithStyle:UITableViewStyleInsetGrouped])
        self.title = @"Capabilities";
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.tableView.accessibilityIdentifier = @"dsh.capabilities";
    self.navigationItem.rightBarButtonItem =
        [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(done)];
    [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(reload)
                                               name:DSHCapabilityRegistryDidChangeNotification object:nil];
    // A system permission can be changed in Settings while we are in the
    // background, so the states are re-read every time the app comes back.
    [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(reload)
                                               name:UIApplicationDidBecomeActiveNotification object:nil];
    [self reload];
}

- (void)dealloc {
    [NSNotificationCenter.defaultCenter removeObserver:self];
}

- (void)reload {
    self.capabilities = DSHCapabilityRegistry.shared.capabilities;
    [self.tableView reloadData];
}

- (void)done {
    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark Table

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    // Capabilities register when the guest finishes booting, so the list can
    // legitimately be empty for the first few seconds after launch.
    return section == 0 ? MAX(1, (NSInteger) self.capabilities.count) : 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return section == 0 ? @"Device access" : @"Bridge";
}

- (NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section {
    if (section == 0)
        return @"Anything switched on here can be read by the agent running in DSH — including by a model answering over the network. "
                "Switches take effect immediately, including in the middle of a turn. Items marked “needs iOS permission” also have to be "
                "allowed in the system dialog, and can be revoked in Settings ▸ Privacy.";
    return @"The bridge listens on this device only (127.0.0.1) and requires a token that changes every launch, so other apps cannot reach it.";
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:nil];
    cell.detailTextLabel.numberOfLines = 0;
    cell.detailTextLabel.textColor = UIColor.secondaryLabelColor;

    if (indexPath.section == 1) {
        DSHHostBridge *bridge = DSHHostBridge.shared;
        cell.textLabel.text = bridge.isRunning ? @"Running" : @"Not running";
        cell.detailTextLabel.text = bridge.isRunning
            ? [NSString stringWithFormat:@"%@ · %lu requests served", bridge.baseURLString, (unsigned long) bridge.requestCount]
            : @"The guest cannot reach any device capability.";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.accessibilityIdentifier = @"dsh.capability.bridge";
        return cell;
    }

    if (self.capabilities.count == 0) {
        cell.textLabel.text = @"Still starting…";
        cell.detailTextLabel.text = @"Capabilities appear once the guest has booted.";
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        cell.accessibilityIdentifier = @"dsh.capability.empty";
        return cell;
    }

    DSHCapability *capability = self.capabilities[indexPath.row];
    DSHCapabilityState state = [DSHCapabilityRegistry.shared stateForIdentifier:capability.identifier];
    cell.textLabel.text = capability.title;
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.accessibilityIdentifier = [NSString stringWithFormat:@"dsh.capability.%@", capability.identifier];

    NSMutableString *detail = [capability.details mutableCopy];
    if (!capability.available)
        [detail appendString:@"\nNot available on this device."];
    else if (capability.gate == DSHCapabilityGateSystemPermission)
        [detail appendString:@"\nAlso needs iOS permission."];
    else if (capability.gate == DSHCapabilityGatePerCall)
        [detail appendString:@"\nAsks you before every call."];
    cell.detailTextLabel.text = detail;

    UISwitch *toggle = [UISwitch new];
    toggle.on = state != DSHCapabilityStateDisabled && state != DSHCapabilityStateUnavailable;
    toggle.enabled = capability.available;
    toggle.tag = indexPath.row;
    toggle.accessibilityIdentifier = [NSString stringWithFormat:@"dsh.capability.switch.%@", capability.identifier];
    [toggle addTarget:self action:@selector(toggled:) forControlEvents:UIControlEventValueChanged];
    cell.accessoryView = toggle;
    return cell;
}

- (void)toggled:(UISwitch *)toggle {
    if (toggle.tag < 0 || (NSUInteger) toggle.tag >= self.capabilities.count)
        return;
    DSHCapability *capability = self.capabilities[toggle.tag];
    if (!toggle.isOn) {
        [DSHCapabilityRegistry.shared setEnabled:NO forIdentifier:capability.identifier];
        return;
    }
    // Turning something on is the consequential direction, so it is the one
    // that gets a confirmation naming what is being handed over.
    UIAlertController *alert = [UIAlertController
        alertControllerWithTitle:capability.title
                         message:[NSString stringWithFormat:
                                  @"%@\n\nThe agent will be able to read this whenever it decides to, including when a remote model asks it to.",
                                  capability.details]
                  preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
        toggle.on = NO;
    }]];
    [alert addAction:[UIAlertAction actionWithTitle:@"Allow" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        [DSHCapabilityRegistry.shared setEnabled:YES forIdentifier:capability.identifier];
    }]];
    [self presentViewController:alert animated:YES completion:nil];
}

@end
