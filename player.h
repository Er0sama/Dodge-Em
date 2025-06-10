#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "score.h"
#include "lives.h"
using namespace std;
using namespace sf;

class player
{
	Texture player_texture;
	Sprite player_sprite;
	float speed;
	lives*  health;
	int x, y;
	bool increased;
	score* scores;
	// 22i-0783    Muhammad Saad Lone  OOP - B
public:
	player();
	int get_lifenum();
	Sprite get_sprite();
	Sprite get_lives();
	void set_live(int x);
	bool get_increased();
	void set_increased(bool x);
	void automovement(int &border);
	void turn(string x,int &border);
	void live_decrement();
	void live_increment();
	void change_speed(float spd);
	float get_speed();
	void set_pos(int x, int y);
	void change_sprite(string path);
	Sprite get_sprite1();
	Sprite get_sprite2();
	Sprite get_sprite3();
	Sprite get_sprite4();
	int get_value();
	void set_value(int num);
	void add_value(int x);
	~player();
};
