#include <iostream>
#include <stdlib.h>
#include <string>
#include "Contessa.hpp"


using namespace std;
using namespace coup;


    void Contessa::coup(Player &player){
        Player::coup(player);
        this->last_operation = "coup";
    }
    void Contessa::block(Player &player){

            if(player.get_last_operation() == "coup" && player.get_player_role() == "assassin" && player.get_name() != this->_game.turn()){
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