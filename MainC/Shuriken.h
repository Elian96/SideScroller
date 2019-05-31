//
// Created by Pavel Ibrahim on 12/14/18.
//

#ifndef ASSIGNMENT_6_SHURIKEN_H
#define ASSIGNMENT_6_SHURIKEN_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

enum state
{
    VISIBLE, INVISIBLE
};

class MC;

class Shuriken {

    explicit Shuriken(MC &MainCharacter);

public:

    void Shuriken_Draw(sf::RenderWindow &window, MC &Traveler, int Shuriken_Level);
    void Shuriken_DirChange(MC &Traveler);
    void Shuriken_Move();
    void Shuriken_Trigger(); // This is called a trigger, mainly because it's the function that launches the shuriken.

private:
    float Shuriken_Damage   = 1;
    float Shuriken_Distance = 80;
    int Shuriken_Level_Variable;
    float Shuriken_Speed = 6.f;

    sf::Vector2i Shuriken_State = {0, INVISIBLE};
    sf::Vector2f Shuriken_Velocity;
    sf::Texture  Shuriken_Texture;
    sf::Sprite   Shuriken_Sprite;

};


#endif //ASSIGNMENT_6_SHURIKEN_H