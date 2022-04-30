#include <iostream>
#include <stdlib.h>
#include <string>
#include "Player.hpp"


using namespace std;
using namespace coup;

    // void coup::Player::income(){

    // }
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
        // cout<<"this->_game.turn()"<<this->_game.turn()<<endl;
        // cout<<"this->_name"<<this->_name<<endl;
        if(this->_game.turn() == this->_name){
            this->coins_player++;
            this->last_operation = "income";
            // cout<<"curr"<<this->_game.get_current_player()<<endl;
            this->_game.set_current_player();
            // cout<<"curr"<<this->_game.get_current_player()<<endl;
        }else{
            throw runtime_error("its not " + this->_name + " turn to play");
        }
}
    void Player::foreign_aid(){ // if the player blocked when he take foreign_aid its turn finish
        if(this->_game.turn() == this->_name){
        this->coins_player+=2;
        this->last_operation = "foreign_aid";
        this->_game.set_current_player();
        
        }else{
            ("its not " + this->_name + " turn to play");
        }
    }
    void Player::coup(Player &player){
        if(this->_game.turn() == this->_name){
            this->coins_player-=7;
            this->_game.remove_player(player._name);
            this->last_operation = "coup";
            // cout<<"this->dismissed_player1 "<<this->dismissed_player<<endl;
            this->dismissed_player = "-" + player.get_name();
            // cout<<"this->dismissed_player2 "<<this->dismissed_player<<endl;
            this->_game.set_current_player();
        }else{
            throw runtime_error("you dont have enough money");
        }
    }
    // string Player::winner(Game game){
    //     return "";
    // }
    // string Player::role(){
    //     return this.player_role;
    // }
    int Player::coins(){
        return this->coins_player;
    }
    // void Player::block(Player const &player){
        
    // }
    string Player::get_last_operation(){
        return this->last_operation;
    }
    int Player::get_coins_player(){
        return this->coins_player;
    }
    string Player::get_name(){
        return this->_name;
    }
    string Player::get_player_role(){
        return this->player_role;
    }
    string Player::get_dismissed_player(){
        return this->dismissed_player;
    }
    int Player::get_money_before_operation(){
        return this->money_before_operation;
    }
    void Player::set_coins_player(int k){
        this->coins_player += k;
    }
    void Player::set_dismissed_player(string &name){
        this->dismissed_player = name;
    }
    string Player::change_name(string &name){
        string new_name = "";
        size_t k=0;
        for (size_t i = 1; i < name.size(); i++)
        {
            // string temp = ("" + (name[i]));
            new_name.append({name[i]}); 
        }
        return new_name;
    }
    ostream& operator<<(ostream& os,const Player &player){
        return os;
    }
    // void turn(){
    //     return;
    // }
    // string players(Game game){
    //     return "";
    // }
    // string winner(Game game){
    //     return "";
    // }
    // string role(){
    //     return "";
    // }
    // int coins(){
    //     return 0;
    // }
