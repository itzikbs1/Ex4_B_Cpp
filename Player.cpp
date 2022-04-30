#include <iostream>
#include <stdlib.h>
#include <string>
#include "Player.hpp"


using namespace std;
using namespace coup;

    // Player::Player(Game &game, string &name, string player){
    //     cout<<"game!!!???   "<<&game<<endl;
    //     this->_game = game;
    //     cout<<"16!!"<<endl;
    //     // cout<<"game!  "<<&(this->_game)<<endl;
    //     this->_name = name;
    //     this->coins_player = 0;
    //     this->player_role = player;
    //     // this->_game.players_name.push_back(name);
    //     this->_game.add_player(name);
    // }
    void Player::income(){
        if(this->_game.turn() == this->_name){
            if(this->coins_player < ten){
            this->coins_player++;
            this->last_operation = "income";
            this->_game.set_current_player();
            }else{
                this->_game.set_current_player();
                throw runtime_error("you have too much money");
            }
        }else{
            // this->_game.set_current_player();
            throw runtime_error("its not " + this->_name + " turn to play");
        }
    }
    void Player::foreign_aid(){ // if the player blocked when he take foreign_aid its turn finish
        
        if(this->_game.turn() == this->_name){
            if(this->coins_player < ten){
                this->coins_player+=2;
                this->last_operation = "foreign_aid";
                this->_game.set_current_player();
            }else{
                this->_game.set_current_player();
                throw runtime_error("you have too much money");
            }
        }else{
            // this->_game.set_current_player();
            throw runtime_error("its not " + this->_name + " turn to play");
        }
    }
    void Player::coup(Player &player){
        if(this->_game.turn() == this->_name){
            if(this->coins_player>=seven){
                this->coins_player-=seven;
                this->_game.remove_player(player._name);
                this->last_operation = "coup";
                this->dismissed_player = "-" + player.get_name();
                this->_game.set_current_player();
        }else{
            this->_game.set_current_player();
            throw runtime_error("you dont have enough money");
        }
        }else{
            // this->_game.set_current_player();
            throw runtime_error("its not your turn");
        }
    }
    // string Player::winner(Game game){
    //     return "";
    // }
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