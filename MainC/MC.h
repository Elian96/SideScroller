#ifndef ASSIGNMENT_6_MC_H
#define ASSIGNMENT_6_MC_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "../map/map.h"
#include "../StateMachine/StateMachine.h"

class Map;
class Layer;
class LevelBuild;
class Enemy;
class StateMachine;


// Using enum to differentiate between directions of main character's movement
// This makes it easier to read code
enum Direction {
    RightI, LeftI, RightM, LeftM, RightIW, LeftIW, LeftMW, RightMW
    // "I" - Idle
    // "W" - Weapons
    // "M" - Moving
};

class MC {
public:
    explicit MC(Map &map);

    ~MC();

    unsigned int *MC_Foreground_Tilemap;                        // Used to obtain the tilemap array for the Foreground Layer
    unsigned int *MC_Bridges_Tilemap;                           // Used to obtain the tilemap array for the Bridges layer
    unsigned int MC_1Collider;

    std::shared_ptr<Layer> MC_Layer_Foreground;                 // Used to obtain the Foreground layer from the jSon file.
    std::shared_ptr<Layer> MC_Layer_Bridges;                    // Used to obtain the Bridges layer from the jSon file.

    unsigned int MC_xTile;
    unsigned int MC_yTile;

    void MC_DrawCharacter(sf::RenderWindow &window, Map &maps); // This draws the character ONLY
    void MC_MoveCharacter();                                    // Moving the character/Animation
    void MC_TileCollision(sf::FloatRect &rect, Map &map);
    void MC_BridgeCollision(sf::FloatRect &rect, Map &map);     // This is made because the bridge layer is a different one than the ForeGround
    void MC_Events(sf::Event &event, sf::RenderWindow &window); // All events for the Main Character is included in this function
    void MC_LoadTilemaps();                                     // Made a function that loads all tilemaps.

    sf::Vector2i MC_Direction = {0, RightIW};                    // Used to change between directions, Idle or in Movement, Weapons on or not

    sf::Sprite MC_Sprite;                                       // The sprite of the Main Character
    sf::Texture MC_Texture;                                     // The Texture of the Main Character

    sf::Event MC_Event;

    int MC_xPosition;                                    // X position of the Main character on the window screen.
    int MC_yPosition;                                    // Y position of the Main character on the window screen.

    sf::FloatRect MC_Top;                                // The horizontal rectangle on top of the Main Character
    sf::FloatRect MC_Bottom;                             // The horizontal rectangle under the Main Character
    sf::FloatRect MC_Left;                               // The Vertical rectangle to the left of the Main Character
    sf::FloatRect MC_Right;                              // The Vertical rectangle to the right of the Main Character

    std::string MC_Layer_ForeGround_Name = "ForeGround"; // Name of Foreground layer name in jSon file
    std::string MC_Layer_Bridges_Name = "Bridges";       // Name of Bridges layer name in jSon file

    //Tilemap positions for the different tilemaps in integers. These are being used for checking against player position to create collision.
    unsigned int MC_LeftCollider_Foreground, MC_RightCollider_Foreground, MC_Left_DownCollider_Foreground, MC_Right_DownCollider_Foreground;    // Foreground Layer
    unsigned int MC_LeftCollider_Bridges, MC_RightCollider_Bridges, MC_Left_DownCollider_Bridges, MC_Right_DownCollider_Bridges;                // Bridges Layer

    sf::Vector2f MC_Velocity = (sf::Vector2f(30, 0));       // Used for character position and moving the character itself

protected:
    float MC_Gravity = 0.1f;                                // Variable used for implementing a MC_Gravity-like mechanism on the map
    float MC_MovingSpeed = 3.0f;                            // Main character moving speed
    float MC_JumpSpeed = 6.5f;                              // This has to be faster to make it at least have more power than the resistance, aka MC_Gravity
    float MC_Damage = 1;                                    // This get's upgraded in the game. Max 5
    float MC_Health = 5;                                    // This get's upgraded in the game. Max
    bool  MC_Weapon;                                        // If the MC has the Weapons on or not...

    Map &map;
};

#endif //ASSIGNMENT_6_MC_H