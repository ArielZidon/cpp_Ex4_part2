#include "Contessa.hpp"

namespace coup{

    Contessa::Contessa(Game &game, string name) : Player(game, name)
    {}

    void Contessa::block(Player &p)
    {
        if(p.Action!= Act::coup)
        {
            throw invalid_argument("cant block " + p.name );
        }
        p.IgetBlock();
    }
    
    string Contessa::role()
    {
        return "Contessa";
    }

    void Contessa::IgetBlock()
    {
        if(Action == Act::foreign_aid)
        {
            money-=2;
        }
        else
        {
            throw runtime_error("the Contessa do not do any act");
        }
        Action = Act::nothing;
    }
    
}