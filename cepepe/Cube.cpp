//
// Cube.cpp
//

#include <GL/gl.h>
#include <Cube.h>
#include <iostream>

#ifdef GRENABLED

#endif

#define HAN nsHanoi::Cube

HAN::Cube(const Point &A, const Point &B,
                 const Point &D, const Point &E)
{
    //A
    SetPoint(0, A.X(), A.Y(), A.Z(), 1.0);

    //B
    SetPoint(1, B.X(), B.Y(), B.Z(), 1.0);

    //C
    SetPoint(2, D.X(), B.Y(), D.Z(), 1.0);

    //D
    SetPoint(3, D.X(), D.Y(), D.Z(), 1.0);

    //E
    SetPoint(4, E.X(), E.Y(), E.Z(), 1.0);

    //F
    SetPoint(5, B.X(), B.Y(), E.Z(), 1.0);

    //G
    SetPoint(6, D.X(), B.Y(), E.Z(), 1.0);

    //H
    SetPoint(7, D.X(), A.Y(), E.Z(), 1.0);

}

void HAN::SetPoint(unsigned Case, float X, float Y, float Z, float W) noexcept
{
    if (Case <= 7)
    {
        m_VPoints[Case][0] = X;
        m_VPoints[Case][1] = Y;
        m_VPoints[Case][2] = Z;
        m_VPoints[Case][3] = W;
    }
}

void HAN::AxeRotate (const byte_t Axe, double Rotation) noexcept
{
    nsHanoi::Matrix Transformation = Matrix();

    switch (Axe)
    {
        case AXE_X:
            Transformation.SetLine(0, 1, 0, 0, 0);
            Transformation.SetLine(1, 0, float(cos(Rotation)), float(-sin(Rotation)), 0);
            Transformation.SetLine(2, 0, float(sin(Rotation)), float(cos(Rotation)), 0);
            Transformation.SetLine(3, 0, 0, 0, 1);
            break;
        case AXE_Y:
            Transformation.SetLine(0, float(cos(Rotation)), 0, float(sin(Rotation)), 0);
            Transformation.SetLine(1, 0, 1, 0, 0);
            Transformation.SetLine(2, float(-sin(Rotation)), 0, float(cos(Rotation)), 0);
            Transformation.SetLine(3, 0, 0, 0, 1);
            break;
        case AXE_Z:
            Transformation.SetLine(0, float(cos(Rotation)), float(-sin(Rotation)), 0, 0);
            Transformation.SetLine(1, float(sin(Rotation)), float(cos(Rotation)), 0, 0);
            Transformation.SetLine(2, 0, 0, 1, 0);
            Transformation.SetLine(3, 0, 0, 0, 1);
            break;
        default:
            break;
    }

    ApplyTransformation(Transformation);

} // AxeRotate ()

void HAN::Rotate (const byte_t Axe, const Point & Origine, double Rotation) noexcept
{
    // On amene le cube a l'origine
    Move (-Origine.X(), -Origine.Y(), -Origine.Z());

    // Rotation par rapport a l'axe donne
    AxeRotate (Axe, Rotation);

    // On ramene le cube a sa position initiale
    Move (Origine.X(), Origine.Y(), Origine.Z());

} // Rotate ()

void HAN::Move(float XTranslation, float YTranslation, float ZTranslation) noexcept
{
    //Appliquer mouvement :
    //this *= Mat4x4
    //  (x)      (1 0 0 Tx)     (x')
    //  (y)  X   (0 1 0 Ty)  =  (y')
    //  (z)      (0 0 1 Tz)     (z')
    //  (w)      (0 0 0 1 )     (w')

    //Définition de la matrice Transformation
    nsHanoi::Matrix Transformation;
    Transformation.SetLine(0, 1, 0, 0, XTranslation);
    Transformation.SetLine(1, 0, 1, 0, YTranslation);
    Transformation.SetLine(2, 0, 0, 1, ZTranslation);
    Transformation.SetLine(3, 0, 0, 0, 1);

    ApplyTransformation(Transformation);
}

//Pour plus de compréhension dans la fonction suivante
#define T Transformation.m_M
#define P m_VPoints

void HAN::ApplyTransformation(const nsHanoi::Matrix &Transformation) noexcept
{

    for (unsigned i = 0; i < 8; ++i)
    {
        // X
        m_VPoints[i][0] = P[i][0] * T[0][0] + P[i][1] * T[0][1] + P[i][2] * T[0][2] + P[i][3] * T[0][3];
        // Y
        m_VPoints[i][1] = P[i][0] * T[1][0] + P[i][1] * T[1][1] + P[i][2] * T[1][2] + P[i][3] * T[1][3];
        // Z
        m_VPoints[i][2] = P[i][0] * T[2][0] + P[i][1] * T[2][1] + P[i][2] * T[2][2] + P[i][3] * T[2][3];
        // W
        m_VPoints[i][3] = P[i][0] * T[3][0] + P[i][1] * T[3][1] + P[i][2] * T[3][2] + P[i][3] * T[3][3];

    }

}

#undef P
#undef T


bool HAN::operator==(const Cube &Pave) const noexcept
{
    for (unsigned i = 0; i < 8; ++i)
        for (unsigned j = 0; j < 3; ++j)
            if (m_VPoints[i][j] != Pave.m_VPoints[i][j])
                return false;
    return true;
}

