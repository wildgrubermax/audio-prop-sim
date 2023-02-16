#ifndef SOUNDSOURCE_H
#define SOUNDSOURCE_H

#include "defines.h"

class Space;

#include <string>
#include <vector>
#include <fmt/core.h>
#include "space.h"
#include "spaceobject.h"

//Soundsource
class SoundSource : public SpaceObject{  
    public:
        double frequency, phaseOffset, direction;
        SoundSource(double, double, double, double, double, double, Space&, std::string);
        std::string debugInfo();
        void registerToSpace(Space&);
};

SoundSource::SoundSource(double x, double y, double z, double frequency, double phaseOffset, double direction, Space& space, std::string name = UNIN_DEFAULT_STRING) : SpaceObject(x, y, z, true, name){
    this->frequency = frequency;
    this->phaseOffset = phaseOffset;
    this->direction = direction;

    registerToSpace(space);
}

std::string SoundSource::debugInfo() {
    std::string result = SpaceObject::debugInfo();
    result += "\n\t-SoundSource@|Freq:" + fmt::format("{:.2f}", frequency) + "|Phase:" + fmt::format("{:.2f}", phaseOffset) + "|Dir:" + fmt::format("{:.2f}", direction) + "|";
    return result;
}

void SoundSource::registerToSpace(Space& space) {
    SpaceObject::registerToSpace(space);
    space.soundSources.push_back(this);
}

#endif