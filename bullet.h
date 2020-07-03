#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
class bullet : public sf::RectangleShape
{
    int i;
    double speed;
    double vx;
    double vy;
    int posx;
    int posy;
public:
    bullet(double x,sf::Sprite sp,double y);
    void strzal(bullet &bl,const sf::Time &elapsed,int dmg,int x,int y);
    void strzal(bullet&bl,const sf::Time &elapsed,sf::Sprite sp,int x,int y);
    bool kolizja(bullet&bl,sf::Sprite &sp);
};

#endif // BULLET_H
