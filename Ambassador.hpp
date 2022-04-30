#include <iostream>
#include "Player.hpp"

using namespace std;
namespace coup{
class Ambassador : public Player{

    private:
        // string _name;
        // Game _game;
    public:
        // Player::Player
        // Ambassador();
        // Ambassador(Game game, string &name);
        Ambassador(Game &game, string name) : Player(game, name){
            this->player_role = "ambassador";
        }
        void transfer(Player &player1, Player &player2);
        void block(Player &player);
};
}