//
// HanoiCube.h
// Created by j14003626 on 18/09/15.
//

#pragma once

#include "HanoiPoint.h"
#include "HanoiMatrix.h"
#include <vector>

namespace nsHanoi
{
    class HanoiCube
    {
    private:
        float m_VPoints[8][4];
        //Tableau de points, chacun correspondant à un sommet du cube
        //8 Vecteurs : (x, y, z, w)


        void setPoint(unsigned Case, float X, float Y, float Z, float W) noexcept;

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

        void ApplyTransformation(const HanoiMatrix &Transformation) noexcept;


    };
}

