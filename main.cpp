//
// main.cpp
//

#include "HanoiCuboid.h"

using namespace nsHanoi;

int main()
{
    HanoiCuboid Pave = HanoiCuboid(HanoiPoint(0, 0, 0), HanoiPoint(1, 0, 0),
                                   HanoiPoint(0, 0, -1), HanoiPoint(0, 0.5, 0));
    Pave.Move(1, 1, 1);

    return 0;
}
