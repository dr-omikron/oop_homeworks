#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) :
    GenericPlayer(name) {}

bool Player::isHitting() const
{
    cout << "\n" << "> " << m_name << ", ��� �����? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << "\n" << "> " << m_name << " �������!\n";
    cout << "�����: " << m_wins << "   ���������: " << m_loses << endl;
}

void Player::lose() const
{
    cout << "\n" << "> " << m_name << " ��������!\n";
    cout << "�����: " << m_wins << "   ���������: " << m_loses << endl;
}

void Player::push() const
{
    cout << "\n" << "> " << m_name << ". �����!\n";
}