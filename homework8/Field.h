#pragma once

#include <vector>

class Field
{
protected:
	enum FieldValue { SPACE, ROBOT };
	std::vector <std::vector<FieldValue>> m_field;
	std::vector <FieldValue> m_fValues;
public:
	Field();
	void SetField(int with, int height);
	virtual void Print() = 0;
};

