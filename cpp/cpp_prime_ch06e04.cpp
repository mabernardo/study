// cpp_prime_ch06e04.cpp
/*
When you join the Benevolent Order of Programmers, you can be known at BOP
meetings by your real name, your job title, or your secret BOP name. Write a pro-
gram that can list members by real name, by job title, by secret name, or by a mem-
ber’s preference. Base the program on the following structure:
// Benevolent Order of Programmers name structure
struct bop {
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

In the program, create a small array of such structures and initialize it to suitable
values. Have the program run a loop that lets the user select from different alterna-
tives:
a. display by name      b. display by title
c. display by bopname   d. display by preference
q. quit

Note that “display by preference” does not mean display the preference member; it
means display the member corresponding to the preference number. For instance, if
preference is 1 , choice d would display the programmer’s job title. A sample run
may look something like the following:
Benevolent Order of Programmers Report
a. display by name      b. display by title
c. display by bopname   d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!
*/
#include <iostream>
#include <cstring>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::array;

const int SIZE = 30;
const int ARRAY_SIZE = 2;

struct bop
{
    char fullname[SIZE];    // real name
    char title[SIZE];       // job title
    char bopname[SIZE];     // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

void show_menu();
void display_bop(bop*, char);

int main()
{
    char ch;
    bop bs[] = {
        { "Marcio Bernardo", "System Architect", "NiteWolf", 2},
        { "Jon Snow", "Lead Designer", "Jon", 1},
    };

    show_menu();
    do
    {
        cout << "Enter your choice: ";
        cin >> ch;
        display_bop(bs, ch);

    } while (ch != 'q' && ch != 'Q');
    return 0;
}


void show_menu()
{
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name\tb. display by title" << endl;
    cout << "c. display by bopname\td. display by preference" << endl;
    cout << "q. quit" << endl;
}

void display_bop(bop* bs, char ch)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        switch (ch)
        {
            case 'a':
            case 'A':
                cout << bs[i].fullname << endl;
                break;
            case 'b':
            case 'B':
                cout << bs[i].title << endl;
                break;
            case 'c':
            case 'C':
                cout << bs[i].bopname << endl;
                break;
            case 'd':
            case 'D':
                switch (bs[i].preference)
                {
                    case 0:
                        cout << bs[i].fullname << endl;
                        break;
                    case 1:
                        cout << bs[i].title << endl;
                        break;
                    case 2:
                        cout << bs[i].bopname << endl;
                        break;
                    default:
                        cout << bs[i].fullname << ": Invalid preference" << endl;
                }
                break;
        }
    }
}
