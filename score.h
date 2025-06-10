#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
// 22i-0783    Muhammad Saad Lone  OOP - B
#include <string.h>
#include "lives.h"
using namespace std;
using namespace sf;

class score
{
	Texture ones_tex;
	Sprite ones_sprite;
	Texture tens_tex;
	Sprite tens_sprite;
	Texture hundreds_tex;
	Sprite hundreds_sprite;
	Texture thousands_tex;
	Sprite thousands_sprite;
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int value;

public:

	score();
	Sprite get_sprite1();
	Sprite get_sprite2();
	Sprite get_sprite3();
	Sprite get_sprite4();
	int get_value();
	void set_value(int num);
	void add_value(int x);
	void deduct_value(int x);
	void sprite_update();
};