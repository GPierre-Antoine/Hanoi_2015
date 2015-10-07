//
// main.cpp
//

#include "Cuboid.h"

#include <cassert>

using namespace nsHanoi;

int main()
{
    Cuboid Pave = Cuboid(Point(1, 0, 0), Point(1, 1, 0),
                         Point(0, 0, 0), Point(0, 0, 0.5));

    Pave.Move(1, 1, 1);

    Cuboid Moved = Cuboid(Point(2, 1, 1), Point(2, 2, 1),
                          Point(1, 1, 1), Point(1, 1, 1.5));

    assert (Pave == Moved);

    return 0;
}
