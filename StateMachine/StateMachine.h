#ifndef ASSIGNMENT_6_STATEMACHINE_H
#define ASSIGNMENT_6_STATEMACHINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../GlobalVars.h"

enum class State {
    MENU, LEVELS, HIGHSCORE, SETTINGS, UPGRADES, PAUSE, LEVEL1, LEVEL2, LEVEL3, LEVEL4, WINSCREEN, LOSESCREEN
};
enum class Signals {
    menu, levels, highscore, settings, upgrades, pause, level1, level2, level3, level4, winscreen, losescreen
};

class StateMachine {

public:

    StateMachine();

    ~StateMachine();

    void SendSignal(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);
    State state;
protected:

    //One function for each state. Receives signal for processing

    State StateMenu(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    State StateLevels(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    State StateHighscore(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    State StateUpgrades(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    State StateSetting(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    State StatePause(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    State StateLevel1(Signals signals, sf::RenderWindow &window);

    State StateWinScreen(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

    State StateLoseScreen(Signals signals, sf::RenderWindow &window, bool fullScreen, bool sound, bool music, int level);

};


#endif //ASSIGNMENT_6_STATEMACHINE_H
