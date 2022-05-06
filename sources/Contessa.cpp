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

        if(player.get_last_operation() == "coup" && player.get_player_role() == "Assassin" && player.get_name() != this->_game.turn()){
            // cout<<"player.get_money_before_operation() "<<player.get_money_before_operation()<<endl;
            if(player.get_money_before_operation()>=7){
                throw runtime_error("its invalid block you cant do it " + this->_name);
            }
            // cout<<"18"<<endl;
            string dem_player = player.get_dismissed_player();
            // cout<<"dem_player "<<dem_player<<endl;
            string real_name = Player::change_name(dem_player);
            // cout<<"real_name "<<real_name<<endl;
            vector<string> player_name = this->_game.get_players_name();
            for (size_t i = 0; i < player_name.size(); i++)
            {
                if (player_name[i] == dem_player)
                {
                    this->_game.set_players_name(i, real_name);
                }
            }
        }else{
            // cout<<"32"<<endl;
            throw runtime_error("its invalid block you cant do it " + this->_name);
        }
        this->last_operation = "block";
    }