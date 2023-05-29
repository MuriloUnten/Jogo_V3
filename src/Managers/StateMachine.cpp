#include "../../include/Managers/StateMachine.hpp"


namespace Managers
{
    StateMachine* StateMachine::instance = nullptr;

    StateMachine::StateMachine()
    {
        lastStateID = undefined;
        currentStateID = undefined;
    }


    StateMachine::~StateMachine()
    {
        std::map<stateID, GameStates::GameState*>::iterator it;

        for (it = statesMap.begin(); it != statesMap.end(); ++it)
            delete (it->second);
    }


    StateMachine* StateMachine::getInstance()
    {
        if(instance == nullptr)
            instance = new StateMachine();
        return instance;
    }


    void StateMachine::deleteInstance()
    {
        if(instance)
            delete instance;
        instance = nullptr;
    }


    void StateMachine::addState(GameStates::GameState* state)
    {
        if(state != nullptr)
            statesMap.insert(std::pair<stateID, GameStates::GameState*>(state->getID(), state));
    }


    void StateMachine::changeState(stateID newState)
    {
        lastStateID = currentStateID;
        currentStateID = newState;
        statesMap[currentStateID]->resetState();
    }


    void StateMachine::overwriteState(GameStates::GameState* newState)
    {
        statesMap[newState->getID()] = newState;
    }


    void StateMachine::executeState()
    {
        statesMap[currentStateID]->execute();
    }


    void StateMachine::drawState()
    {
        statesMap[currentStateID]->draw();
    }

}// namespace Managers
