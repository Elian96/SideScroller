//
// Created by Pavel Ibrahim on 12/14/18.
//

#include <iostream>
#include "Shuriken.h"
#include "MC.h"

Shuriken::Shuriken(MC &Maincharacter) {
    Shuriken_Sprite.setTexture(Shuriken_Texture);
    if (!Shuriken_Texture.loadFromFile("MainC/Shuriken.png"))
        std::cout << "Error loading png file";

    Shuriken_Sprite.setPosition(Maincharacter.MC_Sprite.getPosition().x, Maincharacter.MC_Sprite.getPosition().y);
}

void Shuriken::Shuriken_Draw(sf::RenderWindow &window, MC &Traveler, int Shuriken_Level) {
    Shuriken_Level = Shuriken_Level_Variable;
    window.draw(Shuriken_Sprite);
}

void Shuriken::Shuriken_DirChange(MC &Traveler)
{
    bool MC_Dir_Left  = false;
    bool MC_Dir_Right = true;  // the character points to the right when the game starts

    if(Traveler.MC_Direction.y == RightI
       || Traveler.MC_Direction.y == RightM
       || Traveler.MC_Direction.y == RightIW
       || Traveler.MC_Direction.y == RightMW) {
        MC_Dir_Right = true;
        MC_Dir_Left  = false;
    }
    if(Traveler.MC_Direction.y == LeftI
       || Traveler.MC_Direction.y == LeftM
       || Traveler.MC_Direction.y == LeftIW
       || Traveler.MC_Direction.y == LeftMW) {
        MC_Dir_Left  = true;
        MC_Dir_Right = false;
    }

    if (MC_Dir_Right)
    {
        Shuriken_Velocity.x = Shuriken_Speed;
    }
    if (MC_Dir_Left)
    {
        Shuriken_Velocity.x = -Shuriken_Speed;
    }
}

void Shuriken::Shuriken_Move() {
    Shuriken_Sprite.move(Shuriken_Velocity.x, Shuriken_Velocity.y);
}

void Shuriken::Shuriken_Trigger()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        Shuriken_State.y = VISIBLE;
    }
}