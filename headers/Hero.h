#ifndef HERO_H
#define HERO_H


#include <SFML/Graphics.hpp>
#include <iostream>
class Hero:public sf::Sprite
{
 int HP_level;
 int Max_Hp;
 double speed;
 double pos_x;
 double pos_y;
 double DMG;
 double atack_ratio;
 double velocity;
 public:
 Hero();
 virtual void atack();
 virtual void get_hit();
};
#endif // HERO_H
