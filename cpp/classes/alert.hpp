//
//  File: alert.hpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 6/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#ifndef ALERT_HPP
#define ALERT_HPP

#include "entity_selector.hpp"
#include "time_range.hpp"
#include "translated_string.hpp"

typedef enum {
    UNKNOWN_CAUSE = 1,
    OTHER_CAUSE = 2, // Not machine-representable.
    TECHNICAL_PROBLEM = 3,
    STRIKE = 4,        // Public transit agency employees stopped working.
    DEMONSTRATION = 5, // People are blocking the streets.
    ACCIDENT = 6,
    HOLIDAY = 7,
    WEATHER = 8,
    MAINTENANCE = 9,
    CONSTRUCTION = 10,
    POLICE_ACTIVITY = 11,
    MEDICAL_EMERGENCY = 12
} Cause;

typedef enum {
    NO_SERVICE = 1,
    REDUCED_SERVICE = 2,
    SIGNIFICANT_DELAYS = 3,
    DETOUR = 4,
    ADDITIONAL_SERVICE = 5,
    MODIFIED_SERVICE = 6,
    OTHER_EFFECT = 7,
    UNKNOWN_EFFECT = 8,
    STOP_MOVED = 9
}
Effect;

class Alert
{
  private:
    const int active_period_size;
    Time_Range * time_ranges;

    const int informed_entity_size;
    Entity_Selector * informed_entities;

    Cause cause;

    Effect effect;

    Translated_String url;
    Translated_String header_text;
    Translated_String description_text;

  public:
    Alert();
    ~Alert();
};

#endif //ALERT_HPP