#pragma once
#include <iostream>
#include <map>
#include "Game.hpp"

using namespace std;
namespace coup{
class Player{

    protected:
        // vector<Player<vector<string>>> players_dismissed;
        // map<string, Player> players_dismissed;
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
        // Player();
        // Player(Game game, string name) : _game(game), _name(name) {}//, _game.add_player(name) {}
        Player(Game &game, string &name) : _game(game), _name(name){
            game.add_player(name);
            this->coins_player = 0;
            // this->player_role = "Duke";
            this->dismissed_player = "";
            this->last_operation = "";
            this->money_before_operation = 0;
            // this->stolen_player = NULL;
        }
        // Player(Game &game, string &name, string role = "Player");
        //        // cout<<"game   "<<&game<<endl;
        // // this->_game = game;
        // _game(game);
        // // cout<<"game!  "<<&(this->_game)<<endl;
        // this->_name = name;
        // this->coins_player = 0;
        // this->player_role = role;
        // this->_game.add_player(name);
        // }
        void income();
        void foreign_aid();
        virtual void coup(Player &player);
        // void turn();
        // string players(Game game);
        // string winner(Game game);
        string role(); //name of the role
        int coins();
        string get_last_operation();
        int get_coins_player();
        string get_player_role();
        void set_coins_player(int k);
        string get_name();
        string get_dismissed_player();
        int get_money_before_operation();
        void set_dismissed_player(string &name);
        string change_name(string &name); 
        // void block(Player const &player);
        friend std::ostream& operator<<(ostream& os,const Player &player);
        // friend std::istream& operator>>(istream& in, Player &player);
};
}