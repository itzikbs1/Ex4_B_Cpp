#include <iostream>
#include <iostream>
#include "Player.hpp"

using namespace std;
namespace coup{
class Assassin : public Player{


    public:
        Assassin(Game &game, string name) : Player(game, name){
            this->player_role = "Assassin";
        }
        void coup(Player &player);
};
}