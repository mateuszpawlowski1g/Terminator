#include "bullet.h"

bullet::bullet(double x,sf::Sprite sp,double y):sf::RectangleShape()
{
    speed=200;
    i=0;
    posx=x;
    posy=y;
    sf::FloatRect granice = sp.getGlobalBounds();
    vx=(granice.left-x)/(granice.top-y);
    vy=(granice.top-y)/(granice.left-x);
    if(vx>-1&&vx<0){
        vx=-1;
    }
    if(vx>0&&vx<1){
        vx=1;
    }
    if(vy>-1&&vy<0){
        vy=-1;
    }
    if(vy>0&&vy<1){
        vy=1;
    }
}
void bullet::strzal(bullet &bl,const sf::Time &elapsed,int dmg,int x,int y){
    float ruchX = 0, ruchY = 0;
    //bl.setPosition(bl.posx,bl.posy);
    bl.setSize(sf::Vector2f(5,5));
    bl.setFillColor(sf::Color::White);
    ruchX=bl.speed*bl.vx*elapsed.asSeconds();
     ruchY=bl.speed*bl.vy*elapsed.asSeconds();
     bl.move(sf::Vector2f(ruchX,ruchY));
}
void bullet::strzal(bullet&bl,const sf::Time &elapsed,sf::Sprite sp,int x,int y){
    sf::Vector2f strzelec=sp.getPosition();
    if(i==0){
        bl.setPosition(strzelec.x,strzelec.y);
        bl.vx=(strzelec.x-x)/(strzelec.y-y);
        bl.vy=(strzelec.y-y)/(strzelec.x-x);
//         bl.vx=abs((x-strzelec.x)/(y-strzelec.y));
//         bl.vy=abs((y-strzelec.y)/(x-strzelec.x));
         if(x<strzelec.x&&y<strzelec.y){
             bl.vx=bl.vx*(-1);
             bl.vy=bl.vy*(-1);
         }
         if(x<strzelec.x&&y>=strzelec.y){
              bl.vy=bl.vy*(-1);
         }
         if(x>=strzelec.x&&y<strzelec.y){
              bl.vx=bl.vx*(-1);
         }
      //  std::cout<<strzelec.x<<"     "<<strzelec.y<<std::endl;
    }
    else{
        float ruchX = 0, ruchY = 0;

        bl.setSize(sf::Vector2f(5,5));
        bl.setFillColor(sf::Color::White);
        ruchX=bl.speed*bl.vx*elapsed.asSeconds();
         ruchY=bl.speed*bl.vy*elapsed.asSeconds();
         bl.move(sf::Vector2f(ruchX,ruchY));
    }
    i++;
}
bool kolizja(bullet&bl,sf::Sprite &sp){
    //sf::Vector2f bull= bl.getGlobalBounds();

}
