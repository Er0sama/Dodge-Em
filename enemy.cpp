// 22i-0783    Muhammad Saad Lone  OOP - B
#include "enemy.h"

enemy::enemy()
{
}
void enemy::formation(int x, int y)
{
}
Sprite enemy::get_sprite()
{
    return enemy_sprite;
}
void enemy::automovement(int& border)
{
}
bool enemy::smart_movement(int& E_border, int& P_border, int& lvl)
{
    return false;
}
void enemy::change_pos(int x, int y)
{
}
void enemy::set_pos(int x, int y)
{
}
void enemy::change_speed(float speed)
{
}

bool enemy::collision(player*& Player)
{
    return false;
}
void enemy::change_sprite(string path)
{
}

blue_enemy::blue_enemy()
{
}
void blue_enemy::formation(int x, int y)
{
    enemy_texture.loadFromFile("img/enemy_side.png");
    enemy_sprite.setTexture(enemy_texture);
    speed = 0.12;
    enemy_sprite.setPosition(x, y);
}
Sprite blue_enemy::get_sprite()
{
    return enemy_sprite;
}
void blue_enemy::change_pos(int x, int y)
{
    enemy_sprite.move(x, y);
}
void blue_enemy::set_pos(int x, int y)
{
    enemy_sprite.setPosition(x, y);
}

void blue_enemy::change_sprite(string path)
{
    enemy_texture.loadFromFile(path);
    enemy_sprite.setTexture(enemy_texture);
}
void blue_enemy::change_speed(float speed)
{
    this->speed = speed;
}

