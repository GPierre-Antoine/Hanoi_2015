//
// Created by g20901528 on 07/10/15.
//
#ifdef GRENABLED
    #include <GL/glu.h>
#endif

#include "RessourceManager.h"

#define make_cube(a,b) make_pair(std::unique_ptr<nsHanoi::Cube>(a),b)

using namespace std;
using namespace nsHanoi;


nsHanoi::RessourceManager::RessourceManager () {}

nsHanoi::RessourceManager & nsHanoi::RessourceManager::getInstance () noexcept
{
    static nsHanoi::RessourceManager i;
    return i;
}

void RessourceManager::setView() noexcept
{
#ifdef GRENABLED
    float unit = 2 * offset + biggest_disk;
    gluLookAt(
            3 * unit,number_of_pikes/2 * unit,5 * base_height,
            unit,number_of_pikes/2 * unit,2 * base_height,
            0,0,1
    );
#endif

}

void nsHanoi::RessourceManager::Initialize_All_Cubes () noexcept
{


    //support
    Point D(0,0,0);
    Point B((2*offset + biggest_disk),(2*offset + biggest_disk) * number_of_pikes,0);
    Point A((2*offset + biggest_disk),0,0);
    Point E((2*offset + biggest_disk),0,base_height);
    /*
    Point A(10, 0, 0);
    Point B(10, 20, 0);
    Point D(0, 0 , 0);
    Point E(10, 0, 4);
    */
    vect.reserve(9);
    vect.push_back ( make_cube (new Cube(A,B,D,E),0)); //index 0, does not matter


    //tiges
    for (unsigned i (0);i< number_of_pikes;++i)
    {
        A = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half, 0);
        B = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 + half, 0);
        D = Point((2*offset + biggest_disk) / 2 - half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half, 0);
        E = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half,
                  base_height + (number_of_disks * disk_height));

        vect.push_back( make_cube (new Cube(A, B, D, E),0));//index 0, does not matter
    }

    //disks
    for (unsigned char i (0);i<number_of_disks;++i)
    {
        float a = offset + i * delta_decrease;
        Point A_(a,a,base_height + i * disk_height);
        Point B_(a,a + (biggest_disk - (delta_decrease * i * 2)),
                 base_height + i * disk_height);
        Point D_(a + (biggest_disk - (delta_decrease * i * 2)),a,
                 base_height + i * disk_height);
        Point E_(a,a,base_height + (i + 1) * disk_height);

        vect.push_back( make_cube (new Cube(A_, B_, D_, E_),i + 1));
        //index 1 to number_of_disks +1.

    }
}

void nsHanoi::RessourceManager::RenderAll() const noexcept
{
    /**/
    for  (const tCube & i : vect)
        i.first->Affichage();
    //gluSphere(gluNewQuadric(),biggest_disk,5,5);
    /**/
}

#undef make_cube