//
// Created by j14003626 on 18/09/15.
//

#pragma once

namespace nsHanoi
{
    class HanoiCube
    {
    private:
        float m_Points[8][3];

    public:
        //          H-------G
        //         /:      /|
        //        / :     / |
        //       E-------F  |
        //       |  D- - |- C
        //       | /     | /
        //       |/      |/
        //       A-------B
        HanoiCube(float A, float B, float D, float E);
    };
}

