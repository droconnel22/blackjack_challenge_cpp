//
// Created by Dennis O'Connell on 2019-02-08.
//

#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>


#include "Card.h"
#include "Deck.h"


void Deck::Build() {

    // [Ace:2:10:J:Q:K]

    // aces
    for(int suite = 0; suite <4; suite++)
    {
        deck[suite][0] = new Card("ace", 11, this->suites[suite], suite % 2 == 0);
    }

    // numericals
    for(int suite = 0; suite <4; suite++)
    {
        for(int num = 1; num < 10; num++){
            deck[suite][num] = new Card(std::to_string(num+1), num+1, this->suites[suite], suite % 2 == 0);
        }
    }

    // jokers
    for(int suite = 0; suite <4; suite++)
    {
        deck[suite][10] = new Card("joker", 10, this->suites[suite], suite % 2 == 0);
    }

    // queens
    for(int suite = 0; suite <4; suite++)
    {
        deck[suite][11] = new Card("queen", 10, this->suites[suite], suite % 2 == 0);
    }

    // kings
    for(int suite = 0; suite <4; suite++)
    {
        deck[suite][12] = new Card("king", 10, this->suites[suite], suite % 2 == 0);
    }
}

Card* Deck::GetRandomCard()
{
    std::srand(std::time(NULL));
    int randomSuite = std::rand() % 4;
    int randomType = std::rand() % 12;
    std::cout << "\n Player drew "<< randomSuite << " " << randomType << std::endl;
    return deck[randomSuite][randomType];
}

// https://stackoverflow.com/questions/9459035/why-does-rand-yield-the-same-sequence-of-numbers-on-every-run
Deck::Deck() {

}

