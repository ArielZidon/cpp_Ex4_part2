#include "Game.hpp"

namespace coup
{
Game::Game(){
    t = 0;
    StartGame = false;
}

vector<string> Game::players()
{
    vector<string> res;
    for(Player *p : GamePlayers)
    {
        if(p->life)
        {
            res.push_back(p->name);
        }
    }
    return res;
}

string Game::turn()
{
    if (this->GamePlayers.empty())
    {
        throw runtime_error("0 players in the game");
    }
    return GamePlayers[t]->name;
}

string Game::winner()
{
    if (this->players().size()!=1 || !StartGame)
    {
        throw runtime_error("there is no players in the game");
    }
    return GamePlayers[t]->name;  
}

void Game::add_a_Player(Player *new_name)
{
    if (players().size() >= maxPlayer)
    {
        throw runtime_error("6 players max");
    }
    if (StartGame)
    {
        throw runtime_error("you cannot add aplayer in a middle of the game");
    }
    GamePlayers.push_back(new_name);
}

void Game::nextTern()
{
    do
        {
            t = (t+1) % GamePlayers.size();

        } while (!GamePlayers[t]->life);
}
}