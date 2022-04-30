#include <iostream>
#include <iostream>
#include "Player.hpp"

using namespace std;
namespace coup{
class Captain : public Player{

    protected:
        // string _name;
        // Game _game;
        // Player stolen_player;
    public:
        // Captain();
        // Captain(Game game, string &name);
        Captain(Game &game, string name) : Player(game, name){
            this->player_role = "captain";
            // stolen_player{game, ""};
            // stolen_player = NULL;
            // this->stolen_player = NULL;
        }
        void block(Player &player);
        void steal(Player &player);
};
}