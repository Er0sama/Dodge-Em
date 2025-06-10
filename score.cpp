// 22i-0783    Muhammad Saad Lone  OOP - B
#include "score.h"

score::score()
{
    value = 0;
    ones_tex.loadFromFile("img/0.png");
    ones_sprite.setTexture(ones_tex);
    tens_tex.loadFromFile("img/0.png");
    tens_sprite.setTexture(tens_tex);
    hundreds_tex.loadFromFile("img/0.png");
    hundreds_sprite.setTexture(hundreds_tex);
    thousands_tex.loadFromFile("img/0.png");
    thousands_sprite.setTexture(thousands_tex);
    y1 = 100;
    y2 = 100;   
    y3 = 100;
    y4 = 100;
    x1 = 660;
    x2 = 760;
    x3 = 860;
    x4 = 960;
    ones_sprite.setPosition(x4, y4);
    tens_sprite.setPosition(x3, y3);
    hundreds_sprite.setPosition(x2, y2);
    thousands_sprite.setPosition(x1, y1);
}
int score::get_value()
{
    return value;
}
void score::set_value(int num)
{
    this->value = num;
    sprite_update();
}
Sprite score::get_sprite1()
{
    return ones_sprite;
}
Sprite score::get_sprite2()
{
    return tens_sprite;
}
Sprite score::get_sprite3()
{
    return hundreds_sprite;
}
Sprite score::get_sprite4()
{
    return thousands_sprite;
}
void score::add_value(int x)
{
    value += x;
    sprite_update();
}
void score::deduct_value(int x)
{
    value -= x;
    sprite_update();
}
void score::sprite_update()
{
    if (value <= 9999)
    {
        int thou = value / 1000;
        int hun = (value / 100) % 10;
        int ten = (value / 10) % 10;
        int one = value % 10;

        switch (one)
        {
        case 1:
            ones_tex.loadFromFile("img/1.png");
            ones_sprite.setTexture(ones_tex);
            break;
        case 2:
            ones_tex.loadFromFile("img/2.png");
            ones_sprite.setTexture(ones_tex);
            break;
        case 3:
            ones_tex.loadFromFile("img/3.png");
            ones_sprite.setTexture(ones_tex);
            break;
        case 4:
            ones_tex.loadFromFile("img/4.png");
            ones_sprite.setTexture(ones_tex);
            break;
        case 5:
            ones_tex.loadFromFile("img/5.png");
            ones_sprite.setTexture(ones_tex);
            break;
        case 6:
            ones_tex.loadFromFile("img/6.png");
            ones_sprite.setTexture(ones_tex);
            break;
        case 7:
            ones_tex.loadFromFile("img/7.png");
            ones_sprite.setTexture(ones_tex);
            break;
        case 8:
            ones_tex.loadFromFile("img/8.png");
            ones_sprite.setTexture(ones_tex);
            break;
        case 9:
            ones_tex.loadFromFile("img/9.png");
            ones_sprite.setTexture(ones_tex);
            break;
        default:
            ones_tex.loadFromFile("img/0.png");
            ones_sprite.setTexture(ones_tex);
            break;
        }
        switch (ten)
        {
        case 1:
            tens_tex.loadFromFile("img/1.png");
            tens_sprite.setTexture(tens_tex);
            break;
        case 2:
            tens_tex.loadFromFile("img/2.png");
            tens_sprite.setTexture(tens_tex);
            break;
        case 3:
            tens_tex.loadFromFile("img/3.png");
            tens_sprite.setTexture(tens_tex);
            break;
        case 4:
            tens_tex.loadFromFile("img/4.png");
            tens_sprite.setTexture(tens_tex);
            break;
        case 5:
            tens_tex.loadFromFile("img/5.png");
            tens_sprite.setTexture(tens_tex);
            break;
        case 6:
            tens_tex.loadFromFile("img/6.png");
            tens_sprite.setTexture(tens_tex);
            break;
        case 7:
            tens_tex.loadFromFile("img/7.png");
            tens_sprite.setTexture(tens_tex);
            break;
        case 8:
            tens_tex.loadFromFile("img/8.png");
            tens_sprite.setTexture(tens_tex);
            break;
        case 9:
            tens_tex.loadFromFile("img/9.png");
            tens_sprite.setTexture(tens_tex);
            break;
        default:
            tens_tex.loadFromFile("img/0.png");
            tens_sprite.setTexture(tens_tex);
            break;
        }
        switch (hun)
        {
        case 1:
            hundreds_tex.loadFromFile("img/1.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        case 2:
            hundreds_tex.loadFromFile("img/2.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        case 3:
            hundreds_tex.loadFromFile("img/3.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        case 4:
            hundreds_tex.loadFromFile("img/4.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        case 5:
            hundreds_tex.loadFromFile("img/5.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        case 6:
            hundreds_tex.loadFromFile("img/6.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        case 7:
            hundreds_tex.loadFromFile("img/7.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        case 8:
            hundreds_tex.loadFromFile("img/8.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        case 9:
            hundreds_tex.loadFromFile("img/9.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        default:
            hundreds_tex.loadFromFile("img/0.png");
            hundreds_sprite.setTexture(hundreds_tex);
            break;
        }
        switch (thou)
        {
        case 1:
            thousands_tex.loadFromFile("img/1.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        case 2:
            thousands_tex.loadFromFile("img/2.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        case 3:
            thousands_tex.loadFromFile("img/3.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        case 4:
            thousands_tex.loadFromFile("img/4.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        case 5:
            thousands_tex.loadFromFile("img/5.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        case 6:
            thousands_tex.loadFromFile("img/6.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        case 7:
            thousands_tex.loadFromFile("img/7.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        case 8:
            thousands_tex.loadFromFile("img/8.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        case 9:
            thousands_tex.loadFromFile("img/9.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        default:
            thousands_tex.loadFromFile("img/0.png");
            thousands_sprite.setTexture(thousands_tex);
            break;
        }
    }
}