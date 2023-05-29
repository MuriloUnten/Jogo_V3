#include "../../include/GameStates/GameState.hpp"
#include "../../include/Managers/StateMachine.hpp"

namespace GameStates
{
    Managers::StateMachine* GameState::stateMachine = Managers::StateMachine::getInstance();

    GameState::GameState()
    {
        active = false;
    }


    GameState::~GameState()
    {

    }


    void GameState::changeState(stateID id)
    {
        stateMachine->changeState(id);
    }


    const stateID GameState::getID() const
    {
        return id;
    }


    const bool GameState::getActive() const
    {
        return active;
    }


    void GameState::setActive(const bool isActive)
    {
        active = isActive;
    }
}
