#pragma once
#include <iostream>
#include <string>
#include "Hand.h"

class GenericPlayer : public Hand
{
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const std::string& name = "");
    virtual ~GenericPlayer();
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void bust() const;
    void winsCounter();
    void losesCounter();
protected:
    std:: string m_name;
    int m_total;
    int m_wins = 0;
    int m_loses = 0;
};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);