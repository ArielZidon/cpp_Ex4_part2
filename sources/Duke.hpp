#include"Player.hpp"

namespace coup{
    class Duke : public Player
    {
    public:
        Duke(Game &game, string name);
        static void block(Player &p);
        void tax();
        string role();
        void IgetBlock();
    };
}