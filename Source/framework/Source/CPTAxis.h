#import "CPTDefinitions.h"
#import "CPTLayer.h"
#import "CPTTextStyle.h"

/// @file

@class CPTAxis;
@class CPTAxisLabel;
@class CPTAxisSet;
@class CPTAxisTitle;
@class CPTGridLines;
@class CPTLimitBand;
@class CPTLineCap;
@class CPTLineStyle;
@class CPTPlotSpace;
@class CPTPlotRange;
@class CPTPlotArea;
@class CPTShadow;

/**
 *  @brief Enumeration of labeling policies
 **/
typedef enum _CPTAxisLabelingPolicy {
    CPTAxisLabelingPolicyNone,              ///< No labels provided; user sets labels and tick locations.
    CPTAxisLabelingPolicyLocationsProvided, ///< User sets tick locations; axis makes labels.
    CPTAxisLabelingPolicyFixedInterval,     ///< Fixed interval labeling policy.
    CPTAxisLabelingPolicyAutomatic,         ///< Automatic labeling policy.
    CPTAxisLabelingPolicyEqualDivisions     ///< Divide the plot range into equal parts.
}
CPTAxisLabelingPolicy;

#pragma mark -

/**
 *  @brief Axis labeling delegate.
 **/
@protocol CPTAxisDelegate<NSObject>

@optional

/// @name Labels
/// @{

/** @brief @optional Determines if the axis should relabel itself now.
 *  @param axis The axis.
 *  @return @YES if the axis should relabel now.
 **/
-(BOOL)axisShouldRelabel:(CPTAxis *)axis;

/** @brief @optional The method is called after the axis is relabeled to allow the delegate to perform any
 *  necessary cleanup or further labeling actions.
 *  @param axis The axis.
 **/
-(void)axisDidRelabel:(CPTAxis *)axis;

/** @brief @optional This method gives the delegate a chance to create custom labels for each tick.
 *  It can be used with any labeling policy. Returning @NO will cause the axis not
 *  to update the labels. It is then the delegate&rsquo;s responsibility to do this.
 *  @param axis The axis.
 *  @param locations The locations of the major ticks.
 *  @return @YES if the axis class should proceed with automatic labeling.
 **/
-(BOOL)axis:(CPTAxis *)axis shouldUpdateAxisLabelsAtLocations:(NSSet *)locations;

/** @brief @optional This method gives the delegate a chance to create custom labels for each minor tick.
 *  It can be used with any labeling policy. Returning @NO will cause the axis not
 *  to update the labels. It is then the delegate&rsquo;s responsibility to do this.
 *  @param axis The axis.
 *  @param locations The locations of the minor ticks.
 *  @return @YES if the axis class should proceed with automatic labeling.
 **/
-(BOOL)axis:(CPTAxis *)axis shouldUpdateMinorAxisLabelsAtLocations:(NSSet *)locations;

/// @}

/// @name Label Selection
/// @{

/** @brief @optional Informs the delegate that an axis label was
 *  @if MacOnly clicked. @endif
 *  @if iOSOnly touched. @endif
 *  @param axis The axis.
 *  @param label The selected axis label.
 **/
-(void)axis:(CPTAxis *)axis labelWasSelected:(CPTAxisLabel *)label;

/** @brief @optional Informs the delegate that an axis label was
 *  @if MacOnly clicked. @endif
 *  @if iOSOnly touched. @endif
 *  @param axis The axis.
 *  @param label The selected axis label.
 *  @param event The event that triggered the selection.
 **/
-(void)axis:(CPTAxis *)axis labelWasSelected:(CPTAxisLabel *)label withEvent:(CPTNativeEvent *)event;

/** @brief @optional Informs the delegate that a minor tick axis label was
 *  @if MacOnly clicked. @endif
 *  @if iOSOnly touched. @endif
 *  @param axis The axis.
 *  @param label The selected minor tick axis label.
 **/
-(void)axis:(CPTAxis *)axis minorTickLabelWasSelected:(CPTAxisLabel *)label;

/** @brief @optional Informs the delegate that a minor tick axis label was
 *  @if MacOnly clicked. @endif
 *  @if iOSOnly touched. @endif
 *  @param axis The axis.
 *  @param label The selected minor tick axis label.
 *  @param event The event that triggered the selection.
 **/
-(void)axis:(CPTAxis *)axis minorTickLabelWasSelected:(CPTAxisLabel *)label withEvent:(CPTNativeEvent *)event;

/// @}

@end

#pragma mark -

