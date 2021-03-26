#include "Bar.h"
#include "Ex.h"

int Bar::Set(int a)
{
	if ((m_y + a) > 100)
	{
		Ex ex (a * m_y);
		throw ex;
	}
	else
	{
		m_y = a;
	}
	return m_y;
}
