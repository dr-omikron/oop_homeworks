
#include <iostream>

#include "div_function.h"
#include "Ex.h"
#include "Bar.h"
#include "Robot.h"
#include "Field.h"
#include "OffTheField.h"
#include "IllegalCommand.h"

int main()
{
    //Ex1
    try
    {
        std::cout << Div(12, 0) << "\n";
    }
    catch (const char* ex)
	{
		std::cerr << "Error!" << ex << "\n";
	}
    //Ex2

    Bar bar;
    int num = 0;
    try
    {
        do {
            std::cin >> num;
            bar.Set(num);
        } while (num != 0);
    }
    catch (Ex &ex)
    {
        std::cout << "Error! " << ex.Data() << std::endl;
    }
    //Ex3

    Robot robot;
	int n = 1;
	std::cout << "Robot control:\n2 - down\n4 - left\n6 - right\n8 - up\n" << std::endl;
	while (n != 0)
	{
		robot.Print();
		std::cout << "\nEnter '0' to exit" << std::endl;
		std::cin >> n;
		try {
		    robot.SetPosition(n);
		}
		catch (IllegalCommand &illCom)
		{
			std::cout << illCom.Error() << std::endl;
			std::cout << "Your command: " << illCom.GetCommand() << std::endl;
			std::cout << illCom.RobotPosition() << std::endl;
		}
		catch (OffTheField &oft)
		{
			std::cout << oft.Error() << std::endl;
			std::cout << oft.RobotPosition() << std::endl;
			oft.GetDirection(n);
		}
	}

	


}
