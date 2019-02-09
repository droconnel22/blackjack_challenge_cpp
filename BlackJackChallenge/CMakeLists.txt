cmake_minimum_required(VERSION 3.13)
project(HelloMain)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloMain main.cpp Node.h cmake-build-debug/Node.cpp Blackjack/Card.h Blackjack/Card.cpp Blackjack/Player.h Blackjack/Player.cpp Blackjack/Deck.h Blackjack/Deck.cpp Blackjack/Game.h Blackjack/Game.cpp)