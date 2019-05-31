cmake_minimum_required(VERSION 3.12)
project(assignment_6)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp GameMenu/GameMenu.h GlobalVars.h GameMenu/GameMenu.cpp
        Levels/Levels.cpp Levels/Levels.h Level1/Level1.cpp
        Level1/Level1.h Settings/Settings.cpp
        Settings/Settings.h StateMachine/StateMachine.cpp StateMachine/StateMachine.h
        objects/layer.cpp objects/layer.h map/map.cpp map/map.h
        objects/object.h objects/sprite.cpp objects/sprite.h
        Collectors/Collectors.cpp Collectors/Collectors.h
        Upgrades/Upgrades.cpp Upgrades/Upgrades.h Enemy/EnemyBee.cpp
        Enemy/EnemyBee.h MainC/MC.cpp MainC/MC.h Highscore/Highscore.cpp Highscore/Highscore.h PauseMenu/PauseMenu.cpp
        PauseMenu/PauseMenu.h Levels/LevelBuild.cpp Levels/LevelBuild.h EndScreen/WinScreen.cpp EndScreen/WinScreen.h EndScreen/LoseScreen.cpp EndScreen/LoseScreen.h Enemy/Enemy.h Enemy/EnemyPerson.cpp Enemy/EnemyPerson.h Enemy/EnemyBlackWolf.cpp Enemy/EnemyBlackWolf.h Enemy/EnemyBrownWolf.cpp Enemy/EnemyBrownWolf.h MainC/Shuriken.cpp MainC/Shuriken.h)

add_executable(assignment_6 ${SOURCE_FILES})
target_link_libraries (assignment_6 sfml-graphics sfml-window sfml-system jsoncpp)