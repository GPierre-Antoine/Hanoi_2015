//
// HanoiPoint.cpp
// Created by j14003626 on 18/09/15.
//

#include "HanoiPoint.h"


#define POINT nsHanoi::HanoiPoint

POINT::HanoiPoint(float X, float Y, float Z)
        : m_X(X), m_Y(Y), m_Z(Z)
{ }

float POINT::X() const
{
    return m_X;
}

float POINT::Y() const
{
    return m_Y;
}

float POINT::Z() const
{
    return m_Z;
}