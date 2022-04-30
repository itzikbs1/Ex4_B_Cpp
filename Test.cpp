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


    TEST_CASE("Good input"){
        Game game_1{};

        /* This player drew the "Duke" card, his name is Moshe
        and he is a player in game_1 */
        Duke duke{game_1, "Moshe"};
        Assassin assassin{game_1, "Yossi"};
        Ambassador ambassador{game_1, "Meirav"};
        Captain captain{game_1, "Reut"};
        Contessa contessa{game_1, "Gilad"};

        vector<string> players = game_1.players();
        CHECK(players.size() == 5);
        CHECK(game_1.turn() == "Moshe");
        duke.income();
        CHECK(game_1.turn() == "Yossi");
        assassin.income();
        CHECK(game_1.turn() == "Meirav");
        ambassador.income();
        CHECK(game_1.turn() == "Reut");
        captain.foreign_aid();
        CHECK(game_1.turn() == "Gilad");
        duke.block(captain);
        contessa.income();

        CHECK(game_1.turn() == "Moshe");
        duke.foreign_aid();
        CHECK(game_1.turn() == "Yossi");
        assassin.foreign_aid();
        CHECK(game_1.turn() == "Meirav");
        ambassador.foreign_aid();
        CHECK(game_1.turn() == "Reut");
        captain.foreign_aid();
        CHECK(game_1.turn() == "Gilad");
        contessa.foreign_aid();
        CHECK(duke.coins() == 3);
        CHECK(assassin.coins() == 3);
        CHECK(ambassador.coins() == 3);
        CHECK(captain.coins() == 2);
        duke.foreign_aid();
        assassin.coup(duke);

        players = game_1.players();
        vector <string> play_now;
        play_now.push_back("Yossi");
        play_now.push_back("Meirav");
        play_now.push_back("Reut");
        play_now.push_back("Gilad");
        size_t i=0;

        for(string name : players){
            CHECK(name == play_now[i++]);
        }
        contessa.block(assassin);
        players = game_1.players();
        play_now.clear();
        play_now.push_back("Moshe");
        play_now.push_back("Yossi");
        play_now.push_back("Meirav");
        play_now.push_back("Reut");
        play_now.push_back("Gilad");
        i=0;

        for(string name : players){
            CHECK(name == play_now[i++]);
        }
        CHECK(assassin.coins() == 0);
        ambassador.transfer(duke, assassin);
        CHECK(duke.coins() == 4);
        CHECK(assassin.coins() == 1);
        captain.steal(assassin);
        CHECK(assassin.coins() == 0);
        CHECK(captain.coins() == 3);
        ambassador.block(captain);
        CHECK(assassin.coins() == 1);
        CHECK(captain.coins() == 2);
        
        // CHECK_THROWS(duke.coins() == 0); 
    }
    TEST_CASE("Bad input"){
        Game game_1{};

        /* This player drew the "Duke" card, his name is Moshe
        and he is a player in game_1 */
        Duke duke{game_1, "Moshe"};
        Assassin assassin{game_1, "Yossi"};
        Ambassador ambassador{game_1, "Meirav"};
        Captain captain{game_1, "Reut"};
        Contessa contessa{game_1, "Gilad"};

        CHECK_THROWS(assassin.income());
        CHECK_THROWS(ambassador.foreign_aid());
        CHECK_THROWS(captain.income());
        CHECK_THROWS(contessa.foreign_aid());
        CHECK_THROWS(assassin.foreign_aid());

        duke.foreign_aid();
        assassin.foreign_aid();
        CHECK_THROWS(ambassador.transfer(captain, duke));
        CHECK_THROWS(ambassador.transfer(captain, contessa));
        CHECK_FALSE(game_1.turn() != "Meirav");
        CHECK_THROWS(captain.steal(contessa));
        ambassador.transfer(assassin, duke);
        captain.income();
        contessa.income();
        duke.foreign_aid();
        assassin.income();
        CHECK_THROWS(captain.income());
        ambassador.income();
        captain.income();
        contessa.income();

        duke.foreign_aid();
        assassin.foreign_aid();
        CHECK_FALSE(game_1.turn() != "Meirav");
        ambassador.transfer(assassin, duke);
        captain.income();
        contessa.income();
        duke.foreign_aid();
        assassin.income();
        CHECK_THROWS(captain.income());
        ambassador.income();
        captain.income();
        contessa.income();
        CHECK_THROWS(duke.foreign_aid());
        CHECK_THROWS(duke.income());
    }