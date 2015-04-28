// cpp_primer_pex01.cpp -- Programming Exercise 1, C++ Primer, Ch. 3, page 111
// Write a short program that asks for your height in integer inches and then converts
// your height to feet and inches. Have the program use the underscore character to
// indicate where to type the response.Also use a const symbolic constant to repre-
// sent the conversion factor.
#include <iostream>

int main()
{
	using namespace std;
	int inches, feet;
	const int Inches_Per_Foot = 12;

	cout << "Enter your height in inches: ___\b\b\b";
	cin >> inches;

	feet = inches / Inches_Per_Foot;
	inches = inches % Inches_Per_Foot;
	cout << "Your height is " << feet << " feet and " << inches << " inches." << endl;
	return 0;
}
