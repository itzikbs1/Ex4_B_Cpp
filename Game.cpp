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
        // cout<<"16 game.cpp"<<endl;
        // cout<<"current_player "<<this->current_player<<endl;
        // cout<<"this->players_name.at((current_player%this->players_name.size()))"<<this->players_name.at((current_player%this->players_name.size()))<<endl;
        // cout<<"this->current_player "<<this->current_player<<endl;
        // cout<<"this->players_name.size() "<<this->players_name.size()<<endl;
        string player_name = this->players_name.at((this->current_player%this->players_name.size()));
        // cout<<"pla game.cpp "<<player_name<<endl;
        // k++;
        // cout<<"32!"<<endl;
        return player_name;
    }
    vector<string> Game::players(){
        vector<string> now_play;
        for (size_t i = 0; i < this->players_name.size(); i++)
        {
            // cout<<"players_name[i]"<<players_name[i][0]<<endl;
            // cout<<"-"<<endl;
            if(players_name[i][0] != '-'){
                now_play.push_back(players_name[i]);
            }
        }
        // return this->players_name;
        return now_play;
    }
    // ostream& operator<<(ostream& os,const Game &game){
    //     return os;
    // }

    string Game::winner(Game game){
        return "";
    }
    void Game::add_player(string &n){
        // cout<<"33G.c"<<endl;
        // cout<<"sfd"<<n<<endl;
        // cout<<"plasdsa"<<players_name[0]<<endl;
        players_name.push_back(n);
    }
    unsigned long Game::get_current_player(){
        return this->current_player;
    }
    // map<string, string> Game::get_players_dismissed(){
    //     return players_dismissed;
    // }
    vector<string> Game::get_players_name(){
        return players_name;
    }
    void Game::set_current_player(){
        this->current_player++;
    }

    void Game::set_players_name(size_t i, string &name){
        this->players_name[i] = name;
    }

    void Game::remove_player(string const &player){
        // int k=0;
        // this->players_name.erase(remove(this->players_name.begin(), this->players_name.end(), player), this->players_name.end());
        for (size_t i = 0; i < this->players_name.size(); i++)
        {
            if(players_name[i] == player){
                players_name[i] = "-" + player;
            }
        }
        
    }
    // string Game::role(){
    //     return "";
    // }
    // int Game::coins(){
    //     return 0;
    // }