#ifndef SPACE_H
#define SPACE_H

#include "defines.h"

class SpaceObject;
class SoundSource;

#include <string>
#include <vector>

class Space {
    public:
        //one vector required per iterable type
        std::vector<SpaceObject*> spaceObjects;
        std::vector<SoundSource*> soundSources;
        std::string debugInfo();
};

/*
std::string Space::debugInfo() {
    std::string result = "    Object Debug Info:    \n";
    for (int i = 0; i < spaceObjects.size(); i++) {
        result.append(spaceObjects[i].debugInfo()+"\n");
    }
    return result;
}
*/

#endif