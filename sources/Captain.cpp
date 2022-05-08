#include "Captain.hpp"

namespace coup{

    Captain::Captain(Game &game, string name) : Player(game, name)
    {
        this->victem = NULL;
        STOLEN_MONEY = 0;
    }
    
    void Captain::block(Player &p)
    {
        if(p.Action == Act::steal)
        {
            p.IgetBlock();
        }
        else{
            throw invalid_argument("cant block " + p.name );
        }
    }

    void Captain::steal(Player &p)
    {
        checkTurn();
        if(p.money>=2)
        {
            STOLEN_MONEY = 2;
            p.money-=2;
            money+=2;
            this->victem = &p;
        }
        else{
            STOLEN_MONEY = p.money;
            money+=p.money;
            p.money = 0;
        }
        end(Act::steal);
    }

    string Captain::role()
    {
        return "Captain";
    }

    void Captain::IgetBlock()
    {
        if(Action == Act::foreign_aid)
        {
            money-=2;
        }
        if(Action == Act::steal)
        {
            victem->money+=STOLEN_MONEY;
            money-=STOLEN_MONEY;
        }
        else
        {
            throw runtime_error("the Captain do not do any act");
        }
        Action = Act::nothing;
    }
    
}