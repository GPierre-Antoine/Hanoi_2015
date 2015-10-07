//
// Droite.cpp
//

#include "Droite.h"
#include "Point.h"

#define HAN nsHanoi::Droite

HAN::Droite (const nsHanoi::Point & Pt1, const nsHanoi::Point & Pt2) noexcept
    : P1 (Pt1), P2(Pt2)
{

}

#undef HAN
