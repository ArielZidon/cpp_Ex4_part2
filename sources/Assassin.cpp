#include "Assassin.hpp"

namespace coup{
    
    Assassin::Assassin(Game &game, string name) : Player(game, name)
    {
        this->kill = NULL;
        this->cost = 0;
    }

    void Assassin::coup(Player &p)
    {
        checkTurn();
         if(!p.life)
         {
             throw runtime_error(name+" is allready dead");
         }
        if(money<3)
        {
            throw runtime_error("cant made the kill because you dont have enough money");
        }
        if(money<money2coup && money>=3 )
        {
            money-=3;
            p.life = false;
            this->kill = &p;
            end(Act::coup);
            cost = 3;
        }
        else{
            money-=money2coup;
            p.life = false;
            this->kill = &p;
            end(Act::coup);
            cost = money2coup;
        }   
    }

    string Assassin::role()
    {
        return "Assassin";
    }

    void Assassin::IgetBlock()
    {
        switch (Action)
        {
        case Act::foreign_aid:
            money -= 2;
            break;
        case Act::coup:
            if(cost == money2coup)
            {
                throw runtime_error("the Assassin made a reguler kill");
            }
            kill->life = true;
            break;
        default:
            throw invalid_argument("the Assassin do not do any act");
            break;
        }
        Action = Act::nothing;
    }
   
}