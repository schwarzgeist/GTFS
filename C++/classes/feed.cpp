//
//  File: feed.cpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 7/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#include "feed.hpp"
#include "feed_header.hpp"
#include "entity.hpp"

Feed::Feed(){ }

Feed::Feed(char * feed_file_contents) { 
    
}

Feed::~Feed() { }

Feed_Header Feed::get_feed_header() { 
    return this->header;
}

int Feed::get_entity_count() {
    return this->entity_size;
}

Entity * Feed::get_feed_entities() {
    return this->entities;
}