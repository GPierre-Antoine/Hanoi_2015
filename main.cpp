#include <iostream>

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
    cout << "coucou";
    return 0;
}