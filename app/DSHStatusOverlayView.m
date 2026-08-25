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
@property (nonatomic, nullable) NSDate *progressStartedAt;
@property (nonatomic) NSTimeInterval expected;
@property (nonatomic) UIProgressView *progress;
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
        [message.heightAnchor constraintGreaterThanOrEqualToConstant:40].active = YES;
        self.messageLabel = message;

        UIProgressView *progress = [[UIProgressView alloc] initWithProgressViewStyle:UIProgressViewStyleDefault];
        progress.trackTintColor = [UIColor.secondaryLabelColor colorWithAlphaComponent:0.25];
        progress.progressTintColor = [UIColor colorNamed:@"DSHAccent"] ?: UIColor.systemBlueColor;
        progress.layer.cornerRadius = 2;
        progress.clipsToBounds = YES;
        progress.accessibilityIdentifier = @"dsh.overlay.progress";
        self.progress = progress;

        UILabel *elapsed = [UILabel new];
        elapsed.font = [UIFont monospacedDigitSystemFontOfSize:12 weight:UIFontWeightRegular];
        elapsed.textColor = UIColor.tertiaryLabelColor;
        elapsed.textAlignment = NSTextAlignmentCenter;
        elapsed.accessibilityIdentifier = @"dsh.overlay.elapsed";
        [elapsed.heightAnchor constraintEqualToConstant:16].active = YES;
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

        UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[title, subtitle, spinner, message, progress, elapsed, buttons, log]];
        stack.axis = UILayoutConstraintAxisVertical;
        stack.alignment = UIStackViewAlignmentCenter;
        stack.spacing = 10;
        [stack setCustomSpacing:2 afterView:title];
        [stack setCustomSpacing:28 afterView:subtitle];
        [stack setCustomSpacing:18 afterView:elapsed];
        stack.translatesAutoresizingMaskIntoConstraints = NO;
        [self addSubview:stack];

        NSLayoutConstraint *stableWidth = [stack.widthAnchor constraintEqualToAnchor:self.widthAnchor constant:-48];
        // Prefer a fixed container width so changing status/elapsed strings do
        // not resize and recenter the entire launch screen. On iPad the
        // required 560 pt ceiling wins over this preferred width.
        stableWidth.priority = UILayoutPriorityDefaultHigh;
        [NSLayoutConstraint activateConstraints:@[
            [stack.centerXAnchor constraintEqualToAnchor:self.centerXAnchor],
            [stack.centerYAnchor constraintEqualToAnchor:self.centerYAnchor constant:-30],
            stableWidth,
            [stack.widthAnchor constraintLessThanOrEqualToConstant:560],
            [message.widthAnchor constraintEqualToAnchor:stack.widthAnchor],
            [progress.widthAnchor constraintEqualToAnchor:stack.widthAnchor constant:-40],
            [progress.heightAnchor constraintEqualToConstant:4],
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
    [self.layer removeAllAnimations];
    self.alpha = 1;
    self.hidden = NO;
    self.showingFailure = NO;
    self.messageLabel.text = message;
    self.messageLabel.textColor = UIColor.labelColor;
    [self.spinner startAnimating];
    self.progress.hidden = NO;
    self.progress.alpha = 0;
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

- (void)setDeterminateProgress:(double)fraction detail:(NSString *)detail {
    self.progressStartedAt = nil;
    self.expected = 0;
    self.progress.hidden = NO;
    self.progress.alpha = fraction < 0 ? 0 : 1;
    if (fraction >= 0)
        [self.progress setProgress:(float) MIN(fraction, 1.0) animated:YES];
    self.elapsedLabel.text = detail ?: @"";
}

- (void)setProgressStartedAt:(NSDate *)startedAt expected:(NSTimeInterval)expected {
    self.progressStartedAt = startedAt;
    self.expected = expected;
    self.progress.hidden = NO;
    self.progress.alpha = startedAt == nil ? 0 : 1;
    [self tick];
}

- (void)showFailure:(NSString *)message {
    [self.layer removeAllAnimations];
    self.alpha = 1;
    self.hidden = NO;
    self.showingFailure = YES;
    self.progress.hidden = YES;
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
    if (self.progressStartedAt == nil || self.expected <= 0) {
        self.elapsedLabel.text = [NSString stringWithFormat:@"%.0f s", t];
        return;
    }
    NSTimeInterval done = -self.progressStartedAt.timeIntervalSinceNow;
    NSTimeInterval left = self.expected - done;
    // Asymptotic fill: never reaches 100% until the server really answers.
    float fraction = done < self.expected ? (float) (done / self.expected) * 0.9f
                                          : 0.9f + 0.1f * (float) (1 - exp(-(done - self.expected) / 15.0));
    [self.progress setProgress:fraction animated:YES];
    if (left > 0.5)
        self.elapsedLabel.text = [NSString stringWithFormat:@"%.0f s elapsed · about %.0f s left", done, left];
    else
        self.elapsedLabel.text = [NSString stringWithFormat:@"%.0f s elapsed · almost there (this device usually takes ~%.0f s)", done, self.expected];
}

- (void)stopTimer {
    [self.timer invalidate];
    self.timer = nil;
    self.startedAt = nil;
    self.progressStartedAt = nil;
    [self.progress setProgress:0 animated:NO];
}

@end
