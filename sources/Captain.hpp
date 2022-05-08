#include"Player.hpp"

using namespace std;

namespace coup{
    class Captain : public Player
    {
        Player *victem;

    public:
        int STOLEN_MONEY;
        Captain(Game &game, string name);
        static void block(Player &p);
        void steal(Player &p);
        string role();
        void IgetBlock();
    };
}