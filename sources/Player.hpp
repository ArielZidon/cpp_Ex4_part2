#pragma once
#include <iostream>
#include <string>
#include "Game.hpp"
#define money2coup  7
#define maxPlayer  6
#define maxCoins 10

using namespace std;

namespace coup
{   
    class Game;
    enum Act
    {
        nothing,
		income,
		foreign_aid,
        coup,
        transfer,
        steal,
        tax
    };

    class Player
    {
        protected:
        Game *game;
        
        public:
        Act Action;
        string name;
        int money;
        bool life;

        Player(Game &g , string &name);
        void income();
        void foreign_aid();
        virtual void coup(Player &person);
        virtual string role() = 0;
        int coins() const;
        void checkTurn();
        void end(Act temp);
        virtual void IgetBlock() =0;
    };
}