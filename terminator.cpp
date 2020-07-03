#include "terminator.h"
#include "cmath"
Terminator::Terminator(sf::Texture text):Hero()
{
    pos_x= 700;
    pos_y=500;
    speed=100;
    Max_Hp=500;
    HP_level=500;
    DMG=50;
    atack_ratio=1;
    velocity=0;
    win=false;
}
void Terminator::ruch(Terminator &term,const sf::Time& elapsed,double mouse_x,double mouse_y){
    float ruchX = 0, ruchY = 0;
    //    term.rotate(term.velocity*(-1));
    //    sf::RectangleShape mysz;
    //    int x=term.pos_x-mouse_x;
    //    int y=term.pos_y-mouse_y;
    //    int c=sqrt((x*x)+(y*y));
    //    sf::RectangleShape rect(sf::Vector2f(120.f, 50.f));
    //    rect.setSize(sf::Vector2f(3,c+1));
    //    double sine=y/c;
    //    rect.setPosition(0,0);

    //    mysz.setSize(sf::Vector2f(1,1));
    //    mysz.setPosition(x,y);
    //    int przypadek;
    //    double rotacja=0;
    //    sf::FloatRect granice = rect.getGlobalBounds();
    //    sf::FloatRect cel = mysz.getGlobalBounds();
    //    std::cout<<granice.top<<std::endl;
    //    std::cout<<cel.top<<std::endl;
    //    if(x>=0&&y>=0){
    //        przypadek=1;
    //    }
    //    if(x>=0&&y<0){
    //        przypadek= 2;
    //    }
    //    if(x<0&&y>=0){
    //        przypadek= 3;
    //    }
    //    if(x<0&&y<0){
    //        przypadek= 4;
    //    }
    //    bool trafiony=false;
    //    double poczatek=90;
    //    double kontener=0;
    //    while (trafiony==false) {
    //        kontener=sin(poczatek);
    //        if(kontener>=(sine-0.1)&&kontener<=(sine+0.1)){
    //           rotacja=poczatek;
    //           term.velocity=poczatek;
    //            trafiony=true;
    //        }
    //        if(kontener>sine){
    //            poczatek=poczatek/2;
    //        }
    //        if (kontener<sine){
    //            poczatek=poczatek+(poczatek/2);
    //        }

    //    }
    //    switch (przypadek) {
    //    case 1:
    //        rotacja=180+rotacja;
    //        term.rotate(rotacja);
    //    case 2:
    //        rotacja=270+rotacja;
    //        term.rotate(rotacja);
    //    case 3:
    //        rotacja=90+rotacja;
    //        term.rotate(rotacja);
    //    case 4:

    //        term.rotate(rotacja);
    //    }
    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //       term.velocity=190* elapsed.asSeconds();
    //       term.rotate(term.velocity);
    //    }
    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //        term.velocity=190* elapsed.asSeconds()*(-1);
    //        term.rotate(term.velocity);
    //    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        ruchY=term.speed*(-1)* elapsed.asSeconds() ;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        ruchY=term.speed* elapsed.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        ruchX=term.speed*(-1)* elapsed.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        ruchX=term.speed* elapsed.asSeconds();
    }
    sf::FloatRect granice = term.getGlobalBounds();
    if (granice.top <= 0) {
        ruchY=0;
    }
    if ((granice.top+granice.height) >= 800) {
        ruchY=0;
    }
    if (granice.left <= 0) {
        ruchX=0;
    }
    if ((granice.left + granice.width) >= 1600) {
        ruchX=0;
    }
    term.move(sf::Vector2f(ruchX,ruchY));
    //std::cout<<term.HP_level<<std::endl;
}
//void atack
void Terminator::get_hit(Terminator&term,sf::RectangleShape&rect){
    sf::FloatRect granice = term.getGlobalBounds();
    if (granice.intersects(rect.getGlobalBounds())) {
        term.HP_level-=50;

    }
}
void Terminator::get_hit_mele(Terminator&term,Hero obiekt){
    float ruchX = 0, ruchY = 0;
    sf::FloatRect granice = term.getGlobalBounds();
    if (granice.intersects(obiekt.getGlobalBounds())) {
        term.HP_level-=100;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            ruchY=20 ;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            ruchY=-20;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            ruchX=20;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            ruchX=-20;
        }
        sf::FloatRect granice = term.getGlobalBounds();
        if (granice.top <= 0) {
            ruchY=0;
        }
        if ((granice.top+granice.height) >= 800) {
            ruchY=0;
        }
        if (granice.left <= 0) {
            ruchX=0;
        }
        if ((granice.left + granice.width) >= 1600) {
            ruchX=0;
        }
        term.move(sf::Vector2f(ruchX,ruchY));
    }
}
