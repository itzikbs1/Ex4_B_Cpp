#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "vector"
#include <map>
using namespace std;
namespace coup{
class Game{

    protected:
        vector<string> players_name;
        unsigned long size;
        unsigned long current_player;
        bool game_started;

    public:
        Game();
        string turn();
        vector<string> players();
        string winner() const;
        void add_player(string &n);
        unsigned long get_current_player() const;
        void set_current_player();
        void remove_player(string const &player);
        vector<string> get_players_name() const;
        void set_players_name(size_t i, string &name);
        bool get_game_strated() const;
        void set_game_strated(bool ans);

};
}