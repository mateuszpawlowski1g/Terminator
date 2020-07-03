#ifndef TERMINATOR_H
#define TERMINATOR_H
#include "Hero.h"

class Terminator : public Hero
{
    bool win;
     public:
     Terminator();
     void move();
     void atack();
     void get_hit();
     bool wygrana();
};

#endif // TERMINATOR_H
