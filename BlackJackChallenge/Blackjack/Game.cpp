//
// Created by Dennis O'Connell on 2019-02-08.
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <math.h>

#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"

Game::Game(int numOfPlayers) {
    this->numOfPlayers = numOfPlayers;
    this->initalize();
}

void Game::Play() {
    while(this->noWinner)
    {
        this->playersDraw();
        this->drawResults();
    }
    this->Menu();
}

void Game::Reset() {

    this->players.clear();
    this->cardsInPlay.clear();

}

void Game::initalize() {
    std::cout << "Starting the game..." << std::endl;
    this->noWinner = true;
    deck.Build();
    std::string names[3]{"Bob", "Mary", "John"};
    for(int i = 0; i < this->numOfPlayers; i++){
        Player *player = new Player(names[i]);
        this->players.push_back(player);
    }
}

void Game::playersDraw(){
    // go round

    std::vector<Player*>::iterator playerIterator;
    for (playerIterator = this->players.begin(); playerIterator < this->players.end(); playerIterator++)
    {

        Player* currentPlayer = *playerIterator;
        std::cout << currentPlayer->GetName() << "--------------------------------------"  << std::endl;
        std::string result = "";
        std::cout << "Press 1 to Draw and any key to skip" << std::endl;
        std::cin >> result;

        if (result == "1") {
            Card *card;

            bool pickingCard = true;
            while(pickingCard)
            {
                card = this->deck.GetRandomCard();

                std::vector<Card*>::iterator handIter;

                pickingCard = false;
                for(handIter = this->cardsInPlay.begin(); handIter != this->cardsInPlay.end(); handIter++){
                    if(card == *handIter){
                        std::cout << "\n Card already exits trying again..." << std::endl;
                        pickingCard = true;
                    }
                }
            }

            this->cardsInPlay.push_back(card);
            currentPlayer->DrawCard(card);
            std::cout << "\nCurrent Player: " << currentPlayer->GetName() << "  Drew " << card->GetCardName() << std::endl;
        }

    }

}

void Game::drawResults() {
    // check victory
    int winnerCount =0;
    std::vector<Player*>::iterator playerIterator2;
    std::cout << "--------------------------------------"  << std::endl;
    for (playerIterator2 = this->players.begin(); playerIterator2 < this->players.end(); playerIterator2++)
    {
        Player *currentPlayer = *playerIterator2;

        std::vector<Card *> playerCards = currentPlayer->GetCards();
        std::vector<Card *>::iterator playerCardsIter;

        int value = 0;
        int numOfCards = currentPlayer->GetCardCount();
        int results[2]{0, 0};
        std::cout << "\n" << std::endl;
        for (playerCardsIter = playerCards.begin(); playerCardsIter != playerCards.end(); playerCardsIter++)
        {
            Card *currentCard = *playerCardsIter;

            if (currentCard->GetValue() == 11) {
                results[1] += 1;
            } else {
                results[0] += currentCard->GetValue();
            }

            std::cout << currentCard->GetCardName() << ", ";
        }

        if (results[1] > results[0] && results[1] <= 21) {
            value = results[1];
        } else {
            value = results[0];
        }

        std::cout<< "\n Player: " << currentPlayer->GetName()  << " Total: " << value << std::endl;

        if (value == 21){
            std::cout << "Player " << currentPlayer->GetName() << " has won" << std::endl;
            this->noWinner = false;
            winnerCount++;


        } else if(numOfCards == 5 && value <= 21) {
            std::cout << "Player " << currentPlayer->GetName() << " has won with 5 card trick" << std::endl;
            this->noWinner = false;
            winnerCount++;


        } else if (value > 21) {
            std::cout << "Player has busted removed from game!"<< std::endl;

            this->players.erase(playerIterator2);
            if(this->players.size() ==0){
                this->noWinner = false;
            }
        }
    }

    if(this->noWinner == false ){
        if(winnerCount > 1) {
            std::cout << "TIE !" << std::endl;
        } else if(winnerCount == 0){
            std::cout << "No winners"<< std::endl;
        }
    }
}

void Game::Menu() {

    std:: cout << "Type yes to play again or press any key to exit" << std::endl;
    std::string input;
    std::cin >> input;
    if(input == "yes"){
        this->Reset();
        this->Play();
    }

    std::cout << "Thanks for playing" << std::endl;
}