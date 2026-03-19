// iostream library for input output via console/terminal
#include <iostream>
// thread library for threading operations
#include <thread>
// StopWatch class for time measurement operations
#include "StopWatch.h"
// std namespace for standart library functions and classes
using namespace std;



int main()
{
	// Simple Serial Code that finds the integration of x^2 between 0-10
	// if you take the integral it will be x^3/3 and put 0 and 1 
	// it will converge to 333.3333

	double b = 3, a = 0, n = 3; //n is the number of rectangles
	double h = (b - a) / n;  //width of the rectangles
	double sum = 0, x;

	StopWatch sw;
	// Begin timing
	sw.start();


	for (x = a+1; x <= b; x += h)
	{
		sum += x * x * h;
	}

	// Stop timing
	sw.stop();

	// The final integration
	cout << "Result = " << sum << endl;
	cout << "Time elapsed: " << sw.elapsedTime() << endl;


}