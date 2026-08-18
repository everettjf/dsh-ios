//
//  DSHStatusOverlayView.m
//  DSH
//

#import "DSHStatusOverlayView.h"

@interface DSHStatusOverlayView ()
@property (nonatomic) UILabel *titleLabel;
@property (nonatomic) UILabel *subtitleLabel;
@property (nonatomic) UILabel *messageLabel;
@property (nonatomic) UILabel *elapsedLabel;
@property (nonatomic) UIActivityIndicatorView *spinner;
@property (nonatomic) UITextView *logView;
@property (nonatomic) UIButton *retryButton;
@property (nonatomic) UIButton *terminalButton;
@property (nonatomic) UIButton *logButton;
@property (nonatomic) UIStackView *buttons;
@property (nonatomic, nullable) NSDate *startedAt;
@property (nonatomic, nullable) NSTimer *timer;
@property (nonatomic, readwrite, getter=isShowingFailure) BOOL showingFailure;
@end

@implementation DSHStatusOverlayView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        self.backgroundColor = [UIColor colorNamed:@"DSHBackground"] ?: UIColor.systemBackgroundColor;
        self.accessibilityIdentifier = @"dsh.overlay";

        UILabel *title = [UILabel new];
        title.text = @"DSH";
        title.font = [UIFont monospacedSystemFontOfSize:40 weight:UIFontWeightBold];
        title.textColor = UIColor.labelColor;
        title.textAlignment = NSTextAlignmentCenter;
        self.titleLabel = title;

        UILabel *subtitle = [UILabel new];
        subtitle.text = @"DeepSeek Harness · on-device Linux guest";
        subtitle.font = [UIFont systemFontOfSize:14 weight:UIFontWeightRegular];
        subtitle.textColor = UIColor.secondaryLabelColor;
        subtitle.textAlignment = NSTextAlignmentCenter;
        self.subtitleLabel = subtitle;

        UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
        spinner.hidesWhenStopped = YES;
        self.spinner = spinner;

        UILabel *message = [UILabel new];
        message.font = [UIFont systemFontOfSize:15 weight:UIFontWeightMedium];
        message.textColor = UIColor.labelColor;
        message.textAlignment = NSTextAlignmentCenter;
        message.numberOfLines = 0;
        message.accessibilityIdentifier = @"dsh.overlay.message";
        self.messageLabel = message;

        UILabel *elapsed = [UILabel new];
        elapsed.font = [UIFont monospacedDigitSystemFontOfSize:12 weight:UIFontWeightRegular];
        elapsed.textColor = UIColor.tertiaryLabelColor;
        elapsed.textAlignment = NSTextAlignmentCenter;
        elapsed.accessibilityIdentifier = @"dsh.overlay.elapsed";
        self.elapsedLabel = elapsed;

        UITextView *log = [UITextView new];
        log.editable = NO;
        log.selectable = YES;
        log.font = [UIFont monospacedSystemFontOfSize:11 weight:UIFontWeightRegular];
        log.textColor = UIColor.secondaryLabelColor;
        log.backgroundColor = [UIColor.secondarySystemBackgroundColor colorWithAlphaComponent:0.6];
        log.layer.cornerRadius = 8;
        log.textContainerInset = UIEdgeInsetsMake(8, 8, 8, 8);
        log.accessibilityIdentifier = @"dsh.overlay.log";
        self.logView = log;

        self.retryButton = [self buttonWithTitle:@"Retry" symbol:@"arrow.clockwise" action:@selector(retryTapped) prominent:YES];
        self.retryButton.accessibilityIdentifier = @"dsh.overlay.retry";
        self.terminalButton = [self buttonWithTitle:@"Terminal" symbol:@"terminal" action:@selector(terminalTapped) prominent:NO];
        self.logButton = [self buttonWithTitle:@"Full log" symbol:@"doc.text" action:@selector(logTapped) prominent:NO];

        UIStackView *buttons = [[UIStackView alloc] initWithArrangedSubviews:@[self.retryButton, self.terminalButton, self.logButton]];
        buttons.axis = UILayoutConstraintAxisHorizontal;
        buttons.spacing = 12;
        buttons.alignment = UIStackViewAlignmentCenter;
        self.buttons = buttons;

        UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[title, subtitle, spinner, message, elapsed, buttons, log]];
        stack.axis = UILayoutConstraintAxisVertical;
        stack.alignment = UIStackViewAlignmentCenter;
        stack.spacing = 10;
        [stack setCustomSpacing:2 afterView:title];
        [stack setCustomSpacing:28 afterView:subtitle];
        [stack setCustomSpacing:18 afterView:elapsed];
        stack.translatesAutoresizingMaskIntoConstraints = NO;
        [self addSubview:stack];

        [NSLayoutConstraint activateConstraints:@[
            [stack.centerXAnchor constraintEqualToAnchor:self.centerXAnchor],
            [stack.centerYAnchor constraintEqualToAnchor:self.centerYAnchor constant:-30],
            [stack.widthAnchor constraintLessThanOrEqualToAnchor:self.widthAnchor constant:-48],
            [stack.widthAnchor constraintLessThanOrEqualToConstant:560],
            [message.widthAnchor constraintEqualToAnchor:stack.widthAnchor],
            [log.widthAnchor constraintEqualToAnchor:stack.widthAnchor],
            [log.heightAnchor constraintEqualToConstant:170],
            [stack.widthAnchor constraintGreaterThanOrEqualToConstant:280],
        ]];
    }
    return self;
}

