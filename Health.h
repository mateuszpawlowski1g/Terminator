#ifndef HEALTH_H
#define HEALTH_H
#include "map.h"

class Health : public Map
{
public:
  Health(sf::Texture text);
  void health_lv();
};

#endif // HEALTH_H
