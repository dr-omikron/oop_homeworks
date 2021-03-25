#include "GenericPlayer.h"

using namespace std;

GenericPlayer::GenericPlayer(const string& name) :
    m_name(name) {}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}

void GenericPlayer::bust() const
{
    cout << "\n" << m_name << " перебор!\n";
}

void GenericPlayer::winsCounter()
{
    m_wins++;
}

void GenericPlayer::losesCounter()
{
    m_loses++;
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << "\n" << ">" << aGenericPlayer.m_name << ":\t";
        
    if (!aGenericPlayer.m_cards.empty())
    {
        for (Card* card : aGenericPlayer.m_cards)
        {
            os << *card << "\t";
        }

        if (aGenericPlayer.getTotal() != 0)
        {
            cout << "Всего очков: " << aGenericPlayer.getTotal();
        }
    }
    else
    {
        os << "<Пусто>";
    }

    return os;
}