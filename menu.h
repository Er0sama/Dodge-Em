// 22i-0783    Muhammad Saad Lone  OOP - B
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
using namespace sf;

class Menu
{
public:
    Texture menu_texture;
    Sprite menu_sprite;
    int choice;

    // add menu attributes here
    Menu(string png)
    {
        menu_texture.loadFromFile(png);
        menu_sprite.setTexture(menu_texture);
        // menu_sprite.setScale(0.9, 1);
        choice = 0;
    }
    bool display_menu(RenderWindow& window, bool& exit)
    {
        while (window.isOpen())
        {
            Event menu;
            while (window.pollEvent(menu))
            {
                if (menu.type == Event::Closed)
                    window.close();
                if (menu.type == Event::KeyPressed)
                {
                    if (menu.key.code == Keyboard::Num1)
                        choice = 1;
                    else if (menu.key.code == Keyboard::Num2)
                        choice = 2;
                    else if (menu.key.code == Keyboard::Num3)
                        choice = 3;
                    else if (menu.key.code == Keyboard::Num4)
                        choice = 4;
                }
            }
            switch (choice)
            {
            case 1:

                choice = 0;
                return true;
                break;
            case 3:

                this->Show_Help(window);
                choice = 0;
                break;
            case 2:

                this->show_high_scores(window);
                choice = 0;
                break;
            case 4:

                exit = true;
                return true;
                break;
            default:
                break;
            }
            window.draw(menu_sprite);
            window.display();
        }
        return false;
    }
    bool pause_menu(RenderWindow& window, bool& Continue, bool& exit)
    {
        Texture tex_menu;
        tex_menu.loadFromFile("img/pause.png");
        Sprite sprite_menu;
        sprite_menu.setTexture(tex_menu);

        while (window.isOpen())
        {
            Event n;
            while (window.pollEvent(n))
            {
                if (n.type == Event::Closed)
                    window.close();
                if (n.type == Event::KeyPressed)
                {
                    if (n.key.code == Keyboard::Num1)
                        choice = 1;
                    else if (n.key.code == Keyboard::Num2)
                        choice = 2;
                    else if (n.key.code == Keyboard::Num3)
                        choice = 3;
                    else if (n.key.code == Keyboard::Num4)
                        choice = 4;
                    else if (n.key.code == Keyboard::Num5)
                        choice = 5;
                }
            }
            switch (choice)
            {
            case 5:
                Continue = true;
                choice = 0;
                return false;
                break;
            case 1:
                Continue = false;
                choice = 0;
                return true;
                break;
            case 3:
                this->Show_Help(window);
                choice = 0;
                break;

            case 2:
                this->show_high_scores(window);
                choice = 0;
                break;
            case 4:
                Continue = true;
                exit = true;
                choice = 0;
                return false;
                break;
            default:
                break;
            }
            window.draw(sprite_menu);
            window.display();
        }

        return false;
    }
    void Show_Help(RenderWindow& window)
    {
        Texture tex_help;
        tex_help.loadFromFile("img/help.png");
        Sprite sprite_help;
        sprite_help.setTexture(tex_help);

        while (window.isOpen())
        {
            Event h;
            while (window.pollEvent(h))
            {
                if (h.type == Event::Closed)
                    window.close();
                if (h.type == Event::KeyPressed)
                {
                    if (h.key.code == Keyboard::Num1 || h.key.code == Keyboard::Escape)
                        return;
                }
            }
            window.draw(sprite_help);
            window.display();
        }
    }

    bool game_over(RenderWindow& window, bool& Continue, bool& exit)
    {
        Texture tex_over;
        tex_over.loadFromFile("img/over.png");
        Sprite sprite_over;
        sprite_over.setTexture(tex_over);

        while (window.isOpen())
        {
            Event n;
            while (window.pollEvent(n))
            {
                if (n.type == Event::Closed)
                    window.close();
                if (n.type == Event::KeyPressed)
                {
                    if (n.key.code == Keyboard::Num1)
                        choice = 1;
                    else if (n.key.code == Keyboard::Num2)
                        choice = 2;
                }
            }
            switch (choice)
            {
            case 1:
                Continue = false;
                choice = 0;
                return true;
                break;

            case 2:
                Continue = true;
                exit = true;
                choice = 0;
                return false;
                break;
            default:
                break;
            }
            window.draw(sprite_over);
            window.display();
        }

        return false;
    }

    bool game_won(RenderWindow& window)
    {
        Texture tex_over;
        tex_over.loadFromFile("img/won.png");
        Sprite sprite_over;
        sprite_over.setTexture(tex_over);
        bool click = false;
        while (window.isOpen())
        {
            Event n;
            while (window.pollEvent(n))
            {
                if (n.type == Event::Closed)
                    window.close();
                if (n.type == Event::KeyPressed)
                {
                    click = true;
                    break;
                }
            }

            if (click)
                return true;

            window.draw(sprite_over);
            window.display();
        }

        return false;
    }

    void show_high_scores(RenderWindow& window)
    {



    }
};
