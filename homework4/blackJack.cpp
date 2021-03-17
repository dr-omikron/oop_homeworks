#include <iostream>
#include <vector>

class Card
{
public:
    enum Suit
    {
        Hearts,
        Spades,
        Clubs,
        Diamonds

    };
    enum Rank
    {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King

    };
    Card(Rank r, Suit s, bool fU);
    void Flip() { m_faceUp = !(m_faceUp); }
    int GetValue() const;
private:
    Suit m_suit;
    Rank m_rank;
    bool m_faceUp;
};

class Hand 
{
protected:
    std::vector<Card*> m_cards;
public:
    Hand() { m_cards.reserve(7); }
    void Add (Card *newCard);
    int GetTotal() const;
    void Clear();
    virtual ~Hand() { Clear(); }
};

Card::Card(Rank r, Suit s, bool fU)
    :m_rank(r), m_suit(s), m_faceUp(fU){}

int Card::GetValue() const
{
    int value = 0;
    if (m_faceUp)
    {
        value = m_rank;
        if (value > 10) { value = 10; }
    }
    return value;
}

void Hand::Add(Card *newCard)
{
    m_cards.push_back(newCard);
}
int Hand::GetTotal() const
{
    if (m_cards.empty()) {return 0;}
    if (m_cards[0]->GetValue() == 0) {return 0;}
    int total = 0;
    std::vector<Card *>::const_iterator it;
    for (it = m_cards.begin(); it != m_cards.end(); ++it)
    {
        total += (*it)->GetValue();
    }
    bool containsAce = false;
    for (it = m_cards.begin(); it != m_cards.end(); ++it)
    {
        if ((*it)->GetValue() == Card::Ace)
        {
            containsAce = true;
        }
    }
    if (containsAce && total <= 11) {total += 10;}
    return total;
}
void Hand::Clear()
{
    std::vector<Card *>::iterator it = m_cards.begin();
    for (it = m_cards.begin(); it != m_cards.end(); ++it)
    {
        delete *it;
        *it = 0;
    }
    m_cards.clear();
}

int main()
{
    
}

