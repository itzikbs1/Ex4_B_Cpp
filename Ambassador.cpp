#include <iostream>
#include <stdlib.h>
#include <string>
#include "Ambassador.hpp"


using namespace std;
using namespace coup;

    // Ambassador::Ambassador(Game game, string name){
    //     Ambassador::_name = move(name);
    //     Ambassador::_game = game;
    // }
    
    void Ambassador::transfer(Player &player1, Player &player2){
        if(this->_name == this->_game.turn()){
            if (player1.get_coins_player()>0)
            {
                player1.set_coins_player(-1);
                player2.set_coins_player(1);
            }
            this->_game.set_current_player();
        }else{
            throw runtime_error("its not" + this->_name + "turn");
        }
    }
    void Ambassador::block(Player &player){

    }