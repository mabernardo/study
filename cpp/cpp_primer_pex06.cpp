// cpp_primer_pex05.cpp -- Programming Exercise 5, C++ Primer, Ch. 3, page 112
/*
Write a program that requests the user to enter the current world population and
the current population of the U.S. (or of some other nation of your choice). Store
the information in variables of type long long . Have the program display the per-
cent that the U.S. (or other nation’s) population is of the world’s population.The
output should look something like this:
Enter the world's population: 6898758899
Enter the population of the US: 310783781
The population of the US is 4.50492% of the world population.
*/
#include <iostream>

int main()
{
	using namespace std;
	long long world_population;
	long country_population;
	float country_percent;

	cout << "Enter the world's population: ";
	cin >> world_population;
	cout << "Enter your coutry's population: ";
	cin >> country_population;

	country_percent = (float) country_population / (float) world_population * 100.0;

	cout << "The population of your country is " << country_percent;
	cout << "% of the world population." << endl;
	return 0;
}
