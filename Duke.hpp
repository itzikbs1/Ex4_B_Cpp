#include <iostream>
#include "Player.hpp"

using namespace std;
namespace coup{
class Duke : public Player{

    private:
        // string player_role;
        // string _name;
        // Game _game;
    public:
        // Duke();
        // Duke(Game game, string &name);
        Duke(Game &game, string name) : Player(game, name){
         this->player_role = "duke";   
        }
        void block(Player &player);
        void tax();
};
}