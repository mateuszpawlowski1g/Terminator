#include <SFML/Graphics.hpp>
#include <iostream>
#include "background.h"
#include "button.h"
#include "health.h"
#include "Hero.h"
#include "map.h"
#include "meleeenemy.h"
#include "rangeenemy.h"
#include "terminator.h"
#include "wall.h"
int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Terminator");
    std::cout<<"-------------"<<std::endl;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Black);


        window.display();
    }

    return 0;
}
