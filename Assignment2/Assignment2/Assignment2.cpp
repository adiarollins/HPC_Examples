// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// iostream library for input output via console/terminal  


#include  <iostream>;    

#include  <thread>; 

#include "StopWatch (1).h" 

#include <mutex>;  

using namespace std;



int a[] = { 4, 3, 1, 6, 8, 9, 100, 23, 13, 44, 14, 67, 89, 34, 23, 69, 100, 65, 32, 33, 4 ,5 ,6 ,18 };

int b[] = { 1, 7, 8, 4, 9, 12, 10, 3, 1, 14, 7, 7, 9, 3, 3, 6, 11, 165, 2, 1, 14, 15, 8, 33 };

int c[24];

int sum = 0;



mutex mtx;



void myThreadMethod(int thread_id, int N, int p) {

    for (int i = thread_id * N / p; i < (thread_id + 1) * N / p; i++) {

        c[i] = a[i] + b[i];

    }

}



int main() {

    int p = 8;
    int N = 24;
    int size = N / p;

    thread* t = new thread[p];

    for (int id = 0; id < p; id++) {
        t[id] = thread(myThreadMethod, id, N, p);
    }

    for (int i = 0; i < p; i++)
    {

        t[i].join();
    }

    cout << "c[] : ";
    for (int i = 0; i < N; i++) {
        cout << c[i] << " ";
    }
    cout << endl;


}