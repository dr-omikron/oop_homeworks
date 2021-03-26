#pragma once
#include <string>
#include "Robot.h"

class OffTheField
{
protected:
	int m_robotPosX;
	int m_robotPosY;
	int m_invalidCom;
public:
	OffTheField();
	OffTheField(int x, int y);
	std::string RobotPosition();
	void GetDirection(int command);
	virtual std::string Error();
};

