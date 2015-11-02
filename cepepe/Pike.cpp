//
// Created by Pierre-Antoine on 02/11/2015.
//

#include "Pike.h"
#include "Disc.h"


nsHanoi::Pike::Pike(const Point &A,const Point &B,const Point &D,const Point &E,const unsigned char pnumber) : cube(A,B,D,E), number(pnumber)
{
}

void nsHanoi::Pike::Affichage() const noexcept
{
    cube.Affichage();
    for (unsigned long long i {0};i < compteur;++i)
    {
        disques[i].Affichage ();
    }
}

void nsHanoi::Pike::Add (Disc & a)
{
    ++compteur;
    disques.push_back (a);
}

nsHanoi::Disc & nsHanoi::Pike::getDisk()
{
    Disc &temp = disques[compteur--];
    disques.pop_back ();
    return temp;
}