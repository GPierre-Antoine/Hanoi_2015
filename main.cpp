//
// main.cpp
//

#include <iostream>
#include "HanoiCube.h"

#include <cstdio>
#include <cstdlib>


using namespace std;
using namespace nsHanoi;

int main()
{
    HanoiCube(HanoiPoint(0, 0, 0), HanoiPoint(1, 0, 0), HanoiPoint(0, 0, -1), HanoiPoint(0, 1, 0));
    return 0;
}