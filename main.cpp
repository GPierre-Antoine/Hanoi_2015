//
// main.cpp
//

#include "Cuboid.h"

using namespace nsHanoi;

int main()
{
    Cuboid Pave = Cuboid(Point(0, 0, 0), Point(1, 0, 0),
                                   Point(0, 0, -1), Point(0, 0.5, 0));
    Pave.Move(1, 1, 1);

    return 0;
}
