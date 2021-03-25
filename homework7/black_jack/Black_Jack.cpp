
#include <iostream> 
#include <vector>
#include <set> 
#include <string> 

#include "Game.h" 

using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    cout << "\n\n\t\t<< Сыграем в Блек Джек! >>\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "Выберете количество игроков (1 - 7): ";
        cin >> numPlayers;
        cin.clear();
        cin.ignore(20, '\n');
    }

    vector<string> names;
    string name;
    for (int i = 1; i <= numPlayers; ++i)
    {
        cout << "Введите имя игрока " << i << ": ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.play();
        cout << "\nХотите сыграть еще? (Y/N): " << std::endl;
        cin >> again;
    }

    return 0;
}

