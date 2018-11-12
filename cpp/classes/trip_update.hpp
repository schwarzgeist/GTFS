//
//  File: trip_update.hpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 7/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#ifndef TRIP_UPDATE_HPP
#define TRIP_UPDATE_HPP

#include <cstdint>

#include "trip_descriptor.hpp"

class Trip_Update{
private:
    Trip_Descriptor trip_descriptor;
    char * trip_id;
    char * route_id;
    uint32_t direction_id;
    char * start_time;
    char * start_date;
public:
    Trip_Update();
    ~Trip_Update();
};

#endif //TRIP_UPDATE_HPP