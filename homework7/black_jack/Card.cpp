
#include "Card.h"

using namespace std;

Card::Card(rank r /*= ACE*/, suit s, bool ifu)
    : m_rank(r), m_suit(s), m_isFaceUp(ifu) {
}

int Card::getValue() const
{
    int value = 0;
    if (m_isFaceUp)
    {
        value = m_rank;
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "Ò", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "Â", "Ä", "Ê" };
    const string SUITS[] = { "|Ê", "|Á", "|×", "|Ï" };

    if (aCard.m_isFaceUp)
    {
        os << RANKS[aCard.m_rank] << SUITS[aCard.m_suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}