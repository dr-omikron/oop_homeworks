#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) :
    GenericPlayer(name) {}

bool Player::isHitting() const
{
    cout << "\n" << "> " << m_name << ", еще карту? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << "\n" << "> " << m_name << " выйграл!\n";
    cout << "Побед: " << m_wins << "   Поражений: " << m_loses << endl;
}

void Player::lose() const
{
    cout << "\n" << "> " << m_name << " проиграл!\n";
    cout << "Побед: " << m_wins << "   Поражений: " << m_loses << endl;
}

void Player::push() const
{
    cout << "\n" << "> " << m_name << ". Ничья!\n";
}