//
//  File: time_range.cpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 6/27/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#include "time_range.hpp"

Time_Range::Time_Range() {
    this->start = 0;
    this->end = 0;
 }

 Time_Range::Time_Range(uint64_t start_time, uint64_t end_time){
     this->start = start_time;
     this->end = end_time;
 }

Time_Range::~Time_Range() { }

uint64_t Time_Range::get_start_time(){
    return this->start;
}

uint64_t Time_Range::get_end_time(){
    return this->end;
}

void Time_Range::set_start_time(uint64_t start_time){
    this->start = start_time;
}

void Time_Range::set_end_time(uint64_t end_time){
    this->end = end_time;
}