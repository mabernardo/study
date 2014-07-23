// cpp_primer_pex02.cpp -- Programming Exercise 2, C++ Primer, Ch. 3, page 112
/*
Write a short program that asks for your height in feet and inches and your weight
in pounds. (Use three variables to store the information.) Have the program report
your body mass index (BMI).To calculate the BMI, first convert your height in feet
and inches to your height in inches (1 foot = 12 inches).Then convert your height
in inches to your height in meters by multiplying by 0.0254.Then convert your
weight in pounds into your mass in kilograms by dividing by 2.2. Finally, compute
your BMI by dividing your mass in kilograms by the square of your height in
meters. Use symbolic constants to represent the various conversion factors.
*/
#include <iostream>

int main()
{
	using namespace std;
	const float Inch_To_Meter = 0.0254f;
	const float Pound_To_Kilo = 2.2f;
	const int Foot_To_Inch = 12;
	int feet, inches, weight;

	cout << "Enter your height in feet and inches: _ __\b\b\b\b";
	cin >> feet >> inches;
	cout << "Enter your weight in pounds: ___\b\b\b";
	cin >> weight;

	float meters = (feet * Foot_To_Inch + inches) * Inch_To_Meter;
	float kilos = weight / Pound_To_Kilo;

	float bmi = kilos / (meters * meters);
	cout << "Your height in meters is " << meters << endl;
	cout << "Your weight in kilograms is " << kilos << endl;
	cout << "Your BMI is " << bmi << endl;

	return 0;
}
