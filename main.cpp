//
// main.cpp
//

#include "HanoiCuboid.h"

#include <SFML/Graphics.hpp>

using namespace nsHanoi;

int main()
{

    sf::Window window(sf::VideoMode(800, 600), "My window");

    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
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
