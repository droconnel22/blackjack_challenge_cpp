//
// Created by Dennis O'Connell on 2019-02-08.
//
#include <string>

#ifndef HELLOMAIN_CARD_H
#define HELLOMAIN_CARD_H

class Card {
private:
    int value;
    std::string suite;
    bool isRed;
    std::string type;
public:
    Card(std::string type, int value, std::string suite, bool isRed);
    int GetValue();
    std::string GetSuite();
    bool GetColor();
    std::string GetCardName();
    bool operator< (const Card &right) const;

};


#endif //HELLOMAIN_CARD_H