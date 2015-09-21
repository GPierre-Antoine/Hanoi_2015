//
// HanoiCube.h
// Created by j14003626 on 18/09/15.
//

#pragma once

#include "HanoiPoint.h"
#include <vector>

namespace nsHanoi
{
    typedef float
    typedef float Mat4x4[4][4];

    class HanoiCube
    {
    private:
        float m_Points[8][4];
        //Tableau de points, chacun correspondant à un sommet du cube
        //8 Vecteurs : (x, y, z, w)


        void setPoint(int Case, float X, float Y, float Z, float W) noexcept;

    public:
        //          H-------G
        //         /:      /|
        //        / :     / |             Y |
        //       E-------F  |               |
        //       |  D- - |- C               |_______ X
        //       | /     | /               /
        //       |/      |/             Z /
        //       A-------B
        HanoiCube(const HanoiPoint &A, const HanoiPoint &B, const HanoiPoint &D, const HanoiPoint &E);

        void Move(float XTranslation, float YTranslation, float ZTranslation) noexcept;

        void ApplyTransformation(const Mat4x4 & Transformation) noexcept;


    };
}

