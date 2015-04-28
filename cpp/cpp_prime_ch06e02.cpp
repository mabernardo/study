// cpp_prime_ch06e02.cpp
//
// Write a program that reads up to 10 donation values into an array of double . (Or, if
// you prefer, use an array template object.) The program should terminate input on
// non-numeric input. It should report the average of the numbers and also report
// how many numbers in the array are larger than the average.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

double average(double[], int);

int main()
{
    const int MAX_DONATIONS = 10;
    int count = 0;
    double donations[MAX_DONATIONS];

    cout << "Enter up to 10 donation values: ";
    while ((cin >> donations[count]) && count < MAX_DONATIONS)
        count++;

    double avg = average(donations, count);
    int above_avg = 0;

    for (int i = 0; i < count; i++)
    {
        if (donations[i] > avg)
            above_avg++;
    }

    cout << "Average donation: " << avg << endl;
    cout << "Donations above average: " << above_avg << endl;

    return 0;
}

double average(double values[], int count)
{
    if (count == 0)
        return 0.0;

    double avg = 0.0;
    for (int i = 0; i < count; i++)
    {
        avg += values[i];
    }
    return avg / count;
}
