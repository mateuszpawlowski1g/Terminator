#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "map.h"

class Background : public Map
{
public:
  Background(sf::Texture text);
  void fill();//wypełnienie calej mapy
};

#endif // BACKGROUND_H
