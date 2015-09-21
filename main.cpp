//
// main.cpp
//

#include <iostream>
#include "HanoiCube.h"

using namespace nsHanoi;
using namespace std;

int main()
{
    HanoiCube(HanoiPoint(0, 0, 0), HanoiPoint(1, 0, 0), HanoiPoint(0, 0, -1), HanoiPoint(0, 0.5, 0));
    return 0;
}
