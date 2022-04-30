#include <iostream>
#include <stdlib.h>
#include <string>
#include "Contessa.hpp"


using namespace std;
using namespace coup;

    // Contessa::Contessa(Game game, string name){
    //     Contessa::_name = move(name);
    //     Contessa::_game = game;
    // }
    void Contessa::coup(Player &player){
        Player::coup(player);
    }
    void Contessa::block(Player &player){

        // if(this->_name == this->_game.turn()){
            // cout<<"player.get_last_operation()"<<player.get_last_operation()<<endl;
            // cout<<"player.get_player_role()"<<player.get_player_role()<<endl;
            if(player.get_last_operation() == "coup" && player.get_player_role() == "assassin"){
                string dem_player = player.get_dismissed_player();
                // cout<<"dem_player"<<dem_player<<endl;
                string real_name = Player::change_name(dem_player);
                // cout<<"real_name "<<real_name<<endl;
                vector<string> player_name = this->_game.get_players_name();
                for (size_t i = 0; i < player_name.size(); i++)
                {
                    if (player_name[i] == dem_player)
                    {
                        // cout<<"32!!!"<<endl;
                        this->_game.set_players_name(i, real_name);
                    }
                }
            // }
                // string p = this->_game.get_players_dismissed()[player.get_name()];
                // this->_game.add_player(p);
            }else{
                throw runtime_error("its invalid block you cant do it " + this->_name);
            }
}