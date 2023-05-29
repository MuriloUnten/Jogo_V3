#pragma once

enum stateID
{
    undefined = -1,
    mainMenu = 0,
    level,
    leaderboard,
    gameOver,
    pause,
    menuChoosePlayers,
    menuEndLevel, 
    menuSaveRanking
};

namespace Managers
{
    class StateMachine;
}

namespace GameStates
{
    class GameState
    {
    protected:
        static Managers::StateMachine* stateMachine;
        stateID id;
        bool active;

    public:
        GameState();
        virtual ~GameState();

        virtual void execute() = 0;
        virtual void draw() = 0;
        virtual void resetState() = 0;

        void changeState(stateID id);
        const stateID getID() const;

        const bool getActive() const;
        void setActive(const bool isActive);
    };
}// namespace GameStates
