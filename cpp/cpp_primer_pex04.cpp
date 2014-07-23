// cpp_primer_pex04.cpp -- Programming Exercise 4, C++ Primer, Ch. 3, page 112
/*
Write a program that asks the user to enter the number of seconds as an integer
value (use type long , or, if available, long long ) and that then displays the equiva-
lent time in days, hours, minutes, and seconds. Use symbolic constants to represent
the number of hours in the day, the number of minutes in an hour, and the number
of seconds in a minute.The output should look like this:
Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
*/
#include <iostream>

int main()
{
	using namespace std;
	long long seconds;
	const int Seconds_In_Minute = 60;
	const int Seconds_In_Hour = Seconds_In_Minute * 60;
	const int Seconds_In_Day = Seconds_In_Hour * 24;

	cout << "Enter the number of seconds: ";
	cin >> seconds;

	int days = seconds / Seconds_In_Day;
	int hours = seconds % Seconds_In_Day;
	int minutes = hours % Seconds_In_Hour;
	int secs = minutes % Seconds_In_Minute;

	hours /= Seconds_In_Hour;
	minutes /= Seconds_In_Minute;

	cout << seconds << " seconds = " << days << " days, ";
	cout << hours << " hours, ";
	cout << minutes << " minutes, ";
	cout << secs << " seconds." << endl;
	return 0;
}