void HAN::Affichage() const noexcept
{
#ifdef GRENABLED

    sf::Image bord;
    sf::String bord_adr = "../HanoiTextures/Bord.png";

    if(!bord.loadFromFile(bord_adr))
        std::cout << "Erreur" << bord_adr.getData();

    GLuint bord_texture;
    glGenTextures(1, &bord_texture);

    glBindTexture(GL_TEXTURE_2D,bord_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            bord.getSize().x, bord.getSize().y,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            bord.getPixelsPtr()
    );

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,bord_texture);

    glBegin(GL_QUADS);


    //glColor3ub(0, 0, 120); //face ABFE
    glTexCoord2d(0.0,0.0);
    glVertex3d(m_VPoints[0][0], m_VPoints[0][1], m_VPoints[0][2]);//A
    glTexCoord2d(0.0,1.0);
    glVertex3d(m_VPoints[1][0], m_VPoints[1][1], m_VPoints[1][2]);//B
    glTexCoord2d(1.0,1.0);
    glVertex3d(m_VPoints[5][0], m_VPoints[5][1], m_VPoints[5][2]);//F
    glTexCoord2d(0.0,1.0);
    glVertex3d(m_VPoints[4][0], m_VPoints[4][1], m_VPoints[4][2]);//E

    //glColor3ub(0, 255, 255); //face ABCD
    glTexCoord2d(0.0,0.0);
    glVertex3d(m_VPoints[0][0], m_VPoints[0][1], m_VPoints[0][2]);//A
    glTexCoord2d(0.0,1.0);
    glVertex3d(m_VPoints[1][0], m_VPoints[1][1], m_VPoints[1][2]);//B
    glTexCoord2d(1.0,1.0);
    glVertex3d(m_VPoints[2][0], m_VPoints[2][1], m_VPoints[2][2]);//C
    glTexCoord2d(1.0,0.0);
    glVertex3d(m_VPoints[3][0], m_VPoints[3][1], m_VPoints[3][2]);//D

    //glColor3ub(0, 0, 120); //face FGCB
    glTexCoord2d(0.0,0.0);
    glVertex3d(m_VPoints[5][0], m_VPoints[5][1], m_VPoints[5][2]);//F
    glTexCoord2d(0.0,1.0);
    glVertex3d(m_VPoints[6][0], m_VPoints[6][1], m_VPoints[6][2]);//G
    glTexCoord2d(1.0,1.0);
    glVertex3d(m_VPoints[2][0], m_VPoints[2][1], m_VPoints[2][2]);//C
    glTexCoord2d(1.0,0.0);
    glVertex3d(m_VPoints[1][0], m_VPoints[1][1], m_VPoints[1][2]);//B

    //glColor3ub(0, 0, 120); //face EHDA
    glTexCoord2d(0.0,0.0);
    glVertex3d(m_VPoints[4][0], m_VPoints[4][1], m_VPoints[4][2]);//E
    glTexCoord2d(0.0,1.0);
    glVertex3d(m_VPoints[7][0], m_VPoints[7][1], m_VPoints[7][2]);//H
    glTexCoord2d(1.0,1.0);
    glVertex3d(m_VPoints[3][0], m_VPoints[3][1], m_VPoints[3][2]);//D
    glTexCoord2d(1.0,0.0);
    glVertex3d(m_VPoints[0][0], m_VPoints[0][1], m_VPoints[0][2]);//A

    //glColor3ub(0, 0, 120); //face HGCD
    glTexCoord2d(0.0,0.0);
    glVertex3d(m_VPoints[7][0], m_VPoints[7][1], m_VPoints[7][2]);//H
    glTexCoord2d(0.0,1.0);
    glVertex3d(m_VPoints[6][0], m_VPoints[6][1], m_VPoints[6][2]);//G
    glTexCoord2d(1.0,1.0);
    glVertex3d(m_VPoints[2][0], m_VPoints[2][1], m_VPoints[2][2]);//C
    glTexCoord2d(1.0,0.0);
    glVertex3d(m_VPoints[3][0], m_VPoints[3][1], m_VPoints[3][2]);//D

    glEnd();

    sf::Image dessus;
    sf::String dessus_adr = "../HanoiTextures/Dessus.png";

    if(!dessus.loadFromFile(dessus_adr))
        std::cout << "Erreur" << dessus_adr.getData();

    GLuint dessus_texture;
    glGenTextures(1, &dessus_texture);

    glBindTexture(GL_TEXTURE_2D,dessus_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            dessus.getSize().x, dessus.getSize().y,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            dessus.getPixelsPtr()
    );

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,dessus_texture);

    glBegin(GL_QUADS);



    //glColor3ub(120, 0, 0); //face HGFE
    glTexCoord2d(0.0,0.0);
    glVertex3d(m_VPoints[7][0], m_VPoints[7][1], m_VPoints[7][2]);//H
    glTexCoord2d(1.0,0.0);
    glVertex3d(m_VPoints[6][0], m_VPoints[6][1], m_VPoints[6][2]);//G
    glTexCoord2d(1.0,1.0);
    glVertex3d(m_VPoints[5][0], m_VPoints[5][1], m_VPoints[5][2]);//F
    glTexCoord2d(0.0,1.0);
    glVertex3d(m_VPoints[4][0], m_VPoints[4][1], m_VPoints[4][2]);//E


    glEnd();
#endif
}

nsHanoi::Point HAN::GetCenter () noexcept
{
    // (Dx + Ax) / 2
    float X = (m_VPoints[3][0] + m_VPoints[0][0]) / 2;

    // (Dy + Cy) / 2
    float Y = (m_VPoints[3][0] + m_VPoints[2][0]) / 2;

    // (Dz + Hz) / 2
    float Z = (m_VPoints[3][0] + m_VPoints[7][0]) / 2;

    return Point (X, Y, Z);

}


#undef HAN