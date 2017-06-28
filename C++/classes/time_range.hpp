//
//  File: time_range.hpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 6/27/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#ifndef TIME_RANGE_HPP
#define TIME_RANGE_HPP

#include <cstdint>

class Time_Range{
private:
    uint64_t start;
    uint64_t end;
public:
    Time_Range();
    Time_Range(uint64_t start_time, uint64_t end_time);
    ~Time_Range();

    //accessors
    uint64_t get_start_time(void);
    uint64_t get_end_time(void);
    void set_start_time(uint64_t start_time);
    void set_end_time(uint64_t end_time);
};

#endif