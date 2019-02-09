//
// Created by Dennis O'Connell on 2019-02-08.
//

#include <string>
#include "./Card.h"

Card::Card(std::string type, int value, std::string suite, bool isRed) {
    this->type = type;
    this->value = value;
    this->suite = suite;
    this->isRed = isRed;
}

bool Card::GetColor() {
    return  this->isRed;
}

std::string Card::GetSuite() {
    return  this->suite;
}

int Card::GetValue() {
    return  this->value;
}

std::string Card::GetCardName() {
    return this->type  + " of " + this->suite + " ";
}

bool Card::operator< (const Card &right) const
{
    return suite+type < right.suite+right.type;
}