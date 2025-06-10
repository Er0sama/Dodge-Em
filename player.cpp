#include "player.h"

player::player()
{
    player_texture.loadFromFile("img/player_side.png");
    player_sprite.setTexture(player_texture);
    health = new lives;
    scores = new score;
    x = 450;
    y = 520;
    speed = 0.15;
    player_sprite.setPosition(x, y);
    increased = false;
}
Sprite player::get_sprite()
{
    return player_sprite;
}
void player::set_live(int x)
{
    health->set_live(x);
}

Sprite player::get_lives()
{
    return health->get_sprite();
}
int player::get_lifenum()
{
    return health->get_value();
}

bool player::get_increased()
{
    return increased;
}
void player::set_pos(int x, int y)
{
    player_sprite.setPosition(x, y);
}
void player::set_increased(bool x)
{
    increased = x;
}
float player::get_speed()
{
    return speed;
}

void player::change_sprite(string path)
{
    player_texture.loadFromFile(path);
    player_sprite.setTexture(player_texture);
}
void player::change_speed(float spd)
{
    speed = spd;
}
void player::live_decrement()
{
    health->lives_decrement();
}
void player::live_increment()
{
    health->lives_increment();
}
void player::turn(string x, int &border)
{
    if (x == "l")
    {
        if (player_sprite.getPosition().y > 310 && player_sprite.getPosition().y < 350)
        {
            if (border != 4 && border != 1)
            {
                if (player_sprite.getPosition().x == 926 || player_sprite.getPosition().x == 818)
                {
                    border--;
                }
                else if (player_sprite.getPosition().x == 282 || player_sprite.getPosition().x == 174)
                {
                    border++;
                }
                player_sprite.move(-108, 0);
            }
            else if (border == 4)
            {

                if (player_sprite.getPosition().x == 1034)
                {
                    border--;
                    player_sprite.move(-108, 0);
                }
            }
            else if (border == 1)
            {
                if (player_sprite.getPosition().x == 390)
                {
                    border++;
                    player_sprite.move(-108, 0);
                }
            }
        }
    }
    else if (x == "r")
    {
        if (player_sprite.getPosition().y > 310 && player_sprite.getPosition().y < 350)
        {
            if (border != 4 && border != 1)
            {
                if (player_sprite.getPosition().x == 174 || player_sprite.getPosition().x == 282)
                {
                    border--;
                }
                else if (player_sprite.getPosition().x == 818 || player_sprite.getPosition().x == 926)
                {
                    border++;
                }
                player_sprite.move(108, 0);
            }
            else if (border == 4)
            {

                if (player_sprite.getPosition().x == 66)
                {
                    border--;
                    player_sprite.move(108, 0);
                }
            }
            else if (border == 1)
            {
                if (player_sprite.getPosition().x == 710)
                {
                    border++;
                    player_sprite.move(108, 0);
                }
            }
        }
    }
    else if (x == "u")
    {
        if (player_sprite.getPosition().x > 490 && player_sprite.getPosition().x < 590)
        {
            if (border != 4 && border != 1)
            {
                if (player_sprite.getPosition().y == 475 || player_sprite.getPosition().y == 430)
                {
                    border--;
                }
                else if (player_sprite.getPosition().y == 245 || player_sprite.getPosition().y == 200)
                {
                    border++;
                }
                player_sprite.move(0, -45);
            }
            else if (border == 4)
            {

                if (player_sprite.getPosition().y == 520)
                {
                    border--;
                    player_sprite.move(0, -45);
                }
            }
            else if (border == 1)
            {
                if (player_sprite.getPosition().y == 290)
                {
                    border++;
                    player_sprite.move(0, -45);
                }
            }
        }
    }
    else if (x == "d")
    {
        if (player_sprite.getPosition().x > 490 && player_sprite.getPosition().x < 590)
        {
            if (border != 4 && border != 1)
            {
                if (player_sprite.getPosition().y == 200 || player_sprite.getPosition().y == 245)
                {
                    border--;
                }
                else if (player_sprite.getPosition().y == 430 || player_sprite.getPosition().y == 475)
                {
                    border++;
                }
                player_sprite.move(0, 45);
            }
            else if (border == 4)
            {

                if (player_sprite.getPosition().y == 155)
                {
                    border--;
                    player_sprite.move(0, 45);
                }
            }
            else if (border == 1)
            {
                if (player_sprite.getPosition().y == 385)
                {
                    border++;
                    player_sprite.move(0, 45);
                }
            }
        }
    }
}
void player::automovement(int &border)
{
    float delta_x = 0, delta_y = 0;
    switch (border)
    {
    case 1:

        if ((player_sprite.getPosition().x >= 390 && player_sprite.getPosition().x < 710) && player_sprite.getPosition().y == 290)
        {
            delta_x = +1;
        }
        else if ((player_sprite.getPosition().x <= 710 && player_sprite.getPosition().x > 390) && player_sprite.getPosition().y == 385)
        {
            delta_x = -1;
        }
        else if (player_sprite.getPosition().x == 390 && (player_sprite.getPosition().y <= 385 && player_sprite.getPosition().y > 290))
        {
            delta_y = -1;
        }
        else if (player_sprite.getPosition().x == 710 && (player_sprite.getPosition().y >= 290 && player_sprite.getPosition().y < 385))
        {
            delta_y = +1;
        }

        delta_x *= speed;
        delta_y *= speed;
        // cout << player_sprite.getPosition().x << " " << player_sprite.getPosition().y << endl;
        if (player_sprite.getPosition().x > 710)
        {
            delta_x = -(player_sprite.getPosition().x - 710);
            player_texture.loadFromFile("img/player_straight.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().y > 385)
        {
            delta_y = -(player_sprite.getPosition().y - 385);
            player_texture.loadFromFile("img/player_side.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().x < 390)
        {
            delta_x = -(player_sprite.getPosition().x - 390);
            player_texture.loadFromFile("img/player_straight.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().y < 290)
        {
            delta_y = -(player_sprite.getPosition().y - 290);
            player_texture.loadFromFile("img/player_side.png");
            player_sprite.setTexture(player_texture);
        }

        player_sprite.move(delta_x, delta_y);
        break;
    case 2:

        if ((player_sprite.getPosition().x >= 282 && player_sprite.getPosition().x < 818) && player_sprite.getPosition().y == 245)
        {
            delta_x = +1;
        }
        else if ((player_sprite.getPosition().x <= 818 && player_sprite.getPosition().x > 282) && player_sprite.getPosition().y == 430)
        {
            delta_x = -1;
        }
        else if (player_sprite.getPosition().x == 282 && (player_sprite.getPosition().y <= 430 && player_sprite.getPosition().y > 245))
        {
            delta_y = -1;
        }
        else if (player_sprite.getPosition().x == 818 && (player_sprite.getPosition().y >= 245 && player_sprite.getPosition().y < 430))
        {
            delta_y = +1;
        }

        delta_x *= speed;
        delta_y *= speed;
        // cout << player_sprite.getPosition().x << " " << player_sprite.getPosition().y << endl;
        if (player_sprite.getPosition().x > 818)
        {
            delta_x = -(player_sprite.getPosition().x - 818);
            player_texture.loadFromFile("img/player_straight.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().y > 430)
        {
            delta_y = -(player_sprite.getPosition().y - 430);
            player_texture.loadFromFile("img/player_side.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().x < 282)
        {
            delta_x = -(player_sprite.getPosition().x - 282);
            player_texture.loadFromFile("img/player_straight.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().y < 245)
        {
            delta_y = -(player_sprite.getPosition().y - 245);
            player_texture.loadFromFile("img/player_side.png");
            player_sprite.setTexture(player_texture);
        }

        player_sprite.move(delta_x, delta_y);
        break;
    case 3:

        if ((player_sprite.getPosition().x >= 174 && player_sprite.getPosition().x < 926) && player_sprite.getPosition().y == 200)
        {
            delta_x = +1;
        }
        else if ((player_sprite.getPosition().x <= 926 && player_sprite.getPosition().x > 174) && player_sprite.getPosition().y == 475)
        {
            delta_x = -1;
        }
        else if (player_sprite.getPosition().x == 174 && (player_sprite.getPosition().y <= 475 && player_sprite.getPosition().y > 200))
        {
            delta_y = -1;
        }
        else if (player_sprite.getPosition().x == 926 && (player_sprite.getPosition().y >= 200 && player_sprite.getPosition().y < 475))
        {
            delta_y = +1;
        }

        delta_x *= speed;
        delta_y *= speed;
        // cout << player_sprite.getPosition().x << " " << player_sprite.getPosition().y << endl;
        if (player_sprite.getPosition().x > 926)
        {
            delta_x = -(player_sprite.getPosition().x - 926);
            player_texture.loadFromFile("img/player_straight.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().y > 475)
        {
            delta_y = -(player_sprite.getPosition().y - 475);
            player_texture.loadFromFile("img/player_side.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().x < 174)
        {
            delta_x = -(player_sprite.getPosition().x - 174);
            player_texture.loadFromFile("img/player_straight.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().y < 200)
        {
            delta_y = -(player_sprite.getPosition().y - 200);
            player_texture.loadFromFile("img/player_side.png");
            player_sprite.setTexture(player_texture);
        }

        player_sprite.move(delta_x, delta_y);
        break;
    case 4:

        if ((player_sprite.getPosition().x >= 66 && player_sprite.getPosition().x < 1034) && player_sprite.getPosition().y == 155)
        {
            delta_x = +1;
        }
        else if ((player_sprite.getPosition().x <= 1034 && player_sprite.getPosition().x > 66) && player_sprite.getPosition().y == 520)
        {
            delta_x = -1;
        }
        else if (player_sprite.getPosition().x == 66 && (player_sprite.getPosition().y <= 520 && player_sprite.getPosition().y > 155))
        {
            delta_y = -1;
        }
        else if (player_sprite.getPosition().x == 1034 && (player_sprite.getPosition().y >= 155 && player_sprite.getPosition().y < 520))
        {
            delta_y = +1;
        }

        delta_x *= speed;
        delta_y *= speed;
        //  cout << player_sprite.getPosition().x << " " << player_sprite.getPosition().y << endl;
        if (player_sprite.getPosition().x > 1034)
        {
            delta_x = -(player_sprite.getPosition().x - 1034);
            player_texture.loadFromFile("img/player_straight.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().y > 520)
        {
            delta_y = -(player_sprite.getPosition().y - 520);
            player_texture.loadFromFile("img/player_side.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().x < 66)
        {
            delta_x = -(player_sprite.getPosition().x - 66);
            player_texture.loadFromFile("img/player_straight.png");
            player_sprite.setTexture(player_texture);
        }
        if (player_sprite.getPosition().y < 155)
        {
            delta_y = -(player_sprite.getPosition().y - 155);
            player_texture.loadFromFile("img/player_side.png");
            player_sprite.setTexture(player_texture);
        }
        player_sprite.move(delta_x, delta_y);
        break;
    default:
        break;
    }
}

Sprite player::get_sprite1()
{
    return scores->get_sprite1();
}
Sprite player::get_sprite2()
{
    return scores->get_sprite2();
}
Sprite player::get_sprite3()
{
    return scores->get_sprite3();
}
Sprite player::get_sprite4()
{
    return scores->get_sprite4();
}
int player::get_value()
{
    return scores->get_value();
}
void player::set_value(int num)
{
    scores->set_value(num);
}
void player::add_value(int x)
{
    scores->add_value(x);
}

player::~player()
{
    delete health;
    health = nullptr;
    delete scores;
    scores = nullptr;
}