#include <iostream>
#include <stdlib.h>
#include <string>
#include "vector"
#include "Game.hpp"
#include <algorithm>

using namespace std;
using namespace coup;


    Game::Game(){
        this->size=0;
        this->current_player=0;
        this->game_started = false;
    }
    string Game::turn(){
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

    string Game::winner() const{
        string winn;
        int Participants=0;
        if(this->get_players_name().size() == 1){
             throw runtime_error("the game still running");
        }
        for (size_t i = 0; i < this->get_players_name().size(); i++)
        {
            if(*this->get_players_name()[i].begin() != '-'){
                Participants++;
                winn = this->get_players_name()[i];
            }
        }if(Participants>1){
            throw runtime_error("the game still running");
        }
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