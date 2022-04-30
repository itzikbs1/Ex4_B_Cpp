#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "doctest.h"
using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;






    Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};


    TEST_CASE("Good input"){
        vector<string> players = game_1.players();
        CHECK(players.size() == 5);
        CHECK(game_1.turn() == "Moshe");
        duke.income();
        CHECK(game_1.turn() == "Yossi");
        assassin.income();
        CHECK(game_1.turn() == "Meirav");
        ambassador.income();
        CHECK(game_1.turn() == "Reut");
        captain.income();
        CHECK(game_1.turn() == "Gilad");
        contessa.income();

        CHECK(game_1.turn() == "Moshe");
        duke.foreign_aid();
        CHECK(game_1.turn() == "Yossi");
        assassin.income();
        CHECK(game_1.turn() == "Meirav");
        ambassador.foreign_aid();
        CHECK(game_1.turn() == "Reut");
        captain.foreign_aid();
        CHECK(game_1.turn() == "Gilad");
        contessa.foreign_aid();
        CHECK(duke.coins() == 3);
        CHECK(assassin.coins() == 2);
        CHECK(ambassador.coins() == 3);
        CHECK(captain.coins() == 3);
        
        // CHECK_THROWS(duke.coins() == 0); 
    }
    TEST_CASE("Bad input"){
        CHECK_THROWS(assassin.income());
        CHECK_THROWS(ambassador.foreign_aid());
        CHECK_THROWS(captain.income());
        CHECK_THROWS(contessa.foreign_aid());
        CHECK_THROWS(assassin.foreign_aid());
    }