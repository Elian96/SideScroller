
#ifndef ASSIGNMENT_6_ENEMY_H
#define ASSIGNMENT_6_ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
/**
 * Enemy class which is implemented the other enemy classes
 * each enemy class have enum which includes directions
 * it has arrays of sprites for the other classes
 * texture of all classes
 *
 * @param P0 "person wiht index zero(0)" and and continues to number 4
 * @param B0 " Enemy Bee with index zero(0)"
 * @param BlW0 "Black Wolf with index zero(0)"
 * @param BrWo "Brown Wolf with index zero(0)"
 * @param subtInXPersonL : length person moves in x-axis to the left
 * @param addInXPersonL2 : length person moves in x-axis to the right
 */
enum DirectionPerson { //directions (right or left) to enemy person
    LEFT_P0, RIGHT_P0,
    LEFT_P1, RIGHT_P1,
    LEFT_P2, RIGHT_P2,
    LEFT_P3, RIGHT_P3,
    LEFT_P4, RIGHT_P4
};
enum DirectionBee {                       //directions( right or left) for enemy bee
    LEFT_B0, RIGHT_B0,
    LEFT_B1, RIGHT_B1,
    LEFT_B2, RIGHT_B2,
    LEFT_B3, RIGHT_B3,
    LEFT_B4, RIGHT_B4
};
enum DirectionBlackWolf {                //directions (right or left) for enemy Black Wolf
    LEFT_BlW0, RIGHT_BlW0,
    LEFT_W1, RIGHT_W1
};
enum DirectionBrownWolf{ //directions (right or left) for enemy Brown Wolf
    LEFT_BrW0, RIGHT_BrWO,
    LEFT_BrW1, RIGHT_BrW1,
    LEFT_BrW2, RIGHT_BrW2,
    LEFT_BrW3, RIGHT_BrW3
};

class Enemy {
public:

    DirectionPerson direction_P0 = LEFT_P0;
    DirectionPerson direction_P1 = LEFT_P1;
    DirectionPerson direction_P2 = LEFT_P2;
    DirectionPerson direction_P3 = LEFT_P3;
    DirectionPerson direction_P4 = LEFT_P4;

    DirectionBee direction_B0 = RIGHT_B0;
    DirectionBee direction_B1 = RIGHT_B1;
    DirectionBee direction_B2 = RIGHT_B2;
    DirectionBee direction_B3 = RIGHT_B3;
    DirectionBee direction_B4 = RIGHT_B4;

    DirectionBlackWolf direction_W0 = LEFT_BlW0;
    DirectionBlackWolf direction_W1 = LEFT_W1;

    DirectionBrownWolf direction_BrW0 = LEFT_BrW0;
    DirectionBrownWolf direction_BrW1 = LEFT_BrW1;
    DirectionBrownWolf direction_BrW2 = LEFT_BrW2;
    DirectionBrownWolf direction_BrW3 = LEFT_BrW3;

    //Texture for all enemies
    sf::Texture textureBeeEnemy;
    sf::Texture texturePersonEnemy;
    sf::Texture textureBlackWolfEnemy;
    sf::Texture textureBrownWolfEnemy;

    int speedOfPerEnemy = 20;
    int speedOfBeeEnemy = 20;
    int speedOfWolfEnemy = 20;
    int speedOfBrWolfEnemy = 20;
    int velDirection = -1;

    std::array<int, 5> subtInXPersonL;
    std::array<int, 5> addInXPersonL;

    std::array<int, 4> subtInXPersonL2;
    std::array<int, 4> addInXPersonL2;

};



#endif //ASSIGNMENT_6_ENEMY_H