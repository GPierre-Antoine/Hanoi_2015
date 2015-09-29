//
// main.cpp
//

#include <iostream>
#include "HanoiCube.h"

using namespace nsHanoi;
using namespace std;

namespace {

    void Affichage(){
        sf::Window hano�Window(sf::VideoMode(800, 600), "Hano�", sf::Style::Default);

        glEnable(GL_TEXTURE_3D);

        while (hano�Window.isOpen){
            sf::Event gameEvent;
            while (hano�Window.pollEvent(gameEvent)){
                if (gameEvent.type == sf::Event::Closed) hano�Window.close();
            }
        }
    }//Affichage

}//namespace



int main()
{
    HanoiCube Cube = HanoiCube(HanoiPoint(0, 0, 0), HanoiPoint(1, 0, 0),
                               HanoiPoint(0, 0, -1), HanoiPoint(0, 0.5, 0));
    Cube.Move(1, 1, 1);
    return 0;
}
