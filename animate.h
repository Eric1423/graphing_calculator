#ifndef ANIMATE_H
#define ANIMATE_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include "tokenizer.h"
#include <fstream>
#include <string>
#include <sstream>
class animate{

public:

    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    bool check(string a);
    bool find(char a);
    void saveFile();
    void loadFile();

    void loadFunction();
    void saveFunction();
    double increment();


private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    System system;
    int command;
    sf::Font font;
    sf::Text myTextLabel;
    sf::Text myTextLabel2;
    sf::Text myTextLabel3;
    sf::Text myTextLabel4;
    sf::Text myTextLabel5;//sin
    sf::Text myTextLabel6;//cos
    sf::Text myTextLabel7;//tan
    sf::Text myTextLabel8;//sec
    sf::Text myTextLabel9;
    sf::Text myTextLabel10;

    sf::Text myTextLabel11;//1
    sf::Text myTextLabel12;//2
    sf::Text myTextLabel13;//3
    sf::Text myTextLabel14;//4
    sf::Text myTextLabel15;
    sf::Text myTextLabel16;
    sf::Text myTextLabel17;
    sf::Text myTextLabel18;
    sf::Text myTextLabel19;//9
    sf::Text myTextLabel20;//(
    sf::Text myTextLabel21;//0
    sf::Text myTextLabel22;//)
    //equal 'x' clear
    sf::Text myTextLabel23;
    sf::Text myTextLabel24;
    sf::Text myTextLabel25;

    sf::Text myTextLabel26; //^
    //zoom in out/ reset
    sf::Text myTextLabel27;
    sf::Text myTextLabel28;
    sf::Text myTextLabel29;




    bool mouseIn;
    Sidebar sidebar;

    bool error_;
    string _funciton = "x^3";
    double _originX = 640;//320
    double _originY = 600;//300
    double _numOfdots = 10000;
    double _low = -20;
    double _high = 20;
    bool update_ = false;
    bool INPUT = false;
    double _size;

};

string mouse_pos_string(sf::RenderWindow& window);


#endif // ANIMATE_H
