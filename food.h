#pragma once
// 22i-0783    Muhammad Saad Lone  OOP - B
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "score.h"
#include "player.h"
#include "enemy.h"

using namespace std;
using namespace sf;

class food
{

public:
    virtual Sprite get_sprite() = 0;
    virtual void formation(int& x, int& y) = 0;
    virtual bool food_player_collision(player*& Player) = 0;
    virtual void add_points(player*& Player) = 0;
    virtual void extra_live(player*& Player) {}
    virtual bool increase_speed(player*& Player) { return false; }
    virtual bool enemy_disappear(enemy*& Enemy, int& x, int& y) { return false; }
};

class Redfood : public food
{
public:
    Texture food_tex;
    Sprite food_sprite;
    int food_score;
    // int no_food;

    Redfood()
    {
    }

    void formation(int& x, int& y)
    {

        food_tex.loadFromFile("img/red.png");
        food_sprite.setTexture(food_tex);
        food_score = 10;
        food_sprite.setPosition(x, y);
    }
    Sprite get_sprite()
    {
        Sprite temp;
        temp = food_sprite;
        return food_sprite;
    }

    bool food_player_collision(player*& Player)
    {

        // cout << Player->get_sprite().getPosition().x << "   " << Player->get_sprite().getPosition().y << endl;
        if ((Player->get_sprite().getPosition().x - food_sprite.getPosition().x == 0 || (Player->get_sprite().getPosition().x - food_sprite.getPosition().x < 1 && Player->get_sprite().getPosition().x - food_sprite.getPosition().x > -1)) && (Player->get_sprite().getPosition().y - food_sprite.getPosition().y == 0 || (Player->get_sprite().getPosition().y - food_sprite.getPosition().y < 1 && Player->get_sprite().getPosition().y - food_sprite.getPosition().y > -1)))
        {
            return true;
        }
        else
            return false;
    }
    void add_points(player*& Player)
    {
        Player->add_value(food_score);
    }
};

class Greenfood : public food
{
public:
    Texture food_tex;
    Sprite food_sprite;
    int food_score;
    // int no_food;

    Greenfood()
    {
    }

    void formation(int& x, int& y)
    {

        food_tex.loadFromFile("img/green.png");
        food_sprite.setTexture(food_tex);
        food_sprite.setScale(0.4, 0.4);
        food_score = 20;
        food_sprite.setPosition(x, y);
    }
    Sprite get_sprite()
    {
        Sprite temp;
        temp = food_sprite;
        return food_sprite;
    }

    bool food_player_collision(player*& Player)
    {

        // cout << Player->get_sprite().getPosition().x << "   " << Player->get_sprite().getPosition().y << endl;
        if ((Player->get_sprite().getPosition().x - food_sprite.getPosition().x == 0 || (Player->get_sprite().getPosition().x - food_sprite.getPosition().x < 1 && Player->get_sprite().getPosition().x - food_sprite.getPosition().x > -1)) && (Player->get_sprite().getPosition().y - food_sprite.getPosition().y == 0 || (Player->get_sprite().getPosition().y - food_sprite.getPosition().y < 1 && Player->get_sprite().getPosition().y - food_sprite.getPosition().y > -1)))
        {
            return true;
        }
        else
            return false;
    }
    void add_points(player*& Player)
    {
        Player->add_value(food_score);
    }
    void extra_live(player*& Player)
    {
        Player->live_increment();
    }
};

class Orangefood : public food
{
public:
    Texture food_tex;
    Sprite food_sprite;
    int food_score;
    // int no_food;

    Orangefood()
    {
    }

    void formation(int& x, int& y)
    {

        food_tex.loadFromFile("img/orange.png");
        food_sprite.setTexture(food_tex);
        food_sprite.setScale(0.4, 0.4);
        food_score = 10;
        food_sprite.setPosition(x, y);
    }
    Sprite get_sprite()
    {
        Sprite temp;
        temp = food_sprite;
        return food_sprite;
    }

    bool food_player_collision(player*& Player)
    {

        // cout << Player->get_sprite().getPosition().x << "   " << Player->get_sprite().getPosition().y << endl;
        if ((Player->get_sprite().getPosition().x - food_sprite.getPosition().x == 0 || (Player->get_sprite().getPosition().x - food_sprite.getPosition().x < 1 && Player->get_sprite().getPosition().x - food_sprite.getPosition().x > -1)) && (Player->get_sprite().getPosition().y - food_sprite.getPosition().y == 0 || (Player->get_sprite().getPosition().y - food_sprite.getPosition().y < 1 && Player->get_sprite().getPosition().y - food_sprite.getPosition().y > -1)))
        {
            return true;
        }
        else
            return false;
    }
    void add_points(player*& Player)
    {
        Player->add_value(food_score);
    }

    bool increase_speed(player*& Player)
    {
        float new_speed = Player->get_speed() * 1.5;
        Player->change_speed(new_speed);
        return true;
    }
};

class Whitefood : public food
{
public:
    Texture food_tex;
    Sprite food_sprite;
    int food_score;

    // int no_food;

    Whitefood()
    {
    }

    void formation(int& x, int& y)
    {

        food_tex.loadFromFile("img/white.png");
        food_sprite.setTexture(food_tex);
        food_sprite.setScale(0.4, 0.4);
        food_sprite.setPosition(x, y);
        food_score = 0;
    }
    Sprite get_sprite()
    {
        Sprite temp;
        temp = food_sprite;
        return food_sprite;
    }

    bool food_player_collision(player*& Player)
    {

        // cout << Player->get_sprite().getPosition().x << "   " << Player->get_sprite().getPosition().y << endl;
        if ((Player->get_sprite().getPosition().x - food_sprite.getPosition().x == 0 || (Player->get_sprite().getPosition().x - food_sprite.getPosition().x < 1 && Player->get_sprite().getPosition().x - food_sprite.getPosition().x > -1)) && (Player->get_sprite().getPosition().y - food_sprite.getPosition().y == 0 || (Player->get_sprite().getPosition().y - food_sprite.getPosition().y < 1 && Player->get_sprite().getPosition().y - food_sprite.getPosition().y > -1)))
        {
            return true;
        }
        else
            return false;
    }

    void add_points(player*& Player)
    {
        Player->add_value(food_score);
    }

    bool enemy_disappear(enemy*& Enemy, int& x, int& y)
    {
        x = -5000;
        y = -5000;
        Enemy->change_pos(x, y);
        return true;
    }
};