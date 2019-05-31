
#ifndef ASSIGNMENT_6_BROWNWOLF_H
#define ASSIGNMENT_6_BROWNWOLF_H

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class EnemyBrownWolf : Enemy{
public:
    EnemyBrownWolf(sf::RenderWindow &window, std::array<int,
            4> BrWxPos, std::array<int, 4> BrWyPos);

    ~EnemyBrownWolf();

    void drawEnemyBrownWolf(sf::RenderWindow &window, std::array<int,
            4> BrWxPos, std::array<int, 4> BrWyPos);

    std::array <sf::Sprite, 4> spriteBrownWolfEnemy;

};


#endif //ASSIGNMENT_6_BROWNWOLF_H