void blue_enemy::automovement(int& border)
{

    float delta_x = 0, delta_y = 0;
    if (enemy_sprite.getPosition().x > 0)
        switch (border)
        {
        case 1:

            if ((enemy_sprite.getPosition().x > 390 && enemy_sprite.getPosition().x <= 710) && enemy_sprite.getPosition().y == 290)
            {
                delta_x = -1;
            }
            else if ((enemy_sprite.getPosition().x < 710 && enemy_sprite.getPosition().x >= 390) && enemy_sprite.getPosition().y == 385)
            {
                delta_x = +1;
            }
            else if (enemy_sprite.getPosition().x == 710 && (enemy_sprite.getPosition().y <= 385 && enemy_sprite.getPosition().y > 290))
            {
                delta_y = -1;
            }
            else if (enemy_sprite.getPosition().x == 390 && (enemy_sprite.getPosition().y >= 290 && enemy_sprite.getPosition().y < 385))
            {
                delta_y = +1;
            }

            delta_x *= speed;
            delta_y *= speed;
            // cout << player_sprite.getPosition().x << " " << player_sprite.getPosition().y << endl;
            if (enemy_sprite.getPosition().x > 710)
            {
                delta_x = -(enemy_sprite.getPosition().x - 710);
                enemy_texture.loadFromFile("img/enemy_straight.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().y > 385)
            {
                delta_y = -(enemy_sprite.getPosition().y - 385);
                enemy_texture.loadFromFile("img/enemy_side.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().x < 390)
            {
                delta_x = -(enemy_sprite.getPosition().x - 390);
                enemy_texture.loadFromFile("img/enemy_straight.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().y < 290)
            {
                delta_y = -(enemy_sprite.getPosition().y - 290);
                enemy_texture.loadFromFile("img/enemy_side.png");
                enemy_sprite.setTexture(enemy_texture);
            }

            enemy_sprite.move(delta_x, delta_y);
            break;
        case 2:

            if ((enemy_sprite.getPosition().x > 282 && enemy_sprite.getPosition().x <= 818) && enemy_sprite.getPosition().y == 245)
            {
                delta_x = -1;
            }
            else if ((enemy_sprite.getPosition().x < 818 && enemy_sprite.getPosition().x >= 282) && enemy_sprite.getPosition().y == 430)
            {
                delta_x = +1;
            }
            else if (enemy_sprite.getPosition().x == 818 && (enemy_sprite.getPosition().y <= 430 && enemy_sprite.getPosition().y > 245))
            {
                delta_y = -1;
            }
            else if (enemy_sprite.getPosition().x == 282 && (enemy_sprite.getPosition().y >= 245 && enemy_sprite.getPosition().y < 430))
            {
                delta_y = +1;
            }

            delta_x *= speed;
            delta_y *= speed;
            // cout << player_sprite.getPosition().x << " " << player_sprite.getPosition().y << endl;
            if (enemy_sprite.getPosition().x > 818)
            {
                delta_x = -(enemy_sprite.getPosition().x - 818);
                enemy_texture.loadFromFile("img/enemy_straight.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().y > 430)
            {
                delta_y = -(enemy_sprite.getPosition().y - 430);
                enemy_texture.loadFromFile("img/enemy_side.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().x < 282)
            {
                delta_x = -(enemy_sprite.getPosition().x - 282);
                enemy_texture.loadFromFile("img/enemy_straight.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().y < 245)
            {
                delta_y = -(enemy_sprite.getPosition().y - 245);
                enemy_texture.loadFromFile("img/enemy_side.png");
                enemy_sprite.setTexture(enemy_texture);
            }

            enemy_sprite.move(delta_x, delta_y);
            break;
        case 3:

            if ((enemy_sprite.getPosition().x > 174 && enemy_sprite.getPosition().x <= 926) && enemy_sprite.getPosition().y == 200)
            {
                delta_x = -1;
            }
            else if ((enemy_sprite.getPosition().x < 926 && enemy_sprite.getPosition().x >= 174) && enemy_sprite.getPosition().y == 475)
            {
                delta_x = +1;
            }
            else if (enemy_sprite.getPosition().x == 926 && (enemy_sprite.getPosition().y <= 475 && enemy_sprite.getPosition().y > 200))
            {
                delta_y = -1;
            }
            else if (enemy_sprite.getPosition().x == 174 && (enemy_sprite.getPosition().y >= 200 && enemy_sprite.getPosition().y < 475))
            {
                delta_y = +1;
            }

            delta_x *= speed;
            delta_y *= speed;
            // cout << player_sprite.getPosition().x << " " << player_sprite.getPosition().y << endl;
            if (enemy_sprite.getPosition().x > 926)
            {
                delta_x = -(enemy_sprite.getPosition().x - 926);
                enemy_texture.loadFromFile("img/enemy_straight.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().y > 475)
            {
                delta_y = -(enemy_sprite.getPosition().y - 475);
                enemy_texture.loadFromFile("img/enemy_side.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().x < 174)
            {
                delta_x = -(enemy_sprite.getPosition().x - 174);
                enemy_texture.loadFromFile("img/enemy_straight.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().y < 200)
            {
                delta_y = -(enemy_sprite.getPosition().y - 200);
                enemy_texture.loadFromFile("img/enemy_side.png");
                enemy_sprite.setTexture(enemy_texture);
            }

            enemy_sprite.move(delta_x, delta_y);
            break;
        case 4:

            if ((enemy_sprite.getPosition().x > 66 && enemy_sprite.getPosition().x <= 1034) && enemy_sprite.getPosition().y == 155)
            {
                delta_x = -1;
            }
            else if ((enemy_sprite.getPosition().x < 1034 && enemy_sprite.getPosition().x >= 66) && enemy_sprite.getPosition().y == 520)
            {
                delta_x = +1;
            }
            else if (enemy_sprite.getPosition().x == 1034 && (enemy_sprite.getPosition().y <= 520 && enemy_sprite.getPosition().y > 155))
            {
                delta_y = -1;
            }
            else if (enemy_sprite.getPosition().x == 66 && (enemy_sprite.getPosition().y >= 155 && enemy_sprite.getPosition().y < 520))
            {
                delta_y = +1;
            }

            delta_x *= speed;
            delta_y *= speed;
            // cout << enemy_sprite.getPosition().x << " " << enemy_sprite.getPosition().y << endl;
            if (enemy_sprite.getPosition().x > 1034)
            {
                delta_x = -(enemy_sprite.getPosition().x - 1034);
                enemy_texture.loadFromFile("img/enemy_straight.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().y > 520)
            {
                delta_y = -(enemy_sprite.getPosition().y - 520);
                enemy_texture.loadFromFile("img/enemy_side.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().x < 66)
            {
                delta_x = -(enemy_sprite.getPosition().x - 66);
                enemy_texture.loadFromFile("img/enemy_straight.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            if (enemy_sprite.getPosition().y < 155)
            {
                delta_y = -(enemy_sprite.getPosition().y - 155);
                enemy_texture.loadFromFile("img/enemy_side.png");
                enemy_sprite.setTexture(enemy_texture);
            }
            enemy_sprite.move(delta_x, delta_y);
            break;
        default:
            break;
        }
}
bool blue_enemy::smart_movement(int& E_border, int& P_border, int& lvl)
{
    if (enemy_sprite.getPosition().y > 315 && enemy_sprite.getPosition().y < 350)
    {
        if (P_border < E_border)
        {
            switch (E_border)
            {
            case 4:
                E_border--;
                if (enemy_sprite.getPosition().x == 1034)
                {
                    enemy_sprite.move(-108, 0);
                }
                else if (enemy_sprite.getPosition().x == 66)
                {
                    enemy_sprite.move(108, 0);
                }
                return true;
                break;

            case 3:
                E_border--;
                if (enemy_sprite.getPosition().x == 926)
                {
                    enemy_sprite.move(-108, 0);
                }
                else if (enemy_sprite.getPosition().x == 174)
                {
                    enemy_sprite.move(108, 0);
                }
                return true;
                break;
            case 2:
                E_border--;
                if (enemy_sprite.getPosition().x == 818)
                {
                    enemy_sprite.move(-108, 0);
                }
                else if (enemy_sprite.getPosition().x == 282)
                {
                    enemy_sprite.move(108, 0);
                }
                return true;
                break;
            }
        }
        else if (P_border > E_border)
        {
            switch (E_border)
            {
            case 1:
                E_border++;
                if (enemy_sprite.getPosition().x == 390)
                {
                    enemy_sprite.move(-108, 0);
                }
                else if (enemy_sprite.getPosition().x == 710)
                {
                    enemy_sprite.move(108, 0);
                }
                return true;
                break;
            case 2:
                E_border++;
                if (enemy_sprite.getPosition().x == 282)
                {
                    enemy_sprite.move(-108, 0);
                }
                else if (enemy_sprite.getPosition().x == 818)
                {
                    enemy_sprite.move(108, 0);
                }
                return true;
                break;
            case 3:
                E_border++;
                if (enemy_sprite.getPosition().x == 174)
                {
                    enemy_sprite.move(-108, 0);
                }
                else if (enemy_sprite.getPosition().x == 926)
                {
                    enemy_sprite.move(108, 0);
                }
                return true;
                break;
            }
        }
    }

    if (lvl > 1)
        if (enemy_sprite.getPosition().x > 510 && enemy_sprite.getPosition().x < 580)
        {
            if (P_border < E_border)
            {
                switch (E_border)
                {
                case 4:
                    E_border--;
                    if (enemy_sprite.getPosition().y == 520)
                    {
                        enemy_sprite.move(0, -45);
                    }
                    else if (enemy_sprite.getPosition().y == 155)
                    {
                        enemy_sprite.move(0, 45);
                    }
                    return true;
                    break;

                case 3:
                    E_border--;
                    if (enemy_sprite.getPosition().y == 475)
                    {
                        enemy_sprite.move(0, -45);
                    }
                    else if (enemy_sprite.getPosition().y == 200)
                    {
                        enemy_sprite.move(0, 45);
                    }
                    return true;
                    break;
                case 2:
                    E_border--;
                    if (enemy_sprite.getPosition().y == 430)
                    {
                        enemy_sprite.move(0, -45);
                    }
                    else if (enemy_sprite.getPosition().y == 245)
                    {
                        enemy_sprite.move(0, 45);
                    }
                    return true;
                    break;
                }
            }
            else if (P_border > E_border)
            {
                switch (E_border)
                {
                case 1:
                    E_border++;
                    if (enemy_sprite.getPosition().y == 290)
                    {
                        enemy_sprite.move(0, -45);
                    }
                    else if (enemy_sprite.getPosition().y == 385)
                    {
                        enemy_sprite.move(0, 45);
                    }
                    return true;
                    break;

                case 3:
                    E_border++;
                    if (enemy_sprite.getPosition().y == 475)
                    {
                        enemy_sprite.move(0, 45);
                    }
                    else if (enemy_sprite.getPosition().y == 200)
                    {
                        enemy_sprite.move(0, -45);
                    }
                    return true;
                    break;
                case 2:
                    E_border++;
                    if (enemy_sprite.getPosition().y == 430)
                    {
                        enemy_sprite.move(0, 45);
                    }
                    else if (enemy_sprite.getPosition().y == 245)
                    {
                        enemy_sprite.move(0, -45);
                    }
                    return true;
                    break;
                }
            }
        }
    return false;
}
bool blue_enemy::collision(player*& Player)
{
    if ((Player->get_sprite().getPosition().x - enemy_sprite.getPosition().x == 0 || (Player->get_sprite().getPosition().x - enemy_sprite.getPosition().x < 50 && Player->get_sprite().getPosition().x - enemy_sprite.getPosition().x > -50)) && (Player->get_sprite().getPosition().y - enemy_sprite.getPosition().y == 0 || (Player->get_sprite().getPosition().y - enemy_sprite.getPosition().y < 30 && Player->get_sprite().getPosition().y - enemy_sprite.getPosition().y > -30)))
    {
        return true;
    }

    return false;
}
