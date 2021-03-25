
#include "Hand.h"

void Hand::add(Card* pCard)
{
    m_cards.push_back(pCard);
}

void Hand::clear()
{
    for (auto *cards : m_cards)
    {
        if (!(m_cards.empty()))
        {
            delete cards;
            cards = nullptr;
        }
    }
    m_cards.clear();
}


int Hand::getTotal() const
{
    
    if (m_cards.empty())
        return 0;

    if (m_cards[0]->getValue() == 0)
        return 0;
        
    int total = 0;
   
    for (int i = 0; i < m_cards.size(); ++i)
    {
        total += m_cards[i]->getValue();
    }
        
    bool containsAce = false;
    for (int i = 0; i < m_cards.size(); ++i)
    {
        if (m_cards[i]->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
       
    if (containsAce && total <= 11)
    {
       total += 10;
    }

    return total;
}