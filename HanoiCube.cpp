//
// HanoiCube.cpp
// Created by j14003626 on 18/09/15.
//

#include "HanoiCube.h"

#define CUBE nsHanoi::HanoiCube

CUBE::HanoiCube(const HanoiPoint &A, const HanoiPoint &B, const HanoiPoint &D, const HanoiPoint &E)
{
    //A
    setPoint(0, A.X(), A.Y(), A.Z());

    //B
    setPoint(1, B.X(), B.Y(), B.Z());

    //CX = BX; CY = BY; CZ = DZ
    setPoint(2, B.X(), B.Y(), D.Z());

    //D
    setPoint(3, D.X(), D.Y(), D.Z());

    //E
    setPoint(4, E.X(), E.Y(), E.Z());

    //FX = BX; FY = EY; FZ = BZ
    setPoint(5, B.X(), E.Y(), B.Z());

    //GX = BX; GY = EY; GZ = DZ
    setPoint(6, B.X(), E.Y(), D.Z());

    //HX = AX; HY = EY; HZ = DZ
    setPoint(7, A.X(), E.Y(), D.Z());
}


void CUBE::setPoint(int Case, float X, float Y, float Z) noexcept
{
    if (Case >= 0 || Case <= 7)
    {
        m_Points[Case][0] = X;
        m_Points[Case][1] = Y;
        m_Points[Case][2] = Z;
    }
}