#ifndef RANGEENEMY_H
#define RANGEENEMY_H
#include "Hero.h"

class RangeEnemy : public Hero
{

public:
 RangeEnemy(sf::Texture text);
 void atack();//strzelanie+celowanie
 void get_hit();

};

#endif // RANGEENEMY_H
