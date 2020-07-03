#ifndef MELEEENEMY_H
#define MELEEENEMY_H

#include "Hero.h"
class MeleeEnemy : public Hero
{
public:
 MeleeEnemy();
 void atack();
 void get_hit();
 void auto_pilot(); //podążanie w kierunku gracza
};

#endif // MELEEENEMY_H
