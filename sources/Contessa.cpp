#include <iostream>
#include <stdlib.h>
#include <string>
#include "Contessa.hpp"


using namespace std;
using namespace coup;


    void Contessa::coup(Player &player){
        if(!this->_game.get_game_strated()){
                this->_game.set_game_strated(true);
            }
        Player::coup(player);
        this->last_operation = "coup";
    }
    void Contessa::block(Player &player){
        if(!this->_game.get_game_strated()){
                this->_game.set_game_strated(true);
            }
        if(player.get_last_operation() == "coup" && player.get_player_role() == "Assassin" && player.get_name() != this->_game.turn()){
            if(player.get_money_before_operation()>=seven){
                throw runtime_error("its invalid block you cant do it " + this->_name);
            }
            string dem_player = player.get_dismissed_player();
            string real_name = Player::change_name(dem_player);
            vector<string> player_name = this->_game.get_players_name();
            for (size_t i = 0; i < player_name.size(); i++)
            {
                if (player_name[i] == dem_player)
                {
                    this->_game.set_players_name(i, real_name);
                }
            }
        }else{
            throw runtime_error("its invalid block you cant do it " + this->_name);
        }
        this->last_operation = "block";
    }