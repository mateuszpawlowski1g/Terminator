#ifndef BUTTON_H
#define BUTTON_H
#include "map.h"

class Button : public Map
{
    double HP;
      public:
      Button();
      void get_hit();
};

#endif // BUTTON_H