- (UIButton *)buttonWithTitle:(NSString *)title symbol:(NSString *)symbol action:(SEL)action prominent:(BOOL)prominent {
    UIButtonConfiguration *conf = prominent ? [UIButtonConfiguration filledButtonConfiguration] : [UIButtonConfiguration grayButtonConfiguration];
    conf.title = title;
    conf.image = [UIImage systemImageNamed:symbol];
    conf.imagePadding = 6;
    conf.cornerStyle = UIButtonConfigurationCornerStyleMedium;
    UIButton *b = [UIButton buttonWithConfiguration:conf primaryAction:nil];
    [b addTarget:self action:action forControlEvents:UIControlEventTouchUpInside];
    return b;
}

- (void)retryTapped { if (self.retryHandler) self.retryHandler(); }
- (void)terminalTapped { if (self.terminalHandler) self.terminalHandler(); }
- (void)logTapped { if (self.logHandler) self.logHandler(); }

- (void)showStarting:(NSString *)message {
    self.hidden = NO;
    self.showingFailure = NO;
    self.messageLabel.text = message;
    self.messageLabel.textColor = UIColor.labelColor;
    [self.spinner startAnimating];
    self.retryButton.hidden = YES;
    self.terminalButton.hidden = NO;
    self.logButton.hidden = NO;
    if (self.startedAt == nil) {
        self.startedAt = NSDate.date;
        [self.timer invalidate];
        __weak typeof(self) weakSelf = self;
        self.timer = [NSTimer scheduledTimerWithTimeInterval:1 repeats:YES block:^(NSTimer *t) { [weakSelf tick]; }];
        [self tick];
    }
}

- (void)showFailure:(NSString *)message {
    self.hidden = NO;
    self.showingFailure = YES;
    [self stopTimer];
    self.messageLabel.text = message;
    self.messageLabel.textColor = UIColor.systemRedColor;
    [self.spinner stopAnimating];
    self.retryButton.hidden = NO;
    self.terminalButton.hidden = NO;
    self.logButton.hidden = NO;
    self.elapsedLabel.text = @"";
}

- (void)hide {
    if (self.hidden)
        return;
    [self stopTimer];
    self.showingFailure = NO;
    [UIView animateWithDuration:0.25 animations:^{ self.alpha = 0; } completion:^(BOOL finished) {
        self.hidden = YES;
        self.alpha = 1;
    }];
}

- (void)setLogText:(NSString *)text {
    self.logView.text = text;
    if (text.length)
        [self.logView scrollRangeToVisible:NSMakeRange(text.length - 1, 1)];
}

- (void)tick {
    if (self.startedAt == nil)
        return;
    NSTimeInterval t = -self.startedAt.timeIntervalSinceNow;
    self.elapsedLabel.text = [NSString stringWithFormat:@"%.0f s · first start takes about half a minute", t];
}

- (void)stopTimer {
    [self.timer invalidate];
    self.timer = nil;
    self.startedAt = nil;
}

@end
