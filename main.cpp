//
// main.cpp
//

#include "HanoiCuboid.h"

#include <SFML/Graphics.hpp>

using namespace nsHanoi;

int main()
{

    sf::Window window(sf::VideoMode(800, 600), "My window");

    // on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
    while (window.isOpen())
    {
        // on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
        sf::Event event;
        while (window.pollEvent(event))
        {
            // �v�nement "fermeture demand�e" : on ferme la fen�tre
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    /* * /
    HanoiCuboid Pave = HanoiCuboid(HanoiPoint(0, 0, 0), HanoiPoint(1, 0, 0),
                                   HanoiPoint(0, 0, -1), HanoiPoint(0, 0.5, 0));
    Pave.Move(1, 1, 1);
    /* */
    return 0;
}
