//
// Created by Pierre-Antoine on 02/11/2015.
//

#pragma once


#include "Cube.h"

namespace nsHanoi
{
    class Pike : public Cube
    {
    public:
        Pike(const Point &A,const Point &B,const Point &D,const Point &E,const unsigned char pnumber);
        unsigned char number;
    };
}

