#include <iostream>
#include <stdlib.h>
#include <string>
#include "Duke.hpp"


using namespace std;
using namespace coup;

    // Duke::Duke(){
    //     Duke::_name = "default name";
    //     Duke::_game = Game();
    // }
    // Duke::Duke(Game game, string &name){
    //     Duke::_name = name;
    //     Duke::_game = game;
    // }
    // Duke::Duke(Game game, string name){
    //     Duke::_name = move(name);
    //     Duke::_game = game;
    // }
    void Duke::block(Player &player){
        if(player.get_last_operation() == "foreign_aid"){
            player.set_coins_player(-2); // need to check if the coins player need to be greather then 0 ???
        }else{
            throw runtime_error("the last operation of the player is not foreign_aid");
        }
    }
    void Duke::tax(){
        this->coins_player+=3;
        this->_game.set_current_player();
    }
