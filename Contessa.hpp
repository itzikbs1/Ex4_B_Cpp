#include <iostream>
#include <iostream>
#include "Player.hpp"

using namespace std;
namespace coup{
class Contessa : public Player{

    private:
        // string _name;
        // Game _game;
    public:
        // Contessa();
        // Contessa(Game game, string &name);
        Contessa(Game &game, string name) : Player(game, name){
            this->player_role = "contessa";
        }
        void block(Player &player);
        void coup(Player &player);

};
}