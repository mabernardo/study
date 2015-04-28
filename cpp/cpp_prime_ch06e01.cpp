// cpp_prime_ch06e01.cpp
//
// Write a program that reads keyboard input to the @ symbol and that echoes the
// input except for digits, converting each uppercase character to lowercase, and vice
// versa. (Don’t forget the cctype family.)
//
#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    char ch;

    while ((cin.get(ch)) && ch != '@')
    {
        if (!isdigit(ch))
        {
            ch = (isupper(ch) ? tolower(ch) : toupper(ch));
            cout << ch;
        }
    }
    return 0;
}

