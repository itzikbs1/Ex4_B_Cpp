#include <iostream>
#include <stdlib.h>
#include <string>
#include "Duke.hpp"


using namespace std;
using namespace coup;


    void Duke::block(Player &player){
        if(!this->_game.get_game_strated()){
                this->_game.set_game_strated(true);
            }
        if(player.get_last_operation() == "foreign_aid" && player.get_name() != this->_game.turn()){
            player.set_coins_player(-2);
        }else{
            throw runtime_error("the last operation of the player is not foreign_aid");
        }
        this->last_operation = "block";
    }
    void Duke::tax(){
        if(!this->_game.get_game_strated()){
                this->_game.set_game_strated(true);
            }
        if(this->_name == this->_game.turn()){
            if(this->coins_player<ten){
                this->coins_player+=3;
                this->_game.set_current_player();
            }else{
                this->_game.set_current_player();
                throw runtime_error("you have more than 10 coins");
            }
        }else{
            throw runtime_error("its not your turn");
        }
        this->last_operation = "tax";
    }

