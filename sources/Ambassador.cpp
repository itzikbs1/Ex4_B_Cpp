#include <iostream>
#include <stdlib.h>
#include <string>
#include "Ambassador.hpp"


using namespace std;
using namespace coup;

    void Ambassador::transfer(Player &player1, Player &player2){
        if(this->_name == this->_game.turn()){
            if(!this->_game.get_game_strated()){
                this->_game.set_game_strated(true);
            }
            if (player1.get_coins_player()>0 && this->get_coins_player()<ten)
            {
                player1.set_coins_player(-1);
                player2.set_coins_player(1); 
            }else{
                throw runtime_error("He dont have enough money");
            }
            }else{
                throw runtime_error("its not" + this->_name + "turn");
            }
            this->_game.set_current_player();
            this->last_operation = "transfer";
    }
    void Ambassador::block(Player &player){
        int stolen = 0;
        if(!this->_game.get_game_strated()){
                this->_game.set_game_strated(true);
            }
        if (player.get_last_operation() == "steal" && player.get_player_role() == "Captain" && player.get_name() != this->_game.turn())
        {
            stolen = player.get_coins_player() - player.get_money_before_operation();
            player.set_coins_player(-stolen);
        
            string name_stolen = player.get_dismissed_player();
            for (size_t i = 0; i < this->_game.get_players_name().size(); i++)
            {
                if(this->_game.get_players_name()[i] == name_stolen){
                    player.stolen_player->set_coins_player(stolen);
                }
            }
        }else{
            throw runtime_error("its invalid block you cant do it " + this->_name);
        }
        this->last_operation = "block";
    }