#include <iostream>


#include "./Blackjack/Game.h"

int main() {
    std::cout << "Welcome To Blackjack!" << std::endl;

    Game* game = new Game(3);

    game->Play();

    return 0;
}