#include <iostream>
#include "Player.hpp"

using namespace std;
namespace coup{
class Duke : public Player{


    public:
        Duke(Game &game, string name) : Player(game, name){
         this->player_role = "Duke";   
        }
        void block(Player &player);
        void tax();
};
}