// cpp_primer_pex03.cpp -- Programming Exercise 3, C++ Primer, Ch. 3, page 112
/*
Write a program that asks the user to enter a latitude in degrees, minutes, and sec-
onds and that then displays the latitude in decimal format.There are 60 seconds of
arc to a minute and 60 minutes of arc to a degree; represent these values with sym-
bolic constants.You should use a separate variable for each input value.A sample
run should look like this:
Enter a latitude in degrees, minutes, and seconds:
First, enter the degrees: 37
Next, enter the minutes of arc: 51
Finally, enter the seconds of arc: 19
37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
*/
#include <iostream>

int main()
{
	using namespace std;
	const float Minutes_In_Degree = 60.0f;
	const float Seconds_In_Degree = Minutes_In_Degree * 60.0f;

	int degrees, minutes, seconds;

	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First, enter the degrees: ___\b\b\b";
	cin >> degrees;
	cout << "Next, enter the minutes of arc: __\b\b";
	cin >> minutes;
	cout << "Finally, enter the seconds od arc: __\b\b";
	cin >> seconds;

	float latitude = degrees + (minutes / Minutes_In_Degree) + (seconds / Seconds_In_Degree);
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = ";
	cout << latitude << " degrees." << endl;

	return 0;
}
