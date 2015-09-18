//
// HanoiPoint.h
// Created by j14003626 on 18/09/15.
//

#pragma once

namespace nsHanoi
{
    class HanoiPoint
    {
    private:

        float m_X;
        float m_Y;
        float m_Z;

    public:
        HanoiPoint(float m_X, float m_Y, float m_Z);

        float X() const;

        float Y() const;

        float Z() const;
    };
}