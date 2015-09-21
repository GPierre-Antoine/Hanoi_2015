//
// HanoiCube.h
// Created by j14003626 on 18/09/15.
//

#pragma once

#include "HanoiPoint.h"

namespace nsHanoi
{
    class HanoiCube
    {
    private:
        float m_Points[8][3];


        void setPoint(int Case, float X, float Y, float Z) noexcept;

    public:
        //          H-------G
        //         /:      /|
        //        / :     / |
        //       E-------F  |
        //       |  D- - |- C
        //       | /     | /
        //       |/      |/
        //       A-------B
        HanoiCube(const HanoiPoint &A, const HanoiPoint &B, const HanoiPoint &D, const HanoiPoint &E);
    };
}

