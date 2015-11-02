//
// HanoiCuboid.h
//

#pragma once

#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Point.h"
#include "Matrix.h"


namespace nsHanoi
{
    typedef char unsigned byte_t;

    const byte_t AXE_X = 0;
    const byte_t AXE_Y = 1;
    const byte_t AXE_Z = 2;

    class Cube
    {
    private:
#ifdef GRENABLED
        GLuint texture = 0;
#endif
        float m_VPoints[8][4];
        //Tableau de points, chacun correspondant a un sommet du pave
        //8 Vecteurs : (x, y, z, w)

        //Fonction privee utilisee seulement dans notre classe pour simplifier expressions
        void SetPoint(unsigned Case, float X, float Y, float Z, float W) noexcept;
        
        //Rotation autour d'un axe donné
        void AxeRotate (const byte_t Axe, double Rotation) noexcept;

    public:

        //          H-------G
        //         /:      /|
        //        / :     / |             Z |
        //       E-------F  |               |
        //       |  D- - |- C               |_______ Y
        //       | /     | /               /
        //       |/      |/             X /
        //       A-------B

        //Param : 4 points, ceux présents sur le cube ci-dessus
        //Desc : crée le cube
        Cube(const Point &A, const Point &B, const Point &D, const Point &E);

        //Param : vecteur de translation 3D
        //Desc : applique la translation sur le pave
        void Move(float XTranslation, float YTranslation, float ZTranslation) noexcept;

        //Param : Axe de rotation, Angle en radian
        //Desc : Effectue une rotation du cube autout de l'axe de rotation
        void Rotate (const Droite & Axe, float AngleRadian) noexcept;

        //Param : Matrice 4x4 de transformation
        //Desc : effectue la multiplication matricielle (avec $Transformation) pour chaque point du pave
        void ApplyTransformation(const Matrix &Transformation) noexcept;

        //Param : Un autre pave
        //Desc : Compare deux cubes pour voir si leur position est equivalente
        bool operator == (const Cube & Pave) const noexcept;
        
        // Param : Axe de rotation, Origine : a partir de quelle origine on tourne, Rotation
        // Desc : Applique une rotation autour de l'axe donne, passant par Origine
        void Rotate (const byte_t Axe, const Point & Origine, double Rotation) noexcept;
        
        void Affichage () const noexcept;

        // Renvoit le point au centre du cube
        Point GetCenter () noexcept;
    
    }; // class Cube
}
