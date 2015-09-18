//
// Created by j14003626 on 18/09/15.
//

#include "HanoiPoint.h"


#define POINT nsHanoi::HanoiPoint

POINT::HanoiPoint(float X, float Y, float Z)
        : m_X(X), m_Y(Y), m_Z(Z)
{ }

float *POINT::GetPointVertex()
{
    float vertex[3] = {m_X, m_Y, m_Z};
    return vertex;
}