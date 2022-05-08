#include <iostream>
#include <stdlib.h>
#include <string>
#include "Player.hpp"


using namespace std;
using namespace coup;

    Player::Player(Game &game, string &name) : _game(game), _name(name){
        const int max_participants = 6;
            if((this->_game.players().size() < max_participants && !this->_game.get_game_strated()) || this->_game.players().empty()){
                game.add_player(name);
                this->coins_player = 0;
                this->dismissed_player = "";
                this->last_operation = "";
                this->money_before_operation = 0;
                this->stolen_player = NULL;
            }
            else{
                throw runtime_error("cant add more players.");
            }
        }
    void Player::income(){
        if(this->_game.turn() == this->_name && this->_game.players().size() > 1){
            if(this->coins_player < ten){
            this->coins_player++;
            this->last_operation = "income";
            this->_game.set_current_player();
            }else{
                this->_game.set_current_player();
                throw runtime_error("you have too much money");
            }
        }else{
            throw runtime_error("its not " + this->_name + " turn to play.");
        }
        if(!this->_game.get_game_strated()){
            this->_game.set_game_strated(true); 
        }
    }
    void Player::foreign_aid(){
        
        if(this->_game.turn() == this->_name && this->_game.players().size() > 1){
            if(this->coins_player < ten){
                this->coins_player+=2;
                this->last_operation = "foreign_aid";
                this->_game.set_current_player();
            }else{
                throw runtime_error("you have too much money");
            }
        }else{
            throw runtime_error("its not " + this->_name + " turn to play");
        }
        if(!this->_game.get_game_strated()){
            this->_game.set_game_strated(true); 
        }
    }
    void Player::coup(Player &player){
        if(this->_game.turn() == this->_name && still_in_game(player)){
            if(this->coins_player>=seven){
                this->coins_player-=seven;
                this->_game.remove_player(player._name);
                this->last_operation = "coup";
                this->dismissed_player = "-" + player.get_name();
                this->_game.set_current_player();
        }else{
            throw runtime_error("you dont have enough money");
        }
        }else{
            throw runtime_error("its not your turn");
        }
    }
    string Player::role() const{
        return this->player_role;
    }
    int Player::coins() const{
        return this->coins_player;
    }
    string Player::get_last_operation() const{
        return this->last_operation;
    }
    int Player::get_coins_player() const{
        return this->coins_player;
    }
    string Player::get_name() const{
        return this->_name;
    }
    string Player::get_player_role() const{
        return this->player_role;
    }
    string Player::get_dismissed_player() const{
        return this->dismissed_player;
    }
    int Player::get_money_before_operation() const{
        return this->money_before_operation;
    }
    void Player::set_coins_player(int k){
        this->coins_player += k;
    }
    void Player::set_dismissed_player(string &name){
        this->dismissed_player = name;
    }
    string Player::change_name(string &name){
        string new_name;
        for (size_t i = 1; i < name.size(); i++)
        {
            new_name.append({name[i]}); 
        }
        return new_name;
    }
    ostream& operator<<(ostream& os,const Player &player){
        return os;
    }
    bool Player::still_in_game(Player &player){
        if(player.get_name()[0] != '-'){
            vector<string> vec = player._game.get_players_name();
            for (size_t i = 0; i < vec.size(); i++)
            {
                if(player.get_name() == vec[i]){
                    return true;
                }
            }
        }
        return false;
    }