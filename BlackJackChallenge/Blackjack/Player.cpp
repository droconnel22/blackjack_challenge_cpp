//
// Created by Dennis O'Connell on 2019-02-08.
//

#include <vector>
#include <string>

#include "Card.h"
#include "Player.h"

Player::Player(std::string name) {
    this->name = name;
    this->cardCount = 0;
    this->handValue = 0;
}

void Player::DrawCard(Card* card) {
    this->hand.push_back(card);
    this->cardCount++;
    this->handValue += card->GetValue();

}

int Player::GetCardCount() {
    return this->cardCount;
}

int Player::GetHandValue() {
    return this-> handValue;
}

std::vector<Card*> Player::GetCards() {
    return this->hand;
}

std::string Player::GetName() {
    return this->name;
}


