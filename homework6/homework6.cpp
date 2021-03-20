#include <iostream>
#include <sstream>
#include <ostream>

std::ostream &endll(std::ostream &end)
{
    std::cout << "\n" << std::endl;
    return end;
}

//Ex1

void PrintError()
{
   std::cout << "Invalid enter!\nEnter integer number, please> ";
}

int main()
{
    //Ex1

    std::cout << "Enter integer number> ";
    std::string str;
    std::cin >> str;
    bool f; 
    do
    {   
        f = str.find_first_not_of("0123456789") == std::string::npos;
        if (!f)
        {
            PrintError();
            std::cin >> str;
        }
    } while (!f);
    int in = 0;
    std::stringstream inString;
    inString << str;
    inString >> in;
    std::cout << "Entered number = " << in << std::endl;

    //Ex2
    std::cout<<"My manipulator"<< endll;
    std::cout << "endll";
    

    return EXIT_SUCCESS;
}