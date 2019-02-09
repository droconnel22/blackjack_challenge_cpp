//
// Created by Dennis O'Connell on 2019-02-08.
//

#include <string>
#include <vector>
#include <iostream>
#include <set>

#include "Player.h"
#include "Card.h"
#include "Deck.h"

#ifndef HELLOMAIN_GAME_H
#define HELLOMAIN_GAME_H
class Game {
    public:
        Game(int numOfPlayers);
        void Play();
        void Reset();
        void Menu();


    private:
        void initalize();
        void playersDraw();
        void drawResults();
        int numOfPlayers;
        std::vector<Card*> cardsInPlay;
        std::vector<Player*> players;
        Deck deck;
        bool noWinner;
};


#endif //HELLOMAIN_GAME_H
