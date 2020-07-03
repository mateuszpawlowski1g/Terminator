#include "button.h"

Button::Button(sf::Texture text):Map( text)
{
HP=10;
}
bool Button::get_hit(Button&but,sf::RectangleShape&rect){
    sf::FloatRect granice = but.getGlobalBounds();
    if(granice.intersects(rect.getGlobalBounds())){
        but.HP--;
    }
    if(HP==0){
        return false;
    }
    return  true;
}
