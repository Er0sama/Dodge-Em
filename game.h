// 22i-0783    Muhammad Saad Lone  OOP - B
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "player.h"
#include "food.h"
#include "enemy.h"
#include "score.h"
using namespace std;
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{

public:
    Sprite background; // Game background sprite
    Texture bg_texture;

    Menu *menu;
    bool check_start_game = false; // Bool to check Start New Game
    bool exit = false;             // Bool to check game End
    bool exit_game = false;        // Bool to check Game Quit
    bool Continue = false;         // Bool to check Continue game

    player *Player;
    enemy *Enemy;
    enemy *Enemy2;

    int redfood_num;   // Number of different Foods
    int greenfood_num; // that are going to be spawned in the game.
    int yellowfood_num;
    int orangefood_num;
    int whitefood_num;
    food *redfood[60];
    food *greenfood[5];  // array of pointers of parent class that are going to point
    food *orangefood[5]; // towards the derived classes and call virtual functions
    food *whitefood[5];
    // score* scores;
    int border_player;
    int border_enemy;
    int border_enemy2;

    int game_lvl; // Game lvl

    bool form;
    int x, y;
    bool spd_increase; // Bool to check if players speed is increased
    bool disappear;    // Bool to check if enemy is disappeared
    int destroyed;     // Bool to check if all food in eaten
    bool move, move2;
    bool collision, collision2; // bool to check which enemy is colliding with player
    int temp_score;             // temporary score in case round is restarted

    Game()
    {
        menu = new Menu("img/main.png");
        bg_texture.loadFromFile("img/lol.png");
        background.setTexture(bg_texture);
    }

    void start_game()
    {
        // Different sound effects , self explanatory

        Music menu_sound;
        menu_sound.openFromFile("sound/Underwater_Theme.mp3");

        Music lvl_sound;
        lvl_sound.openFromFile("sound/Ground_Theme.mp3");

        Music lvl_sound2;
        lvl_sound2.openFromFile("sound/Ground_Theme(Hurry!).mp3");

        Music life_lost;
        life_lost.openFromFile("sound/Lost_Life.mp3");

        Music game_over;
        game_over.openFromFile("sound/Game_Over.mp3");

        Music coin;
        coin.openFromFile("sound/mario_coin.wav");

        Music power_up;
        power_up.openFromFile("sound/power_up.wav");

        Music won;
        won.openFromFile("sound/cheer.mp3");

        srand(time(0));
        RenderWindow window(VideoMode(1158, 600), title);
        Clock clock, clock_click, clock_click2, clock_spd, clock_disappear, clock_move, clock_move2, clock_roundrestart;
        float timer = 0;
        float time_click = 0, time_click2 = 0;
        float spd = 0;        // Different clocks to track time based actions
        float vanish = 0;     // like player speeding up , enemy disappearing
        float allow_move = 0; // cool down in playe and enemy turns
        float allow_move2 = 0;
        float collide = 0;

        while (window.isOpen())
        {
            if (!check_start_game)
            {
                menu_sound.play();
                check_start_game = menu->display_menu(window, exit_game);
            }
            if (exit_game)
            {
                window.close();
            }
            if (check_start_game)
            {
                menu_sound.stop();
                lvl_sound.play();
                // initializing data members
                Player = new player;
                Enemy = new blue_enemy;
                Enemy2 = nullptr;
                Enemy->formation(650, 520);
                form = true;
                border_player = 4;
                border_enemy = 4;
                border_enemy2 = 3;
                game_lvl = 1;
                redfood_num = 60;
                greenfood_num = 1;
                orangefood_num = 2;
                whitefood_num = 1;
                destroyed = 0;
                spd_increase = false;
                disappear = false;
                move = false;
                move2 = false;
                x = 0;
                y = 0;
                collision = false;
                collision2 = false;
                temp_score = 0;

                while (window.isOpen())
                {
                    float time = clock.getElapsedTime().asSeconds();
                    clock.restart();
                    timer += time;
                    time_click = clock_click.getElapsedTime().asSeconds();
                    time_click2 = clock_click2.getElapsedTime().asSeconds();
                    spd = clock_spd.getElapsedTime().asSeconds();
                    vanish = clock_disappear.getElapsedTime().asSeconds();
                    allow_move = clock_move.getElapsedTime().asSeconds();
                    allow_move2 = clock_move2.getElapsedTime().asSeconds();
                    collide = clock_roundrestart.getElapsedTime().asSeconds();

                    Event e;
                    while (window.pollEvent(e))
                    {
                        if (e.type == Event::Closed)
                            window.close();
                    }
                    if (Keyboard::isKeyPressed(Keyboard::P)) // when game is paused
                    {
                        if (game_lvl == 1 || game_lvl == 2)
                            lvl_sound.stop(); // stops playing music and plays the relevant one
                        else if (game_lvl == 3 || game_lvl == 4)
                            lvl_sound2.stop();
                        menu_sound.play();

                        check_start_game = menu->pause_menu(window, Continue, exit_game);

                        menu_sound.stop();
                        if (!Continue) // If game continue is false then break loop to start a new game
                        {
                            this->save_score(Player->get_value());
                            break;
                        }
                        else if (exit_game) // First saves current score then exits  the game
                        {
                            this->save_score(Player->get_value());
                            window.close();
                            return;
                        }
                        if (game_lvl == 1 || game_lvl == 2)
                            lvl_sound.play();
                        else if (game_lvl == 3 || game_lvl == 4)
                            lvl_sound2.play();
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Left)) // If left key is pressed
                    {
                        if (time_click > 0.5)
                        {
                            clock_click.restart();
                            time_click = 0;
                            Player->turn("l", border_player);
                        }
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                    {
                        if (time_click > 0.5)
                        {
                            clock_click.restart();
                            time_click = 0;
                            Player->turn("r", border_player);
                        }
                    } // player will move to right
                    if (Keyboard::isKeyPressed(Keyboard::Up)) // If up key is pressed
                    {
                        if (time_click2 > 0.5)
                        {
                            clock_click2.restart();
                            time_click2 = 0;
                            Player->turn("u", border_player);
                        }
                    } // playet will move upwards
                    if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
                    {
                        if (time_click2 > 0.5)
                        {
                            clock_click2.restart();
                            time_click2 = 0;
                            Player->turn("d", border_player);
                        }
                    }
                    if (!collision && !collision2) // when collison occurs players and enemy cannnot move
                    {
                        Player->automovement(border_player);
                        //  if (Enemy != nullptr)
                        Enemy->automovement(border_enemy);
                        if (Enemy2 != nullptr)
                            Enemy2->automovement(border_enemy2);
                    }
                    if (!move)
                        if (Enemy->smart_movement(border_enemy, border_player, game_lvl)) // Enemy movement cool down to make
                        {                                                                 // it seem realistic
                            move = true;
                            clock_move.restart();
                            allow_move = 0;
                        }
                    if (move)
                        if (allow_move > 4)
                        {
                            move = false;
                        }
                    if (!move2) // cool down for 2nd enemy
                        if (Enemy2 != nullptr)
                            if (Enemy2->smart_movement(border_enemy2, border_player, game_lvl))
                            {
                                move2 = true;
                                clock_move2.restart();
                                allow_move2 = 0;
                            }
                    if (move2)
                        if (allow_move2 > 4)
                        {
                            move2 = false;
                        }

                    if (!collision)                   // when collion occurs alot of things happen
                        if (Enemy->collision(Player)) // different music plays
                        {
                            if (game_lvl == 1 || game_lvl == 2)
                                lvl_sound.stop();
                            else if (game_lvl == 3 || game_lvl == 4)
                                lvl_sound2.stop();
                            life_lost.play();
                            Player->live_decrement(); // player live decrease
                            collision = true;
                            Player->change_sprite("img/p_destroyed.png"); // Player and enemy images are changed
                            Enemy->change_sprite("img/e_destroyed.png");
                            clock_roundrestart.restart();
                            collide = 0;
                        }
                    if (collision)
                        if (collide > 3) // time before the round restarts
                        {
                            life_lost.stop();
                            collision = false;
                            Player->change_sprite("img/player_side.png"); // Sprites are reseted to normal ones
                            Enemy->change_sprite("img/enemy_side.png");
                            destroyed = 0;
                            spd += 10;                    // the powerup cool downs are removed
                            Player->set_increased(false); // power up effects are removed
                            Player->change_speed(0.15);
                            border_player = 4; // new spawn positions are set
                            border_enemy = 4;
                            border_enemy2 = 3;
                            Player->set_pos(450, 520);
                            x = 0;
                            y = 0;
                            Enemy->set_pos(650, 520);
                            if (Enemy2 != nullptr)
                            {
                                Enemy2->change_sprite("img/enemy_side.png");
                                Enemy2->set_pos(920, 200);
                            }
                            Player->set_value(temp_score);
                            //  Player->set_live(temp_life);
                            form = true; // the food formation is allowed
                        }
                    if (!collision2)
                        if (Enemy2 != nullptr) // The same things happen as mentioned above
                            if (Enemy2->collision(Player))
                            {
                                if (game_lvl == 1 || game_lvl == 2)
                                    lvl_sound.stop();
                                else if (game_lvl == 3 || game_lvl == 4)
                                    lvl_sound2.stop();
                                life_lost.play();
                                Player->live_decrement();
                                collision2 = true;
                                Player->change_sprite("img/p_destroyed.png");
                                Enemy2->change_sprite("img/e_destroyed.png");
                                clock_roundrestart.restart();
                                collide = 0;
                            }
                    if (collision2)
                        if (collide > 3) // time before spawn
                        {
                            life_lost.stop();
                            collision2 = false;
                            Player->change_sprite("img/player_side.png");
                            Enemy->change_sprite("img/enemy_side.png");
                            Enemy2->change_sprite("img/enemy_side.png");
                            destroyed = 0;
                            spd += 10;
                            Player->set_increased(false);
                            Player->change_speed(0.15);
                            border_player = 4;
                            border_enemy = 4;
                            border_enemy2 = 3;
                            Player->set_pos(450, 520);
                            x = 0;
                            y = 0;
                            Enemy->set_pos(650, 520);
                            if (Enemy2 != nullptr)
                                Enemy2->set_pos(920, 200);
                            Player->set_value(temp_score);
                            // Player->set_live(temp_life);
                            form = true;
                        }

                    if (form)
                    { // first all the food are set to null
                      // memory allocation according to food numbers
                      //  there are different numbers in each round to this process is repeated at
                      //  beginning of each round
                        form = false;
                        for (int i = 0; i < redfood_num; i++)
                            if (redfood[i] != nullptr)
                            {
                                delete redfood[i];
                                redfood[i] = nullptr;
                            }

                        for (int i = 0; i < greenfood_num; i++)
                            if (greenfood[i] != nullptr)
                            {
                                delete greenfood[i];
                                greenfood[i] = nullptr;
                            }

                        for (int i = 0; i < orangefood_num; i++)
                            if (orangefood[i] != nullptr)
                            {
                                delete orangefood[i];
                                orangefood[i] = nullptr;
                            }

                        for (int i = 0; i < whitefood_num; i++)
                            if (whitefood[i] != nullptr)
                            {
                                delete whitefood[i];
                                whitefood[i] = nullptr;
                            }
                        if (game_lvl == 1)

                        {
                            lvl_sound.play();

                            for (int i = 0; i < redfood_num; i++)
                                redfood[i] = new Redfood;

                            for (int i = 0; i < greenfood_num; i++)
                                greenfood[i] = new Greenfood;

                            for (int i = 0; i < orangefood_num; i++)
                                orangefood[i] = new Orangefood;

                            for (int i = 0; i < whitefood_num; i++)
                                whitefood[i] = new Whitefood;

                            int x = 66, y = 155;

                            int i = 0, r = 0, g = 0, o = 0, w = 0;
                            for (; i < 16; i++)
                            {

                                if (i == 4 || i == 8 || i == 12)
                                {
                                    x += 108;
                                    y = 155;
                                }
                                if (i != 0 && i != 4 && i != 8 && i != 12)
                                    y += 45;
                                if (i == 0)
                                {
                                    orangefood[o]->formation(x, y);
                                    o++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                            x = 66;
                            y = 520;
                            for (; i < 32; i++)
                            {
                                if (i == 20 || i == 24 || i == 28)
                                {
                                    x += 108;
                                    y = 520;
                                }
                                if (i != 16 && i != 20 && i != 24 && i != 28)
                                    y -= 45;
                                if (i == 21)
                                {
                                    greenfood[g]->formation(x, y);
                                    g++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }

                            x = 1034;
                            y = 155;
                            for (; i < 48; i++)
                            {
                                if (i == 36 || i == 40 || i == 44)
                                {
                                    x -= 108;
                                    y = 155;
                                }
                                if (i != 32 && i != 36 && i != 40 && i != 44)
                                    y += 45;
                                if (i == 47)
                                {
                                    whitefood[w]->formation(x, y);
                                    w++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                            x = 1034;
                            y = 520;
                            for (; i < 64; i++)
                            {
                                if (i == 52 || i == 56 || i == 60)
                                {
                                    x -= 108;
                                    y = 520;
                                }
                                if (i != 48 && i != 52 && i != 56 && i != 60)
                                    y -= 45;
                                if (i == 58)
                                {
                                    orangefood[o]->formation(x, y);
                                    o++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                        }
                        else if (game_lvl == 2)
                        {
                            lvl_sound.stop();
                            lvl_sound.play();
                            redfood_num = 60;
                            greenfood_num = 1;
                            orangefood_num = 2;
                            whitefood_num = 1;

                            for (int i = 0; i < redfood_num; i++)
                                redfood[i] = new Redfood;

                            for (int i = 0; i < greenfood_num; i++)
                                greenfood[i] = new Greenfood;

                            for (int i = 0; i < orangefood_num; i++)
                                orangefood[i] = new Orangefood;

                            for (int i = 0; i < whitefood_num; i++)
                                whitefood[i] = new Whitefood;

                            int x = 66, y = 155;

                            int i = 0, r = 0, g = 0, o = 0, w = 0;
                            for (; i < 16; i++)
                            {

                                if (i == 4 || i == 8 || i == 12)
                                {
                                    x += 108;
                                    y = 155;
                                }
                                if (i != 0 && i != 4 && i != 8 && i != 12)
                                    y += 45;
                                if (i == 6)
                                {
                                    greenfood[g]->formation(x, y);
                                    g++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                            x = 66;
                            y = 520;
                            for (; i < 32; i++)
                            {
                                if (i == 20 || i == 24 || i == 28)
                                {
                                    x += 108;
                                    y = 520;
                                }
                                if (i != 16 && i != 20 && i != 24 && i != 28)
                                    y -= 45;
                                if (i == 26)
                                {
                                    orangefood[o]->formation(x, y);
                                    o++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }

                            x = 1034;
                            y = 155;
                            for (; i < 48; i++)
                            {
                                if (i == 36 || i == 40 || i == 44)
                                {
                                    x -= 108;
                                    y = 155;
                                }
                                if (i != 32 && i != 36 && i != 40 && i != 44)
                                    y += 45;
                                if (i == 32)
                                {
                                    orangefood[o]->formation(x, y);
                                    o++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                            x = 1034;
                            y = 520;
                            for (; i < 64; i++)
                            {
                                if (i == 52 || i == 56 || i == 60)
                                {
                                    x -= 108;
                                    y = 520;
                                }
                                if (i != 48 && i != 52 && i != 56 && i != 60)
                                    y -= 45;
                                if (i == 57)
                                {
                                    whitefood[w]->formation(x, y);
                                    w++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                        }
                        else if (game_lvl == 3)
                        {
                            lvl_sound.stop();
                            lvl_sound2.play();
                            redfood_num = 59;
                            orangefood_num = 2;
                            greenfood_num = 2;
                            whitefood_num = 1;

                            for (int i = 0; i < redfood_num; i++)
                                redfood[i] = new Redfood;

                            for (int i = 0; i < greenfood_num; i++)
                                greenfood[i] = new Greenfood;

                            for (int i = 0; i < orangefood_num; i++)
                                orangefood[i] = new Orangefood;

                            for (int i = 0; i < whitefood_num; i++)
                                whitefood[i] = new Whitefood;

                            int x = 66, y = 155;

                            int i = 0, r = 0, g = 0, o = 0, w = 0;
                            for (; i < 16; i++)
                            {

                                if (i == 4 || i == 8 || i == 12)
                                {
                                    x += 108;
                                    y = 155;
                                }
                                if (i != 0 && i != 4 && i != 8 && i != 12)
                                    y += 45;
                                if (i == 6)
                                {
                                    orangefood[o]->formation(x, y);
                                    o++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                            x = 66;
                            y = 520;
                            for (; i < 32; i++)
                            {
                                if (i == 20 || i == 24 || i == 28)
                                {
                                    x += 108;
                                    y = 520;
                                }
                                if (i != 16 && i != 20 && i != 24 && i != 28)
                                    y -= 45;
                                if (i == 26)
                                {
                                    greenfood[g]->formation(x, y);
                                    g++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }

                            x = 1034;
                            y = 155;
                            for (; i < 48; i++)
                            {
                                if (i == 36 || i == 40 || i == 44)
                                {
                                    x -= 108;
                                    y = 155;
                                }
                                if (i != 32 && i != 36 && i != 40 && i != 44)
                                    y += 45;
                                if (i == 38)
                                {
                                    whitefood[w]->formation(x, y);
                                    w++;
                                    continue;
                                }
                                else if (i == 47)
                                {
                                    greenfood[g]->formation(x, y);
                                    g++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                            x = 1034;
                            y = 520;
                            for (; i < 64; i++)
                            {
                                if (i == 52 || i == 56 || i == 60)
                                {
                                    x -= 108;
                                    y = 520;
                                }
                                if (i != 48 && i != 52 && i != 56 && i != 60)
                                    y -= 45;
                                if (i == 48)
                                {
                                    orangefood[o]->formation(x, y);
                                    o++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                        }
                        else if (game_lvl == 4)
                        {
                            lvl_sound.stop();
                            lvl_sound2.stop();
                            lvl_sound2.play();
                            Enemy2 = new blue_enemy;
                            Enemy2->formation(926, 200);

                            redfood_num = 58;
                            orangefood_num = 2;
                            greenfood_num = 2;
                            whitefood_num = 2;

                            for (int i = 0; i < redfood_num; i++)
                                redfood[i] = new Redfood;

                            for (int i = 0; i < greenfood_num; i++)
                                greenfood[i] = new Greenfood;

                            for (int i = 0; i < orangefood_num; i++)
                                orangefood[i] = new Orangefood;

                            for (int i = 0; i < whitefood_num; i++)
                                whitefood[i] = new Whitefood;

                            int x = 66, y = 155;

                            int i = 0, r = 0, g = 0, o = 0, w = 0;
                            for (; i < 16; i++)
                            {

                                if (i == 4 || i == 8 || i == 12)
                                {
                                    x += 108;
                                    y = 155;
                                }
                                if (i != 0 && i != 4 && i != 8 && i != 12)
                                    y += 45;
                                if (i == 6)
                                {
                                    greenfood[g]->formation(x, y);
                                    g++;

                                    continue;
                                }
                                else if (i == 15)
                                {
                                    whitefood[w]->formation(x, y);
                                    w++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                            x = 66;
                            y = 520;
                            for (; i < 32; i++)
                            {
                                if (i == 20 || i == 24 || i == 28)
                                {
                                    x += 108;
                                    y = 520;
                                }
                                if (i != 16 && i != 20 && i != 24 && i != 28)
                                    y -= 45;
                                if (i == 26)
                                {
                                    orangefood[o]->formation(x, y);
                                    o++;
                                    continue;
                                }
                                else if (i == 19)
                                {
                                    whitefood[w]->formation(x, y);
                                    w++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }

                            x = 1034;
                            y = 155;
                            for (; i < 48; i++)
                            {
                                if (i == 36 || i == 40 || i == 44)
                                {
                                    x -= 108;
                                    y = 155;
                                }
                                if (i != 32 && i != 36 && i != 40 && i != 44)
                                    y += 45;
                                if (i == 38)
                                {
                                    orangefood[o]->formation(x, y);
                                    o++;
                                    continue;
                                }

                                redfood[r]->formation(x, y);
                                r++;
                            }
                            x = 1034;
                            y = 520;
                            for (; i < 64; i++)
                            {
                                if (i == 52 || i == 56 || i == 60)
                                {
                                    x -= 108;
                                    y = 520;
                                }
                                if (i != 48 && i != 52 && i != 56 && i != 60)
                                    y -= 45;
                                if (i == 52)
                                {
                                    greenfood[g]->formation(x, y);
                                    g++;
                                    continue;
                                }
                                redfood[r]->formation(x, y);
                                r++;
                            }
                        }
                    }
                    for (int i = 0; i < redfood_num; i++)
                    {
                        if (redfood[i] != nullptr)
                            if (redfood[i]->food_player_collision(Player)) // Player and red food contact
                            {

                                redfood[i]->add_points(Player); // Player gets points
                                delete redfood[i];
                                redfood[i] = nullptr;
                                destroyed++;
                                break;
                            }
                    }
                    for (int i = 0; i < orangefood_num; i++)
                    {
                        if (orangefood[i] != nullptr)
                            if (orangefood[i]->food_player_collision(Player)) // Player orange food contact
                            {
                                power_up.play();
                                orangefood[i]->add_points(Player);
                                if (!Player->get_increased())
                                    spd_increase = orangefood[i]->increase_speed(Player); // Player speed increases
                                delete orangefood[i];
                                orangefood[i] = nullptr;
                                destroyed++;
                                break;
                            }
                    }
                    for (int i = 0; i < whitefood_num; i++)
                    {
                        if (whitefood[i] != nullptr)
                            if (whitefood[i]->food_player_collision(Player)) // Player white food contact
                            {
                                coin.play();
                                whitefood[i]->add_points(Player);
                                if (x == 0)
                                {

                                    disappear = whitefood[i]->enemy_disappear(Enemy, x, y); // enemy disappears
                                    if (Enemy2 != nullptr)
                                        whitefood[i]->enemy_disappear(Enemy2, x, y); // 2nd also disappears if present
                                }
                                delete whitefood[i];
                                whitefood[i] = nullptr;
                                destroyed++;
                                break;
                            }
                    }
                    for (int i = 0; i < greenfood_num; i++)
                    {
                        if (greenfood[i] != nullptr)
                            if (greenfood[i]->food_player_collision(Player))
                            {
                                coin.play();
                                greenfood[i]->add_points(Player);
                                greenfood[i]->extra_live(Player); // Live increases after eating green food
                                delete greenfood[i];
                                greenfood[i] = nullptr;
                                destroyed++;
                                break;
                            }
                    }

                    if (disappear)
                    {
                        disappear = false;
                        clock_disappear.restart();
                        vanish = 0;
                    }

                    if (x != 0)
                        if (vanish > 10) // how long enemy disappears
                        {
                            Enemy->change_pos(-x, -y); // reset enemy back to its original position
                            if (Enemy2 != nullptr)
                                Enemy2->change_pos(-x, -y); // reset enemy back to
                            x = 0;
                            y = 0;
                        }

                    if (spd_increase)
                    {
                        spd_increase = false;
                        Player->set_increased(true);
                        clock_spd.restart();
                        spd = 0;
                    }

                    if (Player->get_increased())
                        if (spd > 10) // how long player speed increase
                        {
                            Player->set_increased(false);
                            Player->change_speed(0.15); // reset speed
                        }
                    if (destroyed == 64) // when all the food is eaten in a lvl
                    {
                        destroyed = 0;

                        spd += 10;
                        Player->set_increased(false); // player enemy positions are reseteed
                        Player->change_speed(0.15);   // images are updated
                        border_player = 4;
                        border_enemy = 4;
                        Player->change_sprite("img/player_side.png");
                        Enemy->change_sprite("img/enemy_side.png");
                        Player->set_pos(450, 520);
                        x = 0;
                        y = 0;
                        Enemy->set_pos(650, 520);
                        form = true; // game lvl increase and formation is allowed
                        game_lvl++;
                        temp_score = Player->get_value();
                    }

                    if (game_lvl == 3) // at lvl 3 enemy speed increase
                        Enemy->change_speed(0.15);
                    else
                        Enemy->change_speed(0.12);

                    if (Player->get_lifenum() == 0) // GAME OVER
                    {

                        life_lost.stop();
                        game_over.play();

                        check_start_game = menu->game_over(window, Continue, exit_game);

                        if (!Continue) // If game continue is false then break loop to start a new game
                        {
                            this->save_score(Player->get_value());

                            break;
                        }
                        else if (exit_game)
                        {
                            this->save_score(Player->get_value()); // Saves score before closing game
                            delete Player;
                            Player = nullptr;
                            delete Enemy;
                            Enemy = nullptr;
                            delete Enemy2;
                            Enemy2 = nullptr;
                            window.close();
                            return;
                        }
                    }

                    if (game_lvl == 5) // Game WON
                    {
                        this->save_score(Player->get_value()); // saves score
                        lvl_sound2.stop();
                        won.play();
                        delete Player;
                        Player = nullptr;
                        delete Enemy;
                        Enemy = nullptr;
                        delete Enemy2;
                        Enemy2 = nullptr;

                        if (menu->game_won(window))
                        {
                            window.close();
                        }
                        return;
                    }
                    //////////////////////////////////////////////////////////////////////////////////// call functions above
                    window.clear(Color::Black);
                    window.draw(background);
                    window.draw(Player->get_sprite3());
                    window.draw(Player->get_sprite2());
                    window.draw(Player->get_sprite1());
                    window.draw(Player->get_sprite4());

                    for (int i = 0; i < redfood_num; i++)
                        if (redfood[i] != nullptr)
                            window.draw(redfood[i]->get_sprite());
                    for (int i = 0; i < orangefood_num; i++)
                        if (orangefood[i] != nullptr)
                            window.draw(orangefood[i]->get_sprite());
                    for (int i = 0; i < greenfood_num; i++)
                        if (greenfood[i] != nullptr)
                            window.draw(greenfood[i]->get_sprite());
                    for (int i = 0; i < whitefood_num; i++)
                        if (whitefood[i] != nullptr)
                            window.draw(whitefood[i]->get_sprite());

                    window.draw(Player->get_lives());
                    window.draw(Player->get_sprite());
                    if (Enemy != nullptr)
                        window.draw(Enemy->get_sprite());
                    if (Enemy2 != nullptr)
                        window.draw(Enemy2->get_sprite());
                    window.display();
                }
            }
        }
    }

    void save_score(int currentScore)
    {
        // Read existing high scores from the file
        ifstream file_read;
        ofstream file_write;

        file_read.open("highscores.txt");
        int highScores[5];
        for (int i = 0; i < 5; i++)
            highScores[i] = 0;

        int input;
        int scoreindex = 0;

        while (file_read >> input)
            if (scoreindex < 5)
            {
                highScores[scoreindex] = input;
                scoreindex++;
            }

        file_read.close();

        // Add the current game's score to the high scores
        if (scoreindex < 5)
            highScores[scoreindex] = currentScore;
        else
        {
            int index = 0;
            for (int i = 4; i >= 0; i--)
            {
                if (highScores[i] < highScores[index])
                {
                    index = i;
                }
            }
            highScores[index] = currentScore;
        }

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                if (highScores[j] < highScores[j + 1])
                {
                    int temp = highScores[j + 1];
                    highScores[j + 1] = highScores[j];
                    highScores[j] = temp;
                }
            }

        // Write the updated high scores back to the file
        file_write.open("highscores.txt");

        for (int i = 0; i < 5; ++i)
        {
            file_write << highScores[i] << endl;
        }

        file_write.close();
    }
};
