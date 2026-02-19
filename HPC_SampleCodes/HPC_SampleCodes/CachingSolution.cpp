/*
// iostream library for input output via console/terminal
#include <iostream>
// thread library for threading operations
#include <thread>
// StopWatch class for time measurement operations
#include "StopWatch.h"
// std namespace for standart library functions and classes
using namespace std;


// Simple Threading Examples - 10
// Multithreading Slower than Single Threading - Cache Solution


long sum = 0;
int numofthreads = 5;
long length = 100000000;
int dist = 8;

int* myarray = new int[length];
long* sumeach = new long[numofthreads * dist];

void myThreadMethod(int threadid)
{
	StopWatch sw;
	// Begin timing
	sw.start();

	sumeach[threadid * dist] = 0;


	for (int i = (threadid)*length / numofthreads; i < (threadid + 1) * length / numofthreads; i++)
	{
		sumeach[threadid * dist] += myarray[i];
	}


	// Stop timing
	sw.stop();

	// Write result
	cout << "ThreadID: " << threadid << " , Time elapsed: " << sw.elapsedTime() << endl;
}


int main()
{
	// Creating an array of a given size and assigning 1 to all elements
	myarray = new int[length];
	for (int i = 0; i < length; i++)
	{
		myarray[i] = 1;
	}

	StopWatch sw;

	///////////////////////////////////////////////////////////////////
	// SERIAL PROGRAMMING --> finding the sum of all the elements

	// Begin timing
	sw.start();

	for (int i = 0; i < length; i++)
	{
		sum += myarray[i];
	}

	// Stop timing
	sw.stop();

	// Write result
	cout << "SUM Serial = " << sum << endl;
	cout << "Serial Time elapsed: " << sw.elapsedTime() << endl;
	///////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////
	// PARALLEL PROGRAMMING --> finding the sum of all the elements

	// Creating Thread Array
	thread* t = new thread[numofthreads];

	// Begin timing
	sw.start();

	for (int i = 0; i < numofthreads; i++)
	{
		t[i] = thread(myThreadMethod, i);
	}

	for (int i = 0; i < numofthreads; i++)
	{
		t[i].join();
	}

	// Adding all the sums coming from the threads
	sum = 0;
	for (int i = 0; i < numofthreads; i++)
	{
		sum += sumeach[i * 2000];
	}

	// Stop timing
	sw.stop();

	// Write result
	cout << "SUM Paralel = " << sum << endl;
	cout << "Paralel Time elapsed: " << sw.elapsedTime() << endl;
	///////////////////////////////////////////////////////////////////

}*/