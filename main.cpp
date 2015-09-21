//
// main.cpp
//

#include <iostream>
#include "HanoiCube.h"

using namespace nsHanoi;
using namespace std;

int main()
{
    HanoiCube Cube = HanoiCube(HanoiPoint(0, 0, 0), HanoiPoint(1, 0, 0),
                               HanoiPoint(0, 0, -1), HanoiPoint(0, 0.5, 0));
    Cube.Move(1, 1, 1);
    return 0;
}
