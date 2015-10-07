//
// Created by j14003626 on 21/09/15.
//

#pragma once

namespace nsHanoi
{
    class Matrix
    {
    public:
        float m_M[4][4];

        void SetLine(unsigned Line, float A, float B, float C, float D) noexcept;
    };
}
