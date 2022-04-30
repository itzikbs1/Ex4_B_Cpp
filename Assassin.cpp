#include <iostream>
#include <stdlib.h>
#include <string>
#include "Assassin.hpp"


using namespace std;
using namespace coup;


    void Assassin::coup(Player &player){
            if(this->get_coins_player()>=seven && this->_game.turn() == this->_name){
                Player::coup(player);
            }
            else if (this->coins_player>=3 && this->_game.turn() == this->_name)
            {
                this->coins_player-=3;
                this->_game.remove_player(player.get_name());
                string new_name = "-" + player.get_name();
                this->set_dismissed_player(new_name);
                this->_game.set_current_player();
            }else if(this->_game.turn() == this->_name){
                this->_game.set_current_player();
                throw runtime_error("you dont have enough coins");
            }else{
                throw runtime_error("its not your turn");
            }
            this->last_operation = "coup";
    }