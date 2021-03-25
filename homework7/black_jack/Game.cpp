#include "Game.h" 
#include "..\Black_Jack\Game.h"
using namespace std;


Game::Game(const vector<string>& names)
{
    for (auto name : names)
    {
        m_players.push_back(name);
    }
    
    m_deck.shuffle();
}

void Game::play()
{    
    const int startCardCount = 2;
    for (int i = 0; i < startCardCount; ++i)
    {
        for (int j = 0; j < m_players.size(); ++j)
        {
            m_deck.deal(m_players[j]);
        }
        m_deck.deal(m_house);
    }
    
    m_house.flipFirstCard();
        
    for (int i = 0; i < m_players.size(); ++i)
    {
        cout << m_players[i] << endl;
    }
    cout << m_house << endl;
    
    for (int i = 0; i < m_players.size(); ++i)
    {
        m_deck.additionalCards(m_players[i]);
    }
        
    m_house.flipFirstCard();
    
    cout << endl << m_house;
        
    m_deck.additionalCards(m_house);
        
    if (m_house.isBusted())
    {
        for (int i = 0; i < m_players.size(); ++i)
        {
            if (!(m_players[i].isBusted()))
            {
                m_players[i].winsCounter();
                m_players[i].win();
            }
        }
    }
    else
    {
        for (int j = 0; j < m_players.size(); ++j)
        {
            if (!(m_players[j].isBusted()))
            {
                if (m_players[j].getTotal() > m_house.getTotal())
                {
                    m_players[j].winsCounter();
                    m_players[j].win();
                }
                else if (m_players[j].getTotal() < m_house.getTotal())
                {
                    m_players[j].losesCounter();
                    m_players[j].lose();
                }
                else
                {
                    m_players[j].push();
                }
            }
        }

    }
        
    for (int i = 0; i < m_players.size(); ++i)
    {
        m_players[i].clear();
    }
    m_house.clear();
}


