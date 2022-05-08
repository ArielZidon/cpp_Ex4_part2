#include "Ambassador.hpp"

namespace coup{

    Ambassador::Ambassador(Game &game, string name) : Player(game, name)
    {}

    void Ambassador::transfer(Player &p1,Player &p2)
    {
        checkTurn();
        if(p1.money < 1)
        {
            throw runtime_error("cant transfer money from "+p1.name);
        }
        
        p1.money-=1;
        p2.money+=1;
        end(Act::transfer);
    }

    void Ambassador::block(Player &p)
    {
        if(p.Action == Act::steal)
        {
            p.IgetBlock();
        }
        else{
            throw invalid_argument("cant block " + p.name );
        }
    }
    
    string Ambassador::role()
    {
        return "Ambassador";
    }

    void Ambassador::IgetBlock()
    {
         if(Action != Act::foreign_aid)
        {
            throw runtime_error("the Ambassador do not do any act");
        }
        money-=2;
        Action = Act::nothing;
    }
}