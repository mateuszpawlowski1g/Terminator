#ifndef TERMINATOR_H
#define TERMINATOR_H
#include "Hero.h"

class Terminator : public Hero
{
    int HP_level;
    int Max_Hp;
    double speed;
    double pos_x;
    double pos_y;
    double DMG;
    double atack_ratio;
    double velocity;
    bool win;
     public:
     Terminator(sf::Texture text);
     void ruch(Terminator &term,const sf::Time& elapsed,double mouse_x,double mouse_y);
     //void atack();
     void get_hit(Terminator&term,sf::RectangleShape &rect);
     void get_hit_mele(Terminator&term,Hero obiekt);
     bool wygrana();
};

#endif // TERMINATOR_H
