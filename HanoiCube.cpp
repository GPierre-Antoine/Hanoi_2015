//
// HanoiCube.cpp
// Created by j14003626 on 18/09/15.
//

#include "HanoiCube.h"

#define CUBE nsHanoi::HanoiCube

CUBE::HanoiCube(const HanoiPoint &A, const HanoiPoint &B,
                const HanoiPoint &D, const HanoiPoint &E)
{
    //A
    setPoint(0, A.X(), A.Y(), A.Z(), 1.0);

    //B
    setPoint(1, B.X(), B.Y(), B.Z(), 1.0);

    //CX = BX; CY = BY; CZ = DZ
    setPoint(2, B.X(), B.Y(), D.Z(), 1.0);

    //D
    setPoint(3, D.X(), D.Y(), D.Z(), 1.0);

    //E
    setPoint(4, E.X(), E.Y(), E.Z(), 1.0);

    //FX = BX; FY = EY; FZ = BZ
    setPoint(5, B.X(), E.Y(), B.Z(), 1.0);

    //GX = BX; GY = EY; GZ = DZ
    setPoint(6, B.X(), E.Y(), D.Z(), 1.0);

    //HX = AX; HY = EY; HZ = DZ
    setPoint(7, A.X(), E.Y(), D.Z(), 1.0);
}


void CUBE::setPoint(int Case, float X, float Y, float Z, float W) noexcept
{
    if (Case >= 0 || Case <= 7)
    {
        m_Points[Case][0] = X;
        m_Points[Case][1] = Y;
        m_Points[Case][2] = Z;
        m_Points[Case][3] = W;
    }
}

void CUBE::Move(float XTranslation, float YTranslation, float ZTranslation) noexcept
{
    //Appliquer mouvement :
    //this *= Mat4x4
    //  (x)      (1 0 0 Tx)     (x')
    //  (y)  X   (0 1 0 Ty)  =  (y')
    //  (z)      (0 0 1 Tz)     (z')
    //  (w)      (0 0 0 1 )     (w')

    //Définition de la matrice Transformation
    nsHanoi::Mat4x4 Transformation;
    Transformation[0] = {1, 0, 0, XTranslation};
    Transformation[1] = {0, 1, 0, YTranslation};
    Transformation[2] = {0, 0, 1, ZTranslation};
    Transformation[3] = {0, 0, 0, 1};

    ApplyTransformation(Transformation);
}

void CUBE::ApplyTransformation(const nsHanoi::Mat4x4 & Transformation) noexcept
{

}
