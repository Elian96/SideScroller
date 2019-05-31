#include "MC.h"
#include "../objects/layer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

MC::MC(Map &map) : map(map){

    MC_Sprite.setTexture(MC_Texture);
    if (!MC_Texture.loadFromFile("MainC/TravelerFINALE.png"))
        std::cout << "Error loading png file";

    MC_Sprite.setPosition(10, 640);
}

void MC::MC_DrawCharacter(sf::RenderWindow &window, Map &maps) {
    MC_LoadTilemaps();

    // Under here are some declarations, i have it here because of the refresh-rate in Levelbuild
    // It's wrong to have it in the sf::Event part in LevelBuild.cpp, that's why it's here.
    // This code is implemented while window.isOpen() is active in LevelBuild.cpp
    MC_xPosition = static_cast<int>(MC_Sprite.getPosition().x);
    MC_yPosition = static_cast<int>(MC_Sprite.getPosition().y);

    MC_xTile = static_cast<unsigned int>(MC_xPosition / maps.getTileWidth());
    MC_yTile = static_cast<unsigned int>(MC_yPosition / maps.getTileHeight() + 1);

    MC_1Collider = MC_Foreground_Tilemap[MC_xTile + MC_yTile * MC_Layer_Foreground->getWidth()]; // The collision checker, which i like to call it...

    MC_TileCollision(MC_Right, map);
    if (MC_RightCollider_Foreground != 0) {
        MC_Velocity.x = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            MC_Velocity.x = 0;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            MC_Velocity.x -= MC_MovingSpeed;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {} // do nothing
    }
    MC_TileCollision(MC_Left, map);
    if (MC_LeftCollider_Foreground != 0) {
        MC_Velocity.x = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            MC_Velocity.x = 0;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            MC_Velocity.x += MC_MovingSpeed;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {} // do nothing

    }
    MC_TileCollision(MC_Top, map);
    if ((MC_Left_DownCollider_Foreground != 0 || MC_Right_DownCollider_Foreground != 0)
        || (MC_LeftCollider_Foreground != 0 || MC_RightCollider_Foreground != 0)) {
        MC_Velocity.y += 0.5;
    }
    else if ((MC_Left_DownCollider_Foreground != 0 && MC_Right_DownCollider_Foreground != 0) ||
             (MC_LeftCollider_Foreground != 0 && MC_RightCollider_Foreground != 0))
        MC_Velocity.y = 0;

    MC_TileCollision(MC_Bottom, map);
    if ((MC_LeftCollider_Foreground != 0 && MC_RightCollider_Foreground != 0)
        || (MC_Right_DownCollider_Foreground != 0 && MC_RightCollider_Foreground != 0)
        || (MC_Left_DownCollider_Foreground != 0 && MC_LeftCollider_Foreground != 0)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            MC_Velocity.y = 0;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            MC_Velocity.y = -MC_JumpSpeed;
        } else
            MC_Velocity.y = 0;
    }
    else
        MC_Velocity.y += MC_Gravity;

    MC_BridgeCollision(MC_Top, map);
    if (MC_Left_DownCollider_Bridges != 0 && MC_Right_DownCollider_Bridges != 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            MC_Velocity.y = 0;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            MC_Velocity.y = -MC_MovingSpeed;
        else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            MC_Velocity.y = 0;
    }

    MC_Sprite.setTextureRect(sf::IntRect(MC_Direction.x * 98, MC_Direction.y * 148, 94, 148));
    MC_Sprite.setScale(0.4, 0.4);

    // Drawing the Main character "Traveler"
    window.draw(MC_Sprite);
}

void MC::MC_MoveCharacter() {

    // Using this to check collision for the main character more precisely.
    // The top and bottom checks y collision
    // The left and right checks the x collision
    // The collisions are of course with the Tilemap

    MC_Top = sf::FloatRect(MC_Sprite.getPosition().x, MC_Sprite.getPosition().y, 35, 1);          // Top Rectangle of the MC
    MC_Bottom = sf::FloatRect(MC_Sprite.getPosition().x, MC_Sprite.getPosition().y + 53, 35, 1);  // Bottom Rectangle of the MC

    MC_Left = sf::FloatRect(MC_Sprite.getPosition().x, MC_Sprite.getPosition().y, 1, 53);         // Left side Rectangle of the MC
    MC_Right = sf::FloatRect(MC_Sprite.getPosition().x + 35, MC_Sprite.getPosition().y, 1, 53);   // Right side Rectangle of the MC

    MC_Sprite.move(MC_Velocity.x, MC_Velocity.y);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        MC_Velocity.x = -MC_MovingSpeed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        MC_Velocity.x = MC_MovingSpeed;
    } else
        MC_Velocity.x = 0;

//    std::cout << "MC_Xpos: " << MC_xPosition << " MC_Ypos " << MC_yPosition << " Top Collide: " << MC_Collide_Top << " Bottom Collide: " << MC_Collide_Bottom << std::endl;

}

