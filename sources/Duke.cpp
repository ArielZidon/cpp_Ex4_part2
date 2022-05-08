#include "Duke.hpp"

namespace coup{

    Duke::Duke(Game &game, string name) : Player(game, name)
    {}  

    void Duke::block(Player &p)
    {
        if(p.Action == Act::foreign_aid)
        {
            p.IgetBlock();
        }
        else{
            throw invalid_argument("cant block " + p.name );
        }
    }

    void Duke::tax()
    {
        checkTurn();
        money+=3;
        end(Act::tax);
    }

    string Duke::role()
    {
        return "Duke";
    }

    void Duke::IgetBlock()
    {
        if(Action == Act::foreign_aid)
        {
            money-=2;
        }
        else
        {
            throw runtime_error("the Duke do not do any act");
        }
        Action = Act::nothing;
    }

}