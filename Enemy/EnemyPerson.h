
#ifndef ASSIGNMENT_6_ENEMYPERSON_H
#define ASSIGNMENT_6_ENEMYPERSON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Enemy.h"

class EnemyPerson : Enemy{

public:

    EnemyPerson(sf::RenderWindow &window, std::array<int, 5> PxPos,
                std::array<int, 5> PyPos);

    ~EnemyPerson();

    void drawEnemyPerson(sf::RenderWindow &window, std::array<int, 5> PxPos,
                         std::array<int, 5> PyPos, int level);
    std::array <sf::Sprite, 5> spritePersonEnemy;

};


#endif //ASSIGNMENT_6_ENEMYPERSON_H