#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <SFML/Graphics.hpp>
class Map:public sf::Sprite
{
 double x_pos;
 double y_pos;
 double heigh;
 double width;
 public:
 Map(sf::Texture text);
};

#endif // MAP_H
