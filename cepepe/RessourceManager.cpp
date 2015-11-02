//
// Created by g20901528 on 07/10/15.
//

#include <cstddef>

#ifdef GRENABLED
    #include <GL/glu.h>
#endif


#include "RessourceManager.h"



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
    *support =  (Cube(A,B,D,E));
    //tiges
    for (unsigned char i (0);i< number_of_pikes;++i)
    {
        A = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half, 0);
        B = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 + half, 0);
        D = Point((2*offset + biggest_disk) / 2 - half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half, 0);
        E = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half,
                  base_height + (number_of_disks * disk_height));

        cols.push_back (Pike(A, B, D, E,i));
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

        disks.push_back (Disc(A_,B_,D_,E_,i));
        //index 1 to number_of_disks +1.

    }
}

void nsHanoi::RessourceManager::RenderAll() const noexcept
{
    /**/
    support->Affichage ();
    for  (const Pike & i : cols)
        i.Affichage();
    //gluSphere(gluNewQuadric(),biggest_disk,5,5);
    /**/
}

void nsHanoi::RessourceManager::Algorithme ()
{
    HanoiA (number_of_disks,0,2,1);
}

/**/
void nsHanoi::RessourceManager::HanoiA (unsigned int nbdisk, size_t origine, size_t dest, size_t intermediaire)
{
    if (nbdisk)
    {
        HanoiA (nbdisk - 1, origine, intermediaire, dest);
        Disc & temp = cols[origine].getDisk ();
        temp.Moveto (cols[dest].cube);

        cols[dest].Add (temp);
        HanoiA (nbdisk - 1, intermediaire, dest, origine);
    }
}/**/