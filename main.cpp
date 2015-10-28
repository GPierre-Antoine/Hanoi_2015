//
// main.cpp
//
#ifdef GRENABLED

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/GLU.h>
#endif


#include <Cube.h>
#include <RessourceManager.h>


using namespace nsHanoi;


int main()
{
    RessourceManager &rsm = nsHanoi :: RessourceManager :: getInstance();


    rsm.Initialize_All_Cubes();

    sf::RenderWindow window(sf::VideoMode(800, 600), "xX_HanoiCube_Xx", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    Cube Pave = Cube(Point(6, 5, 5), Point(6, 6, 5),
                         Point(5, 5, 5), Point(6, 5, 5.5));

    const sf::Time timePerFrame = sf::seconds(1.f / 60.f); //60fps
    sf::Clock clock;


    unsigned Cpt = 0;
    bool running = true;
    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            clock.restart();
            if (event.type == sf::Event::Closed)
            {

                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
#ifdef GRENABLED
                glViewport(0, 0, event.size.width, event.size.height);
#endif
            }
        }
#ifdef GRENABLED
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        gluPerspective(90,(double)640/480,1,1000);
        glEnable(GL_DEPTH_TEST);


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();


        rsm.setView();


        rsm.RenderAll();
#endif
        if (Cpt < 100)
        {
            Pave.Move(0.01, 0, 0);
            ++Cpt;
        }
        else if(Cpt >= 100 && Cpt < 200)
        {
            Pave.Move(0, 0, 0.01);
            ++Cpt;
        }

        window.display();
        while (clock.getElapsedTime () < timePerFrame)
            sf::sleep (sf::milliseconds (1));
    }



    return 0;
}
