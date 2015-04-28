// cpp_prime_ch06e03.cpp
/*
Write a precursor to a menu-driven program.The program should display a menu
offering four choices, each labeled with a letter. If the user responds with a letter
other than one of the four valid choices, the program should prompt the user to
enter a valid response until the user complies. Then the program should use a
switch to select a simple action based on the user’s selection. A program run could
look something like this:
Please enter one of the following choices:
c) carnivore p) pianist
t) tree      g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree.
*/
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

void show_menu();
bool valid_choice(char);

int main()
{
    char ch;

    show_menu();
    do
    {
        cout << "Please enter a c, p, t or g: ";
        cin >> ch;

        switch (ch)
        {
            case 'c':
            case 'C':
                cout << "A tiger is a carnivore." << endl;
                break;
            case 'p':
            case 'P':
                cout << "Mozart was a pianist." << endl;
                break;
            case 't':
            case 'T':
                cout << "A maple is a tree." << endl;
                break;
            case 'g':
            case 'G':
                cout << "Portal 2 is a game." << endl;
                break;
        }
    } while (!valid_choice(ch));
    return 0;
}


void show_menu()
{
    cout << "Please enter one of the following choices:" << endl;
    cout << "c) carnivore\tp) pianist" << endl;
    cout << "t) tree\tg) game" << endl;
}

bool valid_choice(char ch)
{
    ch = tolower(ch);
    return (ch == 'c' || ch == 'p' || ch == 't' || ch == 'g');
}
