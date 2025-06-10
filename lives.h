// 22i-0783    Muhammad Saad Lone  OOP - B
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace std;
using namespace sf;

class lives
{
	Texture live_tex;
	Sprite  live_sprite;
	int x, y;
	int value;

public:
	lives();
	void set_live(int x);
	int get_value();
	Sprite get_sprite();
	void lives_increment();
	void lives_decrement();
	void image_update();

};