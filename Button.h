#ifndef BUTTON_H
#define BUTTON_H
#include "map.h"

class Button : public Map
{
    double HP;
      public:
      Button(sf::Texture text);
      bool get_hit(Button&but,sf::RectangleShape&rect);
};

#endif // BUTTON_H
