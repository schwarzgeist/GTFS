//
//  File: feed.hpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 7/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#ifndef FEED_H
#define FEED_H

#include "feed_header.hpp"
#include "entity.hpp"

class Feed{
private:
    Feed_Header header; //an instance of the Feed_Header class to store header information
    int entity_size; //the number of entities a feed has
    Entity * entities;

public:
    Feed();
    Feed(char * feed_file_contents);
    ~Feed();

    //accessors
    Feed_Header get_feed_header(void);
    int get_entity_count(void);
    Entity * get_feed_entities(void);
};

#endif //FEED_H