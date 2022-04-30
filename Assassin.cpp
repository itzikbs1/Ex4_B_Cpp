#include <iostream>
#include <stdlib.h>
#include <string>
#include "Assassin.hpp"


using namespace std;
using namespace coup;

    // Assassin::Assassin(Game game, string name){
    //     Assassin::_name = move(name);
    //     Assassin::_game = game;
    // }
    void Assassin::coup(Player &player){
            if(this->get_coins_player()>=7 && this->_game.turn() == this->_name){
                Player::coup(player);
            }
            else if (this->coins_player>=3 && this->_game.turn() == this->_name)
            {
                this->coins_player-=3;
                this->_game.remove_player(player.get_name());
                string new_name = "-" + player.get_name();
                // cout<<"23"<<endl;
                // cout<<"new_name"<<new_name<<endl;
                // cout<<"this->dismissed_player"<<this->dismissed_player<<endl;
                this->set_dismissed_player(new_name);
                // cout<<"this->dismissed_player"<<this->dismissed_player<<endl;
                // cout<<"27"<<endl;
                // this->_game.get_players_dismissed()[this->get_name()] = player.get_name();
                this->last_operation = "coup";
                this->_game.set_current_player();
            }else{
                throw runtime_error("you dont have enough coins or its not your turn");
            }
    }