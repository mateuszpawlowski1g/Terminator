#ifndef MELEEENEMY_H
#define MELEEENEMY_H

#include "Hero.h"
class MeleeEnemy : public Hero
{
    double speed;
    int stop;
public:
 MeleeEnemy(sf::Texture text);
 void atack();
 void get_hit();
 void auto_pilot(MeleeEnemy &mel,sf::Sprite sp,const sf::Time &elapsed);
 void sciana(MeleeEnemy&mel,sf::RectangleShape&rect);
};

#endif // MELEEENEMY_H
