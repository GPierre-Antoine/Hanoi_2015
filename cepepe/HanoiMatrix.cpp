//
// Created by j14003626 on 21/09/15.
//

#include "HanoiMatrix.h"

#define MAT nsHanoi::HanoiMatrix

void MAT::SetLine(unsigned Line, float A, float B, float C, float D) noexcept
{
    if (Line >= 0 || Line <= 4)
    {
        m_M[Line][0] = A;
        m_M[Line][1] = B;
        m_M[Line][2] = C;
        m_M[Line][3] = D;
    }
}