@interface CPTAxis : CPTLayer {
    @private
    CPTCoordinate coordinate;
    CPTPlotSpace *plotSpace;
    NSSet *majorTickLocations;
    NSSet *minorTickLocations;
    CGFloat majorTickLength;
    CGFloat minorTickLength;
    CGFloat labelOffset;
    CGFloat minorTickLabelOffset;
    CGFloat labelRotation;
    CGFloat minorTickLabelRotation;
    CPTAlignment labelAlignment;
    CPTAlignment minorTickLabelAlignment;
    CPTLineStyle *axisLineStyle;
    CPTLineStyle *zeroAxisXLineStyle;
    CPTLineStyle *majorTickLineStyle;
    CPTLineStyle *minorTickLineStyle;
    CPTLineStyle *majorGridLineStyle;
    CPTLineStyle *minorGridLineStyle;
    CPTLineCap *axisLineCapMin;
    CPTLineCap *axisLineCapMax;
    NSDecimal labelingOrigin;
    NSDecimal majorIntervalLength;
    NSUInteger minorTicksPerInterval;
    NSUInteger preferredNumberOfMajorTicks;
    CPTAxisLabelingPolicy labelingPolicy;
    CPTTextStyle *labelTextStyle;
    CPTTextStyle *minorTickLabelTextStyle;
    CPTSign tickLabelDirection;
    CPTSign minorTickLabelDirection;
    CPTTextStyle *titleTextStyle;
    NSFormatter *labelFormatter;
    NSFormatter *minorTickLabelFormatter;
    BOOL labelFormatterChanged;
    BOOL minorLabelFormatterChanged;
    NSSet *axisLabels;
    NSSet *minorTickAxisLabels;
    CPTAxisTitle *axisTitle;
    NSString *title;
    NSAttributedString *attributedTitle;
    CGFloat titleOffset;
    CGFloat titleRotation;
    NSDecimal titleLocation;
    CPTSign tickDirection;
    BOOL needsRelabel;
    NSArray *labelExclusionRanges;
    CPTPlotRange *visibleRange;
    CPTPlotRange *visibleAxisRange;
    CPTPlotRange *gridLinesRange;
    NSArray *alternatingBandFills;
    NSMutableArray *mutableBackgroundLimitBands;
    BOOL separateLayers;
    CPTShadow *labelShadow;
    CPTShadow *minorTickLabelShadow;
    __cpt_weak CPTPlotArea *plotArea;
    __cpt_weak CPTGridLines *minorGridLines;
    __cpt_weak CPTGridLines *majorGridLines;
}

/// @name Axis
/// @{
@property (nonatomic, readwrite, copy) CPTLineStyle *axisLineStyle;
@property (nonatomic, readwrite, copy) CPTLineStyle *zeroAxisXLineStyle;
@property (nonatomic, readwrite, assign) CPTCoordinate coordinate;
@property (nonatomic, readwrite, assign) NSDecimal labelingOrigin;
@property (nonatomic, readwrite, assign) CPTSign tickDirection;
@property (nonatomic, readwrite, copy) CPTPlotRange *visibleRange;
@property (nonatomic, readwrite, copy) CPTPlotRange *visibleAxisRange;
@property (nonatomic, readwrite, copy) CPTLineCap *axisLineCapMin;
@property (nonatomic, readwrite, copy) CPTLineCap *axisLineCapMax;
/// @}

/// @name Title
/// @{
@property (nonatomic, readwrite, copy) CPTTextStyle *titleTextStyle;
@property (nonatomic, readwrite, retain) CPTAxisTitle *axisTitle;
@property (nonatomic, readwrite, assign) CGFloat titleOffset;
@property (nonatomic, readwrite, copy) NSString *title;
@property (nonatomic, readwrite, copy) NSAttributedString *attributedTitle;
@property (nonatomic, readwrite, assign) CGFloat titleRotation;
@property (nonatomic, readwrite, assign) NSDecimal titleLocation;
@property (nonatomic, readonly, assign) NSDecimal defaultTitleLocation;
/// @}

