#pragma once

#include "../GameStates/GameState.hpp"
#include <map>


namespace Managers
{
    class StateMachine
    {
    private:
       StateMachine();
        static StateMachine* instance;

        std::map<stateID, GameState*> statesMap;
        stateID currentStateID;
        stateID lastStateID;

    public:
        ~StateMachine();
        static StateMachine* getInstance();
        static void deleteInstance();

        void addState(GameState* state);
        void setState(stateID newStateID);
        void changeState(stateID newState);
        void overwriteState(GameState* newState);
        void executeState();
        void drawState();

    };
}// namespace Managers
