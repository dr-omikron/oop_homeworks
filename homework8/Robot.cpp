#include <iostream>
#include "Robot.h"
#include "IllegalCommand.h"
#include "OffTheField.h"

Robot::Robot()
{
    m_positionX = 0;
    m_positionY = 0;
    m_field[m_positionY][m_positionX] = Field::ROBOT;
}
unsigned int Robot::GetPositionX() const
{
    return m_positionX;
}

unsigned int Robot::GetPositionY() const
{
    return m_positionY;
}
void Robot::SetPosition(int command)
{
    int tempX = m_positionX;
    int tempY = m_positionY;
               
    switch (command)
    {
    case (Robot::LEFT) :
        tempX--;
        break;
    case (Robot::RIGH):
        tempX++;
        break;
    case (Robot::UP):
        tempY--;
        break;
    case (Robot::DOWN):
        tempY++;
        break;
    case (0):
        break;
    default:
        throw IllegalCommand(command);
    }

    if (tempY < 0 || tempY >= m_field.size() 
        || tempX < 0 || tempX >= m_fValues.size())
    {
        throw OffTheField (m_positionX, m_positionY);
    }
    m_field[tempY][tempX] = Field::ROBOT;
    m_field[m_positionY][m_positionX] = Field::SPACE;
    
    m_positionX = tempX;
    m_positionY = tempY;
}

void Robot::Print()
{
    const char s = '.';
    const char r = '*';

    for (int i = 0; i < m_field.size(); ++i)
    {
        for (int j = 0; j < m_fValues.size(); ++j)
        {
            if(m_field[i][j] == Field::ROBOT)
                std::cout << r <<" ";
            else
                std::cout << s <<" ";
        }
        std::cout << std::endl;
    }
}
