#include "Player.hpp"

namespace coup{

class Game;
        
Player::Player(Game &g , string &name)
{
    this->Action = Act::nothing;
    this->game = &g;
    this->name = name;
    this->money = 0;
    this->life = true;
    game->add_a_Player(this);
}

void Player:: income()
{
    // if(money>=maxCoins)
    // {
    //     throw runtime_error(name + " you can has more than 10 coins");
    // }
    checkTurn();
    this->money++;
     end(Act::income);
}

void Player::foreign_aid()
{
    if(money>=maxCoins)
    {
        throw runtime_error(name + " you can has more than 10 coins");
    }
    checkTurn();
    this->money+=2;
    end(Act::foreign_aid);
}

int Player::coins() const
{
    return this->money;
}
void Player::coup(Player &person)
{
    if (!person.life)
    {
        throw runtime_error(name + "he dead");
    }
    if (money < money2coup)
    {
        throw runtime_error("you ant kill with thus money");
    }
    person.life = false;
    money -= money2coup;
    end(Act::coup);
}

void Player::checkTurn()
{
    if (game->players().size() < 2)
    {
        throw runtime_error("cant play with 1 player only");
    }
    if (!life)
    {
        throw runtime_error(name + " is allready Dead");
    }
    if (name != game->turn())
    {
        throw runtime_error("this is not your turn: "+name +"||| this: "+game->turn());
    }
    game->StartGame = true;
}

void Player::end(Act temp)
{
    Action = temp;
    game->nextTern();
}

}