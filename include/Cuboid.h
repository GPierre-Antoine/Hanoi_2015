//
// HanoiCuboid.h
// Created by j14003626 on 18/09/15.
//

#pragma once

#include <vector>

#include "Point.h"
#include "Matrix.h"

namespace nsHanoi
{
    class Cuboid
    {
    private:
        float m_VPoints[8][4];
        //Tableau de points, chacun correspondant a un sommet du pave
        //8 Vecteurs : (x, y, z, w)

        //Fonction privee utilisee seulement dans notre classe pour simplifier expressions
        void SetPoint(unsigned Case, float X, float Y, float Z, float W) noexcept;

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
        Cuboid(const Point &A, const Point &B, const Point &D, const Point &E);

        //Param : vecteur de translation 3D
        //Desc : applique la translation sur le pave
        void Move(float XTranslation, float YTranslation, float ZTranslation) noexcept;

        //Param :
        //Desc :
        //void Rotate (const CDroite)

        //Param : Matrice 4x4 de transformation
        //Desc : effectue la multiplication matricielle (avec $Transformation) pour chaque point du pave
        void ApplyTransformation(const Matrix &Transformation) noexcept;

        //Param : Un autre pave
        //Desc : Compare deux cubes pour voir si leur position est equivalente
        bool operator == (const Cuboid & Pave) const noexcept;

    };
}