/// @name Labels
/// @{
@property (nonatomic, readwrite, assign) CPTAxisLabelingPolicy labelingPolicy;
@property (nonatomic, readwrite, assign) CGFloat labelOffset;
@property (nonatomic, readwrite, assign) CGFloat minorTickLabelOffset;
@property (nonatomic, readwrite, assign) CGFloat labelRotation;
@property (nonatomic, readwrite, assign) CGFloat minorTickLabelRotation;
@property (nonatomic, readwrite, assign) CPTAlignment labelAlignment;
@property (nonatomic, readwrite, assign) CPTAlignment minorTickLabelAlignment;
@property (nonatomic, readwrite, copy) CPTTextStyle *labelTextStyle;
@property (nonatomic, readwrite, copy) CPTTextStyle *minorTickLabelTextStyle;
@property (nonatomic, readwrite, assign) CPTSign tickLabelDirection;
@property (nonatomic, readwrite, assign) CPTSign minorTickLabelDirection;
@property (nonatomic, readwrite, retain) NSFormatter *labelFormatter;
@property (nonatomic, readwrite, retain) NSFormatter *minorTickLabelFormatter;
@property (nonatomic, readwrite, retain) NSSet *axisLabels;
@property (nonatomic, readwrite, retain) NSSet *minorTickAxisLabels;
@property (nonatomic, readonly, assign) BOOL needsRelabel;
@property (nonatomic, readwrite, retain) NSArray *labelExclusionRanges;
@property (nonatomic, readwrite, retain) CPTShadow *labelShadow;
@property (nonatomic, readwrite, retain) CPTShadow *minorTickLabelShadow;
/// @}

/// @name Major Ticks
/// @{
@property (nonatomic, readwrite, assign) NSDecimal majorIntervalLength;
@property (nonatomic, readwrite, assign) CGFloat majorTickLength;
@property (nonatomic, readwrite, copy) CPTLineStyle *majorTickLineStyle;
@property (nonatomic, readwrite, retain) NSSet *majorTickLocations;
@property (nonatomic, readwrite, assign) NSUInteger preferredNumberOfMajorTicks;
/// @}

/// @name Minor Ticks
/// @{
@property (nonatomic, readwrite, assign) NSUInteger minorTicksPerInterval;
@property (nonatomic, readwrite, assign) CGFloat minorTickLength;
@property (nonatomic, readwrite, copy) CPTLineStyle *minorTickLineStyle;
@property (nonatomic, readwrite, retain) NSSet *minorTickLocations;
/// @}

/// @name Grid Lines
/// @{
@property (nonatomic, readwrite, copy) CPTLineStyle *majorGridLineStyle;
@property (nonatomic, readwrite, copy) CPTLineStyle *minorGridLineStyle;
@property (nonatomic, readwrite, copy) CPTPlotRange *gridLinesRange;
/// @}

/// @name Background Bands
/// @{
@property (nonatomic, readwrite, copy) NSArray *alternatingBandFills;
@property (nonatomic, readonly, retain) NSArray *backgroundLimitBands;
/// @}

/// @name Plot Space
/// @{
@property (nonatomic, readwrite, retain) CPTPlotSpace *plotSpace;
/// @}

/// @name Layers
/// @{
@property (nonatomic, readwrite, assign) BOOL separateLayers;
@property (nonatomic, readwrite, cpt_weak_property) __cpt_weak CPTPlotArea *plotArea;
@property (nonatomic, readonly, cpt_weak_property) __cpt_weak CPTGridLines *minorGridLines;
@property (nonatomic, readonly, cpt_weak_property) __cpt_weak CPTGridLines *majorGridLines;
@property (nonatomic, readonly, retain) CPTAxisSet *axisSet;
/// @}

/// @name Title
/// @{
-(void)updateAxisTitle;
/// @}

/// @name Labels
/// @{
-(void)relabel;
-(void)setNeedsRelabel;
-(void)updateMajorTickLabels;
-(void)updateMinorTickLabels;
/// @}

/// @name Ticks
/// @{
-(NSSet *)filteredMajorTickLocations:(NSSet *)allLocations;
-(NSSet *)filteredMinorTickLocations:(NSSet *)allLocations;
/// @}

/// @name Background Bands
/// @{
-(void)addBackgroundLimitBand:(CPTLimitBand *)limitBand;
-(void)removeBackgroundLimitBand:(CPTLimitBand *)limitBand;
/// @}

@end

#pragma mark -

/** @category CPTAxis(AbstractMethods)
 *  @brief CPTAxis abstract methods—must be overridden by subclasses
 **/
@interface CPTAxis(AbstractMethods)

/// @name Coordinate Space Conversions
/// @{
-(CGPoint)viewPointForCoordinateDecimalNumber:(NSDecimal)coordinateDecimalNumber;
/// @}

/// @name Grid Lines
/// @{
-(void)drawGridLinesInContext:(CGContextRef)context isMajor:(BOOL)major;
/// @}

/// @name Background Bands
/// @{
-(void)drawBackgroundBandsInContext:(CGContextRef)context;
-(void)drawBackgroundLimitsInContext:(CGContextRef)context;
/// @}

@end
