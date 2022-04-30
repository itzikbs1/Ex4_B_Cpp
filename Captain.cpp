#include <iostream>
#include <stdlib.h>
#include <string>
#include "Captain.hpp"


using namespace std;
using namespace coup;

    // Captain::Captain(Game game, string name){
    //     Captain::_name = move(name);
    //     Captain::_game = game;
    // }
    void Captain::block(Player &player){
        int stolen = 0;
        // if(this->_name == this->_game.turn()){
            if (player.get_last_operation() == "steal" && player.get_player_role() == "captain")
            {
                stolen = player.get_coins_player() - player.get_money_before_operation();
                player.set_coins_player(-stolen);
            
            string name_stolen = player.get_dismissed_player();
            for (size_t i = 0; i < this->_game.get_players_name().size(); i++)
            {
                if(this->_game.get_players_name()[i] == name_stolen){
                    player.stolen_player->set_coins_player(stolen);
                    // player.stolen_player = ; //need this?
                }
            }
        }else{
            throw runtime_error("its invalid block you cant do it " + this->_name);
        }
    }
    void Captain::steal(Player &player){
        if(this->_name == this->_game.turn()){
            this->money_before_operation = this->coins_player;
            if(player.get_coins_player() == 1){
                player.set_coins_player(-1);
                this->set_coins_player(1);
            }else if(player.get_coins_player() >= 2){
                player.set_coins_player(-2);
                this->set_coins_player(2);
            }else{
                throw runtime_error("you cant steal from" + player.get_name() + "is dont have any money");
            }
            this->dismissed_player = player.get_name();
            this->_game.set_current_player();
            this->stolen_player = &player;
        }else{
            throw runtime_error("its not " + this->_name + " turn");
        }
    }