//
// Point.cpp
//

#include "Point.h"


#define POINT nsHanoi::Point

POINT::Point(float X, float Y, float Z)
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