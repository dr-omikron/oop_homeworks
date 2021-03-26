#include "IllegalCommand.h"

IllegalCommand::IllegalCommand(int invalidCom)
{
	m_invalidCom = invalidCom;
}

int IllegalCommand::GetCommand()
{
	return m_invalidCom;
}

std::string IllegalCommand::Error()
{
	return std::string("Error! Illegal command!");
}
