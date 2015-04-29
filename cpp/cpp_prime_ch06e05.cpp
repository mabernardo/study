// cpp_prime_ch06e05.cpp
/*
The Kingdom of Neutronia, where the unit of currency is the tvarp, has the fol-
lowing income tax code:
    First 5,000 tvarps: 0% tax
    Next 10,000 tvarps: 10% tax
    Next 20,000 tvarps: 15% tax
    Tvarps after 35,000: 20% tax
For example, someone earning 38,000 tvarps would owe 5,000 × 0.00 + 10,000 ×
0.10 + 20,000 × 0.15 + 3,000 × 0.20, or 4,600 tvarps.Write a program that uses a
loop to solicit incomes and to report tax owed.The loop should terminate when
the user enters a negative number or non-numeric input.*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::min;

double calculate_taxes(double);

int main()
{
    double income;

    cout << "Enter your income: ";
    while ((cin >> income) && income > 0.0)
    {
        double tax = calculate_taxes(income);
        cout << "You owe " << tax << " tvarps in taxes." << endl;
        cout << "Enter your income: ";
    }
    return 0;
}

double calculate_taxes(double income)
{
    double tax_code[4][2] = {
        { 5000.0, 0.0 },
        { 10000.0, 0.1 },
        { 20000.0, 0.15 },
        { 35000.0, 0.2 }
    };
    int index = 0;
    double tax = 0.0;

    while (income > 0.0)
    {
        tax += min(income, tax_code[index][0]) * tax_code[index][1];
        income -= tax_code[index][0];

        if (index < 3)
            index++;
    }

    return tax;
}

