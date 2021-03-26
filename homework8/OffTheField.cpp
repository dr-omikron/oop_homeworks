#include <iostream>
#include "OffTheField.h"
#include "Robot.h"

OffTheField::OffTheField()
{
    m_robotPosX = 0;
    m_robotPosY = 0;
}

OffTheField::OffTheField(int x, int y)
{
    m_robotPosX = x;
    m_robotPosY = y;
}

std::string OffTheField::RobotPosition()
{
    std::string curPos = "Curren position: X = " + std::to_string(m_robotPosX+1)
        + "; Y = " + std::to_string(m_robotPosY+1);
    return curPos;
}

void OffTheField::GetDirection(int command)
{
	switch (command)
	{
	case(2):
		std::cout << "Robot direction down" << std::endl;
		break;
	case(4):
		std::cout << "Robot direction left" << std::endl;
		break;
	case(6):
		std::cout << "Robot direction right" << std::endl;
		break;
	case(8):
		std::cout << "Robot direction up" << std::endl;
		break;
	default:
		std::cout << "Impossible to determine the direction!" << std::endl;
		break;
	}

}

std::string OffTheField::Error()
{
    return std::string("Error! Going out of bounds!");
}
