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

    public:
        Game();
        string turn();
        vector<string> players();
        static string winner(Game const &game);
        void add_player(string &n);
        unsigned long get_current_player() const;
        void set_current_player();
        void remove_player(string const &player);
        vector<string> get_players_name() const;
        void set_players_name(size_t i, string &name);

};
}