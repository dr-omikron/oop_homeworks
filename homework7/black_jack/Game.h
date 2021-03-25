#pragma once
#include <string>
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
public:
    Game(const std::vector<std::string>& names);
    void play();
 private:
    std::vector<Player> m_players;
    House m_house;
    Deck m_deck;
};
