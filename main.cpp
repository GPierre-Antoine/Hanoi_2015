//
// main.cpp
//

#include "Cube.h"

#include <cassert>

using namespace nsHanoi;

int main()
{
    Cuboid Pave = Cube(Point(1, 0, 0), Point(1, 1, 0),
                         Point(0, 0, 0), Point(0, 0, 0.5));

    Pave.Move(1, 1, 1);

    Cuboid Moved = Cube(Point(2, 1, 1), Point(2, 2, 1),
                          Point(1, 1, 1), Point(1, 1, 1.5));

    assert (Pave == Moved);



    return 0;
}