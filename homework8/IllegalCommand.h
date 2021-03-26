#pragma once
#include "OffTheField.h"

class IllegalCommand :
    public OffTheField
{
public:
    IllegalCommand(int invalidCom);
    int GetCommand();
    std::string Error();
};

