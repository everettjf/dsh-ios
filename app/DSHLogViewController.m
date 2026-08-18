//
//  DSHLogViewController.m
//  DSH
//

#import "DSHLogViewController.h"

@interface DSHLogViewController ()
@property (nonatomic) DSHLogBuffer *log;
@property (nonatomic) UITextView *textView;
@end

@implementation DSHLogViewController

- (instancetype)initWithLog:(DSHLogBuffer *)log {
    if (self = [super initWithNibName:nil bundle:nil]) {
        _log = log;
        self.title = @"Server Log";
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.systemBackgroundColor;
    UITextView *tv = [UITextView new];
    tv.editable = NO;
    tv.font = [UIFont monospacedSystemFontOfSize:11 weight:UIFontWeightRegular];
    tv.textColor = UIColor.labelColor;
    tv.backgroundColor = UIColor.systemBackgroundColor;
    tv.textContainerInset = UIEdgeInsetsMake(12, 12, 12, 12);
    tv.alwaysBounceVertical = YES;
    tv.accessibilityIdentifier = @"dsh.logview";
    tv.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:tv];
    self.textView = tv;
    [NSLayoutConstraint activateConstraints:@[
        [tv.topAnchor constraintEqualToAnchor:self.view.topAnchor],
        [tv.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [tv.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [tv.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
    ]];

    self.navigationItem.rightBarButtonItems = @[
        [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(done)],
        [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemAction target:self action:@selector(share:)],
    ];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Clear" style:UIBarButtonItemStylePlain target:self action:@selector(clear)];

    [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(refresh) name:DSHLogBufferDidChangeNotification object:self.log];
    [self refresh];
}

- (void)dealloc {
    [NSNotificationCenter.defaultCenter removeObserver:self];
}

- (void)refresh {
    NSString *text = [self.log.lines componentsJoinedByString:@"\n"];
    BOOL atBottom = self.textView.contentOffset.y >= self.textView.contentSize.height - self.textView.bounds.size.height - 40;
    self.textView.text = text;
    if (atBottom && text.length)
        [self.textView scrollRangeToVisible:NSMakeRange(text.length - 1, 1)];
}

- (void)done {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)clear {
    [self.log clear];
}

- (void)share:(UIBarButtonItem *)sender {
    UIActivityViewController *vc = [[UIActivityViewController alloc] initWithActivityItems:@[self.textView.text ?: @""] applicationActivities:nil];
    vc.popoverPresentationController.barButtonItem = sender;
    [self presentViewController:vc animated:YES completion:nil];
}

@end
