//
//  EKAlarm.h
//  EventKit
//
//  Copyright 2009-2010 Apple Inc. All rights reserved.
//

#import <EventKit/EventKitDefines.h>
#import <EventKit/EKObject.h>
#import <EventKit/EKTypes.h>

@class EKCalendarItem, EKStructuredLocation;

/*!
    @class          EKAlarm
    @abstract       The EKAlarm class provides an interface for accessing and manipulating calendar event alarms.
    @discussion     The EKAlarm class represents alarms on an event. An alarm can be relative (e.g. 15 mins before) 
                    or absolute (specific time).
*/
EVENTKIT_CLASS_AVAILABLE(10_8, 4_0)
@interface EKAlarm : EKObject <NSCopying> {
}

/*!
    @method     alarmWithAbsoluteDate:
    @abstract   Creates a new autoreleased alarm with an absolute trigger time.
    @param      date    The date the alarm should fire.
*/
+ (EKAlarm *)alarmWithAbsoluteDate:(NSDate *)date;

/*!
    @method     alarmWithRelativeOffset:
    @abstract   Creates a new autoreleased alarm with a relative trigger time.
    @discussion Creates a new autoreleased alarm with a relative trigger time. This offset
                is added to the start date of the event.

    @param      offset    The offset from the event start that the alarm should fire.
*/
+ (EKAlarm *)alarmWithRelativeOffset:(NSTimeInterval)offset;

/*!
    @property   relativeOffset
    @abstract   Specifies a relative offset from an event start date to fire an alarm.
    @discussion Set this property to an appropriate negative value to establish an alarm trigger
                relative to the start date/time of an event. Setting this clears any existing
                date trigger.
*/
@property(nonatomic) NSTimeInterval relativeOffset;

/*!
    @property   absoluteDate
    @abstract   Represents an alarm that fires at a specific date.
    @discussion Set this property to a date to establish an absolute alarm trigger. Setting this
                clears any relative interval trigger.
*/
@property(nonatomic, copy) NSDate *absoluteDate;

/*!
    @property   structuredLocation
    @discussion Allows you to set a structured location (a location with a potential geo-coordinate)
                on an alarm. This is used in conjunction with proximity to do geofence-based
                triggering of reminders.
 */
@property(nonatomic, copy) EKStructuredLocation   *structuredLocation;

/*!
    @property   proximity
    @discussion Defines whether this alarm triggers via entering/exiting a geofence as defined by
                structuredLocation.
 */
@property(nonatomic) EKAlarmProximity    proximity;


@end
