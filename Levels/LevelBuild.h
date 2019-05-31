#ifndef ASSIGNMENT_6_LEVELBUILD_H
#define ASSIGNMENT_6_LEVELBUILD_H

#include <list>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "../map/map.h"
#include "../MainC/MC.h"
#include "../StateMachine/StateMachine.h"


class Object;

class Layer;

class LevelBuild {
public:

    unsigned int *tilemap;
    MC *traveler;

    LevelBuild();

    bool init(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    void run(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);


    std::list<std::shared_ptr<Object>> objects;     //List that contains the tiles as objects

    int level;                         //Variable to check the level we are on
    std::array<int, 20> CoinX;         //X positions for the coins
    std::array<int, 20> CoinY;         //Y positions for the coins
    std::array<int, 5> PxPos;          //X positions for the EnemyPerson
    std::array<int, 5> PyPos;          //Y positions for the EnemyPerson
    std::array<int, 5> BxPos;          //X positions for the EnemyBee
    std::array<int, 5> ByPos;          //Y positions for the EnemyBee
    std::array<int, 2> WxPosL1;        //X positions for the EnemyBlackWolf
    std::array<int, 2> WyPosL1;        //Y positions for the EnemyBlackWolf
    std::array<int, 4> BrWxPosL2;      //X positions for the EnemyBrownWolf
    std::array<int, 4> BrWyPosL2;      //Y positions for the EnemyBrownWolf

    Map map;
    sf::Font font;                      //The font used to view the texts on the screen
    sf::Texture Money;                  //The base for the collected money
    sf::Sprite money;                   //The sprite that contains the texture for the money
    sf::Texture ScoreBase;
    sf::Sprite scorebase;
    sf::View camera;                    //A movable view for the player
    sf::View UI;                        //Non-movable view for the HUD
    int moneyCollect = 0;               //Integer that contains the coins collected in a level then resets after going out of the level
    int score = 0;
    sf::Text MoneyText;                 //Text to save the amount of coins collected
    sf::Text ScoreText;
    sf::CircleShape myPlayer;           //A placeholder player for the level

protected:
    bool gameTick(sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level,
                  std::list<std::shared_ptr<Object>> &objects, float deltaTime);

    sf::Clock clock;                           //Clock used to calculate the time to move the objects
    std::array<sf::Sprite, 3> spriteCloud;     //All the different clouds will be in this array

    //Texture for the clouds
    sf::Texture textureCloud01;
    sf::Texture textureCloud02;
    sf::Texture textureCloud03;


    //Set the starting speed of the clouds
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    //Check if the clouds are shown on the screen
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;


};

#endif //ASSIGNMENT_6_LEVELBUILD_H