void MC::MC_Events(sf::Event &event, sf::RenderWindow &window) {

    // Creating the animation by going through parts of the spritesheet.
    switch (event.type) {

        case sf::Event::KeyPressed: {
            if (event.key.code == sf::Keyboard::Right) {
                MC_Direction.x++;
                if (!MC_Weapon)
                    MC_Direction.y = RightI;
                if (MC_Weapon)
                    MC_Direction.y = RightIW;
                if (MC_Direction.y == RightI) {
                    MC_Direction.y = RightM;
                } if (MC_Direction.y == RightIW) {
                    MC_Direction.y = RightM;
                }
                if (MC_Direction.x * 99 > MC_Texture.getSize().x) {
                    MC_Direction.x = 0;
                    if (MC_Direction.y == RightM)
                        MC_Direction.y = RightI;
                    if (MC_Direction.y == RightMW)
                        MC_Direction.y = RightIW;
                }
            }
            else if (event.key.code == sf::Keyboard::Left) {
                MC_Direction.x++;
                if (!MC_Weapon)
                    MC_Direction.y = LeftI;
                if (MC_Weapon)
                    MC_Direction.y = LeftIW;
                if (MC_Direction.y == LeftI) {
                    MC_Direction.y = LeftM;
                }
                if (MC_Direction.y == LeftIW) {
                    MC_Direction.y = LeftM;
                }
                if (MC_Direction.x * 98 > MC_Texture.getSize().x) {
                    MC_Direction.x = 0;
                    if (MC_Direction.y == LeftM)
                        MC_Direction.y = LeftI;
                    else if (MC_Direction.y == LeftMW)
                        MC_Direction.y = LeftIW;
                }

            } else if (event.key.code == sf::Keyboard::Space) {
                MC_Direction.x++;
                if (MC_Direction.x * 98 > MC_Texture.getSize().x) {
                    MC_Direction.x = 0;
                }

            } else if (event.key.code == sf::Keyboard::E) {
                if (!MC_Weapon) {
                    MC_Weapon = true;
                }
                if (MC_Weapon)
                    MC_Weapon = false;
                if (MC_Direction.y == LeftI || MC_Direction.y == LeftM)
                    MC_Direction.y = LeftIW;
                if (MC_Direction.y == RightI || MC_Direction.y == RightM)
                    MC_Direction.y = RightIW;
            }
            break;

        }
    }

//    std::cout << "MC_xTile: " << MC_xTile << " MC_yTile: " << MC_yTile << std::endl;
}

void MC::MC_TileCollision(sf::FloatRect &rect, Map &map) // Checking each rectangle around the MC for Collision
{

    int x1, x2, y1, y2;
    int tileX, tileY, tileX2, tileY2;

    x1 = static_cast<int>(rect.left + 5);            // The reason for adding 5 to it is to make it precise when colliding with walls.
    y1 = static_cast<int>(rect.top + 7);             // The reason for adding 7 to it is to make it precise to the ground
    x2 = static_cast<int>(rect.left + rect.width);
    y2 = static_cast<int>(rect.top + rect.height);

    tileX  = (x1 / map.getTileWidth());
    tileX2 = (x2 / map.getTileWidth());
    tileY  = (y1 / map.getTileHeight());
    tileY2 = (y2 / map.getTileHeight()) - 2;

    MC_LeftCollider_Foreground       = MC_Foreground_Tilemap[tileX  + tileY  * map.getWidth()];   // Checks if there is a tile in left top
    MC_RightCollider_Foreground      = MC_Foreground_Tilemap[tileX2 + tileY  * map.getWidth()];  // Checks if there is a tile in right top
    MC_Left_DownCollider_Foreground  = MC_Foreground_Tilemap[tileX  + tileY2 * map.getWidth()];  // Checks if there is a tile in left bottom
    MC_Right_DownCollider_Foreground = MC_Foreground_Tilemap[tileX2 + tileY2 * map.getWidth()]; // Checks if there is a tile in right bottom

//    std::cout << "Left: " << MC_LeftCollider_Foreground << " Right:" << MC_RightCollider_Foreground << " Left down: " << MC_Left_DownCollider_Foreground << " Right Down: " << MC_Right_DownCollider_Foreground << std::endl;
}

void MC::MC_BridgeCollision(sf::FloatRect &rect, Map &map) {
    int x1,x2,y1,y2;
    int tileX, tileX2, tileY, tileY2;

    x1 = static_cast<int>(rect.left);
    y1 = static_cast<int>(rect.top);
    x2 = static_cast<int>(rect.left + rect.width);
    y2 = static_cast<int>(rect.top + rect.height);

    tileX  = (x1 / map.getTileWidth());
    tileX2 = (x2 / map.getTileWidth());
    tileY  = (y1 / map.getTileHeight());
    tileY2 = (y2 / map.getTileHeight());

    MC_LeftCollider_Bridges       = MC_Bridges_Tilemap[tileX  + tileY  * map.getWidth()];     // Checks if there is a tile in left top
    MC_RightCollider_Bridges      = MC_Bridges_Tilemap[tileX2 + tileY  * map.getWidth()];     // Checks if there is a tile in right top
    MC_Left_DownCollider_Bridges  = MC_Bridges_Tilemap[tileX  + tileY2 * map.getWidth()];     // Checks if there is a tile in left bottom
    MC_Right_DownCollider_Bridges = MC_Bridges_Tilemap[tileX2 + tileY2 * map.getWidth()];     // Checks if there is a tile in right bottom

}

void MC::MC_LoadTilemaps() {
    MC_Layer_Foreground   = map.getLayer(MC_Layer_ForeGround_Name);
    MC_Foreground_Tilemap = MC_Layer_Foreground->getTilemap();

    MC_Layer_Bridges   = map.getLayer(MC_Layer_Bridges_Name);
    MC_Bridges_Tilemap = MC_Layer_Bridges->getTilemap();
}