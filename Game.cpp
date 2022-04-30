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

    string Game::winner(Game const &game){
        string winn = game.get_players_name()[0];
        for (size_t i = 1; i < game.get_players_name().size(); i++)
        {
            /* code */
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