#include <iostream>
#include <iostream>
#include "Player.hpp"

using namespace std;
namespace coup{
class Captain : public Player{


    public:
        Captain(Game &game, string name) : Player(game, name){
            this->player_role = "Captain";
        }
        void block(Player &player);
        void steal(Player &player);
};
}