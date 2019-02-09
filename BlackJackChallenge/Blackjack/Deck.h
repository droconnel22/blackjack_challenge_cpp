//
// Created by Dennis O'Connell on 2019-02-08.
//

#include<random>
#include <string>
#include <vector>
#include "Card.h"

#ifndef HELLOMAIN_DECK_H
#define HELLOMAIN_DECK_H
class Deck {
    public:
        Deck();
        void Build();
        Card* GetRandomCard();

private:
    Card* deck[4][13];
    std::string suites[4]{"hearts","clovers","diamonds","pikes"};



};

#endif //HELLOMAIN_DECK_H
