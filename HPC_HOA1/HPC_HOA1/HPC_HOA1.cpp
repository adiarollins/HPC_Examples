// HPC_HOA1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>  // for rand() and srand()
#include <ctime>
#include <random>
#include "StopWatch.h"
using namespace std;

mutex mtx;

int a[1000000];
int b[1000000];
int c[1000000];
int mins; // global variable for minimum value
int x;

void myThreadMethod(int thread_id, int N, int p) {
	// the loop which depends on the given thread_id and size
	int my_min = c[thread_id * (N/p)];
	int my_x = thread_id * (N / p);
	for (int i = thread_id * (N/p); i < (thread_id + 1) * (N/p); i++) {
		if (c[i] < my_min) {
			my_min = c[i];
			my_x = i;
		}
	}
	mtx.lock();
	if (my_min < mins) {
		mins = my_min;
		x = my_x;
	}
	mtx.unlock();
}


int main()
{
	StopWatch sw;

    srand(time(0));
	//create arrays with random values
    for (int i = 0; i < 1000000; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }
	//serial addition
	sw.start();
    for (int i = 0; i < 1000000; i++) {
		c[i] = a[i] + b[i];
		//cout << c[i] << " ";
    }
	cout << "Array C created." << endl;	
	sw.stop();
	cout << "Time taken: " << sw.elapsedTime() << " ms" << endl;

	//serial minimum value search
	sw.start();
	mins = 200;
	for (int i = 0; i < 1000000; i++) {
		if (c[i] < mins) {
			mins = c[i];
			x = i;
		}
	}
	cout << "The minimum value in array C is: " << mins << endl;
	sw.stop();
	cout << "Time taken for serial program: " << sw.elapsedTime() << " ms" << endl;
    
	//parallel	
	sw.start();
	int p = 2; // thread count
	int N = 1000000; // array length
	int size = N / p; // partition size
	mins = 200; // reset the minimum value for parallel search

	// thread array for holding the thread instances
	thread* t = new thread[p];

	// thread creation (actual creation and assignment) loop
	for (int id = 0; id < p; id++)
	{
		// create a thread with the function and required arguments
		// the creation operation instantly starts the thread to run
		t[id] = thread(myThreadMethod, id, N,p);
	}

	// joining loop to wait all thread finish operations
	for (int i = 0; i < p; i++)
	{
		// join function is a blocking function, it returns when thread finishes.
		t[i].join();
	}

	// show the result
	cout << "The minimum value in array C is: " << mins << endl;
	sw.stop();
	cout << "Time taken for paralell program: " << sw.elapsedTime() << " ms" << endl;
	return 0;
}
