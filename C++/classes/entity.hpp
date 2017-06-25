//
//  File: entity.hpp
//  Project: GTFS/C++
//
//  Created by Anthony Walker on 7/25/17.
//  Copyright © 2017 Anthony Walker. All rights reserved.
//

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "trip_update.hpp"
#include "trip_descriptor.hpp"

class Entity {
private:
    const char * id;
    Trip_Update trip_update;
    Trip_Descriptor trip_descriptor;

public:
    Entity();
    ~Entity();
};

#endif //ENTITY_HPP