#include <iostream>

using namespace std;

namespace {

    void Affichage(){
        sf::Window hanoïWindow(sf::VideoMode(800, 600), "Hanoï", sf::Style::Default);

        glEnable(GL_TEXTURE_3D);

        while (hanoïWindow.isOpen){
            sf::Event gameEvent;
            while (hanoïWindow.pollEvent(gameEvent)){
                if (gameEvent.type == sf::Event::Closed) hanoïWindow.close();
            }
        }
    }//Affichage

}//namespace



int main()
{
    cout << "coucou";
    return 0;
}