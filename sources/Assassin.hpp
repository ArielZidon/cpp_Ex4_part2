#include"Player.hpp"

namespace coup{
    class Assassin : public Player
    {
    protected:
        Player *kill;
        int cost;
    public:
        Assassin(Game &game, string name);
        void coup(Player &p);
        string role();
        void IgetBlock();
    };
}