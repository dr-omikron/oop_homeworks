#include <iostream>
#include <vector>

class Card
{
public:
    enum Suit { HEARS, SPADES, CLUBS, DIAMONDS };
    enum Rank
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX,
        SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    };
    Card();
    Card(Rank r, Suit s, bool fU);
    void Flip() { m_faceUp = !(m_faceUp); }
    int GetValue() const;
    friend std::ostream &operator << (std::ostream &os, const Card &pCard);
private:
    Suit m_suit;
    Rank m_rank;
    bool m_faceUp;
};
class Hand : public Card
{
protected:
    std::vector<Card *> m_cards;
public:
    Hand() { m_cards.reserve(7); }
    void Add(Card *newCard);
    int GetTotal() const;
    void Clear();
    virtual ~Hand() { Clear(); }
};
class GenericPlayer : public Hand
{
protected:
    std::string m_name;
public:
    GenericPlayer(const std::string &name = "") :m_name(name) {}
    friend std::ostream &operator<<(std::ostream &os, const GenericPlayer &pGenericPlayer);
    virtual bool IsHitting() const = 0;
    bool IsBusted() const { return (GetTotal() > 21); }
    void Bust() const { std::cout << m_name << " bust!\n"; }
    virtual ~GenericPlayer() {}
};
class Player : public GenericPlayer
{
public:
    Player(const std::string &name) : GenericPlayer(name) {};
    virtual bool IsHitting() const;
    void Win() const { std::cout << m_name << " wins!\n"; }
    void Lose() const { std::cout << m_name << " loses!\n"; }
    void Draw() const { std::cout << "Draw!\n"; }
    virtual ~Player() {}
};
class House : public GenericPlayer
{
public:
    House(const std::string &name = "House") {}
    virtual bool IsHitting() const { return (GetTotal() <= 16); }
    void FlipFirstCard();
    virtual ~House() {}
};
Card::Card()
{
    m_suit = SPADES;
    m_rank = ACE;
    m_faceUp = true;
}

Card::Card(Rank r, Suit s, bool fU)
    :m_rank(r), m_suit(s), m_faceUp(fU) {}

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
    if (m_cards.empty()) { return 0; }
    if (m_cards[0]->GetValue() == 0) { return 0; }
    int total = 0;
    std::vector<Card *>::const_iterator it;
    for (it = m_cards.begin(); it != m_cards.end(); ++it)
    {
        total += (*it)->GetValue();
    }
    bool containsAce = false;
    for (it = m_cards.begin(); it != m_cards.end(); ++it)
    {
        if ((*it)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
    if (containsAce && total <= 11) { total += 10; }
    return total;
}
void Hand::Clear()
{
    for (int i = 0; i < m_cards.size(); ++i)
    {
        delete m_cards[i];
    }
    m_cards.clear();
}
std::ostream &operator << (std::ostream &os, const Card &pCard)
{
    const char rankSym[]{ '0', 'A', '2', '3', '4', '5',
               '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
    const char suitSym[]{ 'H', 'C', 'S', 'D' };
    if (pCard.m_faceUp)
    {
        os << rankSym[pCard.m_rank] << suitSym[pCard.m_suit];
    }
    else { os << "XX"; }
    return os;
}
std::ostream &operator<<(std::ostream &os, const GenericPlayer &pGenericPlayer)
{
    os << pGenericPlayer.m_name << ":\t";
    if ((!pGenericPlayer.m_cards.empty()))
    {
        for (int i = 0; i < pGenericPlayer.m_cards.size(); ++i)
        {
            os << *(pGenericPlayer.m_cards.at(i)) << " ";
        }

        if (pGenericPlayer.GetTotal() != 0)
        {
            std::cout << "(" << pGenericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "[empty]";
    }
    return os;
}
bool Player::IsHitting() const
{
    std::cout << m_name << ", do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}
void House::FlipFirstCard()
{
    if (!m_cards.empty())
    {
        m_cards[0]->Flip();
    }
    else
    {
        std::cout << "No card to flip!\n";
    }
}

int main()
{
   
    Hand hand;

    Player player("Andrey");
    player.Add(new Card(Card::JACK, Card::HEARS, true));
    player.Add(new Card(Card::QUEEN, Card::DIAMONDS, true));
    player.Add(new Card(Card::THREE, Card::SPADES, true));
    std::cout << player;
    
}





