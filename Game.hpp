#pragma once//need this?
#include <iostream>
#include <stdlib.h>
#include <string>
#include "vector"
#include <map>
using namespace std;
namespace coup{
class Game{

// static unsigned long k;

    protected:
        map<string, string> players_dismissed;
        vector<string> players_name;
        unsigned long size;
        unsigned long current_player;
        // static int k;
        // Player player_play; //the player that is turn to play 

    public:
        Game();
        // Game(Game &game);
        string turn();
        vector<string> players();
        string winner(Game game);
        void add_player(string &n);
        unsigned long get_current_player();
        void set_current_player();
        void remove_player(string const &player);
        vector<string> get_players_name();
        void set_players_name(size_t i, string &name);
        // map<string, string> get_players_dismissed();
        // string role();
        // int coins();
        // friend std::ostream& operator<<(ostream& os,const Player &player);

};
}