
#ifndef ASSIGNMENT_6_ENEMYBLACKWOLF_H
#define ASSIGNMENT_6_ENEMYBLACKWOLF_H

#include "Enemy.h"

class EnemyBlackWolf : Enemy {

public:
    EnemyBlackWolf(sf::RenderWindow &window, std::array<int, 2> WxPos, std::array<int, 2> WyPos);

    ~EnemyBlackWolf();

    void drawEnemyBlackWolf(sf::RenderWindow &window, std::array<int, 2> WxPos, std::array<int, 2> WyPos);

    std::array <sf::Sprite, 2> spriteBlackWolfEnemy;

};


#endif //ASSIGNMENT_6_ENEMYBLACKWOLF_H