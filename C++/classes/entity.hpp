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