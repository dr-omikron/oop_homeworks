#include "Field.h"

Field::Field()
{
	m_fValues.assign(10, Field::SPACE);
	m_field.assign (10, m_fValues);
}

void Field::SetField(int with, int height)
{
	m_fValues.assign(with, Field::SPACE);
	m_field.assign(height, m_fValues);
}
