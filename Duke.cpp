#include <iostream>
#include <stdlib.h>
#include <string>
#include "Duke.hpp"


using namespace std;
using namespace coup;


    void Duke::block(Player &player){
        if(player.get_last_operation() == "foreign_aid" && player.get_name() != this->_game.turn()){
            player.set_coins_player(-2); // need to check if the coins player need to be greather then 0 ???
        }else{
            throw runtime_error("the last operation of the player is not foreign_aid");
        }
        this->last_operation = "block";
    }
    void Duke::tax(){
        if(this->coins_player<ten){
            this->coins_player+=3;
            this->_game.set_current_player();
        }else{
            throw runtime_error("you have more than 10 coins");
        }
        this->last_operation = "tax";
    }

