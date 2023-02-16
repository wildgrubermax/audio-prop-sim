#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include "defines.h"

class Space;

#include <string>
#include <vector>
#include <fmt/core.h>
#include "space.h"

//Container for objects in the workspace
class SpaceObject {
    public:
        double x, y, z;
        bool enabled;
        std::string name;
        SpaceObject(double, double, double, bool, std::string);
        SpaceObject(double, double, double, bool, Space&, std::string);
        std::string debugInfo();
        void registerToSpace(Space&);
};

SpaceObject::SpaceObject(double x, double y, double z, bool enabled, Space& space, std::string name = UNIN_DEFAULT_STRING) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->enabled = enabled;
    this->name = name;

    registerToSpace(space);
}

SpaceObject::SpaceObject(double x, double y, double z, bool enabled, std::string name = UNIN_DEFAULT_STRING) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->enabled = enabled;
    this->name = name;
}

std::string SpaceObject::debugInfo() {
    std::string result = name + "@|X:" + fmt::format("{:.2f}",x) + "|Y:" + fmt::format("{:.2f}",y) + "|Z:" + fmt::format("{:.2f}",z) + "|E:" + std::to_string(enabled) + "|";
    return result;
}

void SpaceObject::registerToSpace(Space& space) {
    space.spaceObjects.push_back(this);
}

#endif