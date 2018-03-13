//
//  EKTypes.h
//  EventKit
//
//  Copyright 2011 Apple Inc. All rights reserved.
//

#import <Foundation/NSObjCRuntime.h>

/*!
    @enum       EKAuthorizationStatus
    @abstract   This enumerated type is used to indicate the currently granted authorization status for a specific
                entity type.
    @constant   EKAuthorizationStatusNotDetermined  The user has not yet made a choice regarding whether this application
                                                    may access the service.
    @constant   EKAuthorizationStatusRestricted     This application is not authorized to access the service.
                                                    The user cannot change this application’s status, possibly due to
                                                    active restrictions such as parental controls being in place.
    @constant   EKAuthorizationStatusDenied         The user explicitly denied access to the service for this application.
    @constant   EKAuthorizationStatusAuthorized     This application is authorized to access the service.
 */
typedef NS_ENUM(NSInteger, EKAuthorizationStatus) {
    EKAuthorizationStatusNotDetermined = 0,
    EKAuthorizationStatusRestricted,
    EKAuthorizationStatusDenied,
    EKAuthorizationStatusAuthorized,
} __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_6_0);


enum {
    EKSunday = 1,
    EKMonday,
    EKTuesday,
    EKWednesday,
    EKThursday,
    EKFriday,
    EKSaturday
};

/*!
    @enum       EKRecurrenceFrequency
    @abstract   The frequency of a recurrence
    @discussion EKRecurrenceFrequency designates the unit of time used to describe the recurrence.
                It has four possible values, which correspond to recurrence rules that are defined
                in terms of days, weeks, months, and years.
*/
typedef enum {
    EKRecurrenceFrequencyDaily,
    EKRecurrenceFrequencyWeekly,
    EKRecurrenceFrequencyMonthly,
    EKRecurrenceFrequencyYearly
} EKRecurrenceFrequency;

/*!
 @enum       EKParticipantType
 @abstract   Value representing the type of attendee.
 */
typedef enum {
    EKParticipantTypeUnknown,
    EKParticipantTypePerson,
    EKParticipantTypeRoom,
    EKParticipantTypeResource,
    EKParticipantTypeGroup
} EKParticipantType;

/*!
 @enum       EKParticipantRole
 @abstract   Value representing the role of a meeting participant.
 */
typedef enum {
    EKParticipantRoleUnknown,
    EKParticipantRoleRequired,
    EKParticipantRoleOptional,
    EKParticipantRoleChair,
    EKParticipantRoleNonParticipant
} EKParticipantRole;

/*!
 @enum       EKParticipantStatus
 @abstract   Value representing the status of a meeting participant.
 */
typedef enum {
    EKParticipantStatusUnknown,
    EKParticipantStatusPending,
    EKParticipantStatusAccepted,
    EKParticipantStatusDeclined,
    EKParticipantStatusTentative,
    EKParticipantStatusDelegated,
    EKParticipantStatusCompleted,
    EKParticipantStatusInProcess
} EKParticipantStatus;


/*!
 @enum       EKCalendarType
 @abstract   An enum representing the type of a calendar.
 
 @constant   EKCalendarTypeLocal        This calendar is sync'd from either Mobile Me or tethered.
 @constant   EKCalendarTypeCalDAV       This calendar is from a CalDAV server.
 @constant   EKCalendarTypeExchange     This calendar comes from an Exchange server.
 @constant   EKCalendarTypeSubscription This is a locally subscribed calendar.
 @constant   EKCalendarTypeBirthday     This is the built-in birthday calendar.
 */

typedef enum {
    EKCalendarTypeLocal,
    EKCalendarTypeCalDAV,
    EKCalendarTypeExchange,
    EKCalendarTypeSubscription,
    EKCalendarTypeBirthday
} EKCalendarType;

// Event availability support (free/busy)
enum {
    EKCalendarEventAvailabilityNone         = 0,    // calendar doesn't support event availability
    
    EKCalendarEventAvailabilityBusy         = (1 << 0),
    EKCalendarEventAvailabilityFree         = (1 << 1),
    EKCalendarEventAvailabilityTentative    = (1 << 2),
    EKCalendarEventAvailabilityUnavailable  = (1 << 3),
};
typedef NSUInteger EKCalendarEventAvailabilityMask;

typedef enum {
    EKSourceTypeLocal,
    EKSourceTypeExchange,
    EKSourceTypeCalDAV,
    EKSourceTypeMobileMe,
    EKSourceTypeSubscribed,
    EKSourceTypeBirthdays
} EKSourceType;

/*!
 @enum       EKEntityType
 @abstract   A value which specifies an entity type of event or reminder.
 */
enum {
    EKEntityTypeEvent,
    EKEntityTypeReminder
};
typedef NSUInteger EKEntityType;

/*!
 @enum       EKEntityMask
 @abstract   A bitmask based on EKEntityType that can be used to specify multiple entities at once.
 */
enum {
    EKEntityMaskEvent      = (1 << EKEntityTypeEvent),
    EKEntityMaskReminder   = (1 << EKEntityTypeReminder)
};
typedef NSUInteger EKEntityMask;

/*!
 @enum       EKAlarmProximity
 @abstract   A value indicating whether an alarm is triggered by entering or exiting a geofence.
 
 @constant   EKAlarmProximityNone       The alarm has no proximity trigger.
 @constant   EKAlarmProximityEnter      The alarm is set to fire when entering a region (geofence).
 @constant   EKAlarmProximityLeave      The alarm is set to fire when leaving a region (geofence).
 */
enum {
    EKAlarmProximityNone,
    EKAlarmProximityEnter,
    EKAlarmProximityLeave
};
typedef NSInteger EKAlarmProximity;
