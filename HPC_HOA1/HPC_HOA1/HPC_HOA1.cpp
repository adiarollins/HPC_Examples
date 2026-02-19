// HPC_HOA1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include "StopWatch.h"
using namespace std;

mutex mtx;

long sum = 0;
int numofthreads = 5;
long length = 100000000;

int* myarray = new int[length];
long* sumeach = new long[numofthreads * 2000];


void myThreadMethod(int threadid)
{
	StopWatch sw;
	// Begin timing
	sw.start();

	sumeach[threadid * 2000] = 0;


	for (int i = (threadid)*length / numofthreads; i < (threadid + 1) * length / numofthreads; i++)
	{
		sumeach[threadid * 2000] += myarray[i];
	}


	// Stop timing
	sw.stop();

	// Write result
	cout << "ThreadID: " << threadid << " , Time elapsed: " << sw.elapsedTime() << endl;
}


int main()
{
	StopWatch sw;
    int a[1000000];
	int b[1000000];
    int c[1000000];
    srand(time(0));
    for (int i = 0; i < 1000000; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }
	sw.start();
    for (int i = 0; i < 1000000; i++) {
        c[i] = a[i] + b[i];
    }
	sw.stop();
	cout << "Time taken: " << sw.elapsedTime() << " ms" << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
