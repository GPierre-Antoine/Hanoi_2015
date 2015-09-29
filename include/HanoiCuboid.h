//
// HanoiCuboid.h
// Created by j14003626 on 18/09/15.
//

#pragma once

#include "HanoiPoint.h"
#include "HanoiMatrix.h"
#include <vector>

namespace nsHanoi
{
    class HanoiCuboid
    {
    private:
        float m_VPoints[8][4];
        //Tableau de points, chacun correspondant a un sommet du pave
        //8 Vecteurs : (x, y, z, w)

        //Fonction privee utilisee seulement dans notre classe pour simplifier expressions
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

        //Param : 4 points, ceux présents sur le cube ci-dessus
        //Desc : crée le cube
        HanoiCuboid(const HanoiPoint &A, const HanoiPoint &B, const HanoiPoint &D, const HanoiPoint &E);

        //Param : vecteur de translation 3D
        //Desc: applique la translation sur le pave
        void Move(float XTranslation, float YTranslation, float ZTranslation) noexcept;

        //Param : Matrice 4x4 de transformation
        //Desc : effectue la multiplication matricielle (avec $Transformation) pour chaque point du pave
        void ApplyTransformation(const HanoiMatrix &Transformation) noexcept;


    };
}

