//
// Droite.h
//

#pragma once

#include "Point.h"

namespace nsHanoi
{
    class Droite
    {
    public:
        Point P1;
        Point P2;

        Droite (const Point & P1, const Point & P2) noexcept;
    };
}