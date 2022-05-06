#include <iostream>
#include <stdlib.h>
#include <string>
#include "vector"
#include "Game.hpp"
#include <algorithm>

using namespace std;
using namespace coup;


    Game::Game(){
        // cout<<"heyG.c"<<this<<endl;
        this->size=0;
        this->current_player=0;
        this->game_started = false;
        // for (size_t i = 0; i < 5; i++)
        // {
        //     this->players_name.push_back("");
        //     this->size++;
        // }
        // cout<<"9G.c"<<endl;
    }
    // Game::Game(Game game){

    // }
    string Game::turn(){
        // cout<<"this->players_name.at((this->current_player%this->players_name.size()))[0]"<<this->players_name.at((this->current_player%this->players_name.size()))[0]<<endl;
        while(this->players_name.at((this->current_player%this->players_name.size()))[0] == '-'){
            this->current_player++;
        }
        string player_name = this->players_name.at((this->current_player%this->players_name.size()));
        return player_name;
    }
    vector<string> Game::players(){
        vector<string> now_play;
        for (size_t i = 0; i < this->players_name.size(); i++)
        {
            if(players_name[i][0] != '-'){
                now_play.push_back(players_name[i]);
            }
        }
        return now_play;
    }
    // ostream& operator<<(ostream& os,const Game &game){
    //     return os;
    // }

    string Game::winner() const{
        string winn;
        int Participants=0;
        if(this->get_players_name().size() == 1){
             throw runtime_error("the game still running");
        }
        for (size_t i = 0; i < this->get_players_name().size(); i++)
        {
            // cout<<"Game "<<this<<endl;
            // cout<<"*this->get_players_name()[i].begin() "<<*this->get_players_name()[i].begin()<<endl;
            if(*this->get_players_name()[i].begin() != '-'){
                // cout<<"55"<<endl;
                Participants++;
                winn = this->get_players_name()[i];
            }
        }if(Participants>1){
            throw runtime_error("the game still running");
        }

        // cout<<"Participants "<<Participants<<endl;
        return winn;
    }
    void Game::add_player(string &n){
        players_name.push_back(n);
    }
    unsigned long Game::get_current_player() const{
        return this->current_player;
    }
    vector<string> Game::get_players_name() const{
        return players_name;
    }
    bool Game::get_game_strated() const{
        return game_started;
    }
    void Game::set_game_strated(bool ans){
        game_started = ans;
    }
    void Game::set_current_player(){
        this->current_player++;
    }

    void Game::set_players_name(size_t i, string &name){
        this->players_name[i] = name;
    }

    void Game::remove_player(string const &player){

        for (size_t i = 0; i < this->players_name.size(); i++)
        {
            if(players_name[i] == player){
                players_name[i] = "-" + player;
            }
        }
        
    }