//
// Created by Dennis O'Connell on 2019-02-08.
//

#ifndef HELLOMAIN_PLAYER_H
#define HELLOMAIN_PLAYER_H

#include <vector>
#include <string>

#include "Card.h"


class Player {
    public:
        Player(std::string name);
        void DrawCard(Card* card);
        int GetHandValue();
        int GetCardCount();
        std::vector<Card*> GetCards();
        std::string GetName();

    private:
        int handValue;
        int cardCount;
        std::vector<Card*> hand;
        std::string name;
};

#endif //HELLOMAIN_PLAYER_H
