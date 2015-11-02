//
// Created by Pierre-Antoine on 02/11/2015.
//

#pragma once


#include "Cube.h"

namespace nsHanoi
{
    class Disc : public Cube
    {
    public:

        Disc (const Point &A, const Point &B, const Point &D, const Point &E,const unsigned char psize);
        unsigned char size;

    };

}