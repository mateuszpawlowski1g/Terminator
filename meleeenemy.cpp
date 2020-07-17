#include "meleeenemy.h"
#include "cmath"
MeleeEnemy::MeleeEnemy(sf::Texture text):Hero()
{
    speed=120;
}
void MeleeEnemy::auto_pilot(MeleeEnemy &mel,sf::Sprite sp,const sf::Time &elapsed){

    sf::FloatRect granice = sp.getGlobalBounds();
    sf::FloatRect cel = mel.getGlobalBounds();
    double a=granice.left-cel.left;
    double b=granice.top-cel.top;


   double dl =sqrt(a*a+b*b);
   double prop =13/dl;
   if(mel.stop==4||mel.stop==6){
   if(dl<13){
       mel.move(sf::Vector2f(0,b/150));
   }
   else{
       mel.move(sf::Vector2f(0,b*prop/150));
   }
   }
   else if(mel.stop==8||mel.stop==2){
   if(dl<13){
       mel.move(sf::Vector2f(a/150,0));
   }
   else{
       mel.move(sf::Vector2f(a*prop/150,0));
   }
   }
   else{
       if(dl<13){
           mel.move(sf::Vector2f(a/150,b/150));
       }
       else{
           mel.move(sf::Vector2f(a*prop/150,b*prop/150));
       }
   }

}
void MeleeEnemy::sciana(MeleeEnemy&mel,sf::RectangleShape&rect){
    sf::FloatRect mele=mel.getGlobalBounds();
    sf::FloatRect sciana=rect.getGlobalBounds();
    if((mele.top+15)>sciana.top&&mele.top<sciana.top){
        stop=2;
    }
    if((mele.top-15)<(sciana.top+sciana.height)&&(mele.top+5)>(sciana.top+sciana.height)){
        stop=8;
    }
    if((mele.left+15)>sciana.left&&mele.left<sciana.left){
        stop=6;
    }
    if((mele.left-15)<(sciana.left+sciana.width)&&(mele.left+5)>(sciana.left+sciana.width)){
        stop=4;
    }
    //std::cout<<stop<<std::endl;
}
void MeleeEnemy::reset(MeleeEnemy&mel){
    stop=0;
}
