#ifndef ASSIGNMENT_6_ENEMYBEE_H
#define ASSIGNMENT_6_ENEMYBEE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enemy.h"

// enmeyBee implements from class Enemy
class EnemyBee : Enemy {

public:
    EnemyBee(sf::RenderWindow &window,std::array<int, 5> BxPos, std::array<int, 5> ByPos);

    ~EnemyBee();

    void drawEnemyBee(sf::RenderWindow &window, std::array<int, 5> BxPos, std::array<int, 5> ByPos);
    std::array <sf::Sprite, 5> spriteBeeEnemy;


};


#endif //ASSIGNMENT_6_ENEMYBEE_H