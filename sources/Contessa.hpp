#include <iostream>
#include <iostream>
#include "Player.hpp"

using namespace std;
namespace coup{
class Contessa : public Player{


    public:
        Contessa(Game &game, string name) : Player(game, name){
            this->player_role = "Contessa";
        }
        void block(Player &player);
        void coup(Player &player);

};
}