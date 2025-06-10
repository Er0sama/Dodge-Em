// 22i-0783    Muhammad Saad Lone  OOP - B
#include "lives.h"

lives::lives()
{
    value = 3;
    live_tex.loadFromFile("img/live_3.png");
    live_sprite.setTexture(live_tex);
    x = 410;
    y = 100;
    live_sprite.setPosition(x, y);
}
int lives::get_value()
{
    return value;
}
void lives::set_live(int x)
{
    this->value = x;
    image_update();
}
Sprite lives::get_sprite()
{
    return live_sprite;
}
void lives::lives_increment()
{
    if (value < 3)
        value++;
    image_update();
}
void lives::lives_decrement()
{
    if (value > 0)
        value--;
    image_update();
}
void lives::image_update()
{
    // cout << value << endl;
    switch (value)
    {
    case 1:
        live_tex.loadFromFile("img/live_1.png");
        live_sprite.setTexture(live_tex);

        break;

    case 2:
        live_tex.loadFromFile("img/live_2.png");
        live_sprite.setTexture(live_tex);
        break;

    case 3:
        live_tex.loadFromFile("img/live_3.png");
        live_sprite.setTexture(live_tex);
        break;

    default:
        break;
    }
}
