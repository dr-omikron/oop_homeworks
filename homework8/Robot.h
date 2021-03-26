#pragma once
#include "Field.h"

class Robot : public Field
{
private:
	unsigned int m_positionX;
	unsigned int m_positionY;
	enum Moves {  DOWN = 2, LEFT = 4, RIGH = 6, UP = 8	};
public:
	Robot();
	void SetPosition(int command);
	unsigned int GetPositionX() const;
	unsigned int GetPositionY() const;
	void Print() override;
};

