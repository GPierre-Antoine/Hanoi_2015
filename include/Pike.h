//
// Created by Pierre-Antoine on 02/11/2015.
//

#pragma once


#include "Cube.h"
#include "Disc.h"
#include <vector>

namespace nsHanoi
{
    class Pike
    {
    public:
        Pike(const Point &A,const Point &B,const Point &D,const Point &E,const unsigned char pnumber);
        Cube cube;
        unsigned char getNumber() const noexcept;
        void Affichage() const noexcept;
        void Add (Disc & a);
        Disc& getDisk ();
        virtual ~Pike(){}
    private:
        unsigned char compteur = 0;
        std::vector<Disc> disques();
        const unsigned char number;
    };
}

