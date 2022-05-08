#pragma once
#include <iostream>
#include <map>
#include "Game.hpp"

using namespace std;
namespace coup{
class Player{

    public:
        const int seven = 7;
        const int ten = 10;
    protected:
        string _name;
        Game &_game;
        int coins_player;
        string player_role;
        string last_operation;
        string dismissed_player;
        int money_before_operation;
        public:
        Player *stolen_player;

    public:
    Player(Game &game, string &name);
        void income();
        void foreign_aid();
        virtual void coup(Player &player);
        string role() const; 
        int coins() const;
        string get_last_operation() const;
        int get_coins_player() const;
        string get_player_role() const;
        void set_coins_player(int k);
        string get_name() const;
        string get_dismissed_player() const;
        int get_money_before_operation() const;
        void set_dismissed_player(string &name);
        static string change_name(string &name); 
        friend std::ostream& operator<<(ostream& os,const Player &player);
        static bool still_in_game(Player &player);
};
}