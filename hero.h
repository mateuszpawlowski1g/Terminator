Class Hero
{
 int HP_level;
 int Max_Hp;
 double speed;
 double pos_x;
 double pos_y;
 double DMG;
 double atack_ratio;
 public:
 void move();
 virtual void atack();
 virtual void get_hit();
}
