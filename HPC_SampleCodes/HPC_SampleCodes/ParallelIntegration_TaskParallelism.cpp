//// iostream library for input output via console/terminal
//#include <iostream>
//// thread library for threading operations
//#include <thread>
//// StopWatch class for time measurement operations
//#include "StopWatch.h"
//// std namespace for standart library functions and classes
//using namespace std;
//
//
//
//double sum = 0;
//double n = 100000; // Resolution, how many steps
//int threads;
//double a = 0, b = 10;
//
//void myThreadMethod(double start, double end)
//{
//	double localsum = 0; // every thread will have its local sum
//
//	double h = (end - start) / (n / threads);
//	for (double x = start; x < end; x += h)
//	{
//		localsum += x * x * h;
//	}
//	sum += localsum;
//}
//
//
//int main()
//{
//	StopWatch sw;
//
//	// Ask user to enter the thread number
//	cout << "How many threads you will use? >>> ";
//	cin >> threads;
//
//	// divide the domain into n parts, for example if the algorith finds the integration between
//	// 0-100, and number of threads, n is 4 --> each thread will do the integration in (100-0)/4 = 25
//	double size = (b - a) / threads;
//
//	// create a thread array
//	thread* t = new thread[threads];
//
//	//////////////////////////////////////////////////////////////////////////////////
//	// PARALEL VERSION
//	//////////////////////////////////////////////////////////////////////////////////
//
//
//	// Begin timing
//	sw.start();
//
//	for (int i = 0; i < threads; i++)
//	{
//		t[i] = thread(myThreadMethod, i * size, (i + 1) * size);
//	}
//
//	for (int i = 0; i < threads; i++)
//	{
//		t[i].join();
//	}
//
//	// Stop timing
//	sw.stop();
//
//	// The final integration
//	cout << "Parallel Result = " << sum << endl;
//	cout << "Parallel Time elapsed: " << sw.elapsedTime() << endl;
//
//
//
//
//
//	//////////////////////////////////////////////////////////////////////////////////
//	// SERIAL VERSION
//	//////////////////////////////////////////////////////////////////////////////////
//	// Check the serial one
//	double h = (b - a) / n;
//	double sum2 = 0, x;
//
//	// Begin timing
//	sw.start();
//
//	for (x = a; x <= b - h; x += h)
//	{
//		sum2 += (x * x) * h;
//	}
//
//	// Stop timing
//	sw.stop();
//
//	cout << "Serial Result = " << sum2 << endl;
//	cout << "Serial Time elapsed: " << sw.elapsedTime() << endl;
//
//
//}