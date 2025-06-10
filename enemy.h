#pragma once
// 22i-0783    Muhammad Saad Lone  OOP - B
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "player.h"
using namespace std;
using namespace sf;

class enemy
{
protected:
	Texture enemy_texture;
	Sprite enemy_sprite;
	float speed;



public:
	enemy();
	virtual void formation(int x,int y);
	virtual Sprite get_sprite();
	virtual void automovement(int& border);
	virtual bool smart_movement(int& E_border , int& P_border, int& lvl);
	virtual void change_pos(int x, int y);
	virtual void set_pos(int x, int y);
	virtual bool collision(player*& Player);
	virtual void change_sprite(string path);
	virtual void change_speed(float speed);
};

class blue_enemy : public enemy
{
public:
	blue_enemy();
	void formation(int x,int y);
	Sprite get_sprite();
	void automovement(int& border);
    bool smart_movement(int& E_border, int& P_border, int& lvl);
	void change_pos(int x, int y);
	void set_pos(int x, int y);
	virtual bool collision(player*& Player);
	void change_sprite(string path);
	void change_speed(float speed);
};