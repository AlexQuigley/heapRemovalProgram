#include <iostream>
#include <ctime>
#include <algorithm>
#include "binaryminheap.h"
using namespace std;

//Initalizing array and variables
const int ARR_SIZE = 1000;        //Total size of memory allocated array, bigger than is needed
int n = 500;                     //Area of array actively being used by heap, this number changes as the heap is being manipulated
int testSize = 25;              //Size of display output for arrays to terminal
int sortArr[ARR_SIZE];

//Displays all commands and prompts for user
void displayFunc(int arr[], int& n, int testSize, int cap) { 
    string command = "";
    cout << "\n$ ";

    cin >> command;

    //Very inefficient, but C++ does not support strings in case statements so this was my next thought
    if (command == "display") {

        cout << "\nDisplaying array \n";
        for (int i = 0; i < testSize; i++) 
            cout << arr[i] << endl;
        displayFunc(arr, n, testSize, cap);

    }
    else if (command == "heapify") {
        sortArray(arr, n);
        cout << "\nHeap has been heapified!\n";
        displayFunc(arr, n, testSize, cap); 
    }
    else if (command == "insert") {
        cout << "Enter a number to insert: ";
        int val;
        cin >> val;
        insert(arr, n, cap, val);
        displayFunc(arr, n, testSize, cap);

    }
    else if (command == "remove") {
        cout << "Enter an index to remove: ";
        int val;
        cin >> val;
        remove(arr, n, val);
        displayFunc(arr, n, testSize, cap);

    } 
    else if (command == "delMin") {
        deleteMin(arr, n);
        displayFunc(arr, n, testSize, cap);
    }
    else if (command == "percUp") {
        cout << "Enter Index: ";
        int val;
        cin >> val;
        percolateUp(arr, val);
        displayFunc(arr, n, testSize, cap);
    }
    else if (command == "percDown") {
        cout << "Enter Index: ";
        int val;
        cin >> val;
        percolateDown(arr, n, val);
        displayFunc(arr, n, testSize, cap);
    }
    else if (command == "exit") {
        exit(0);
    }
    else if (command == "help") {
        cout << "Available Commands:\n";
        cout << "display\n";
        cout << "heapify\n";
        cout << "insert\n";
        cout << "remove\n";
        cout << "delMin\n";
        cout << "percUp\n";
        cout << "percDown\n";
        cout << "exit\n";
        cout << "help\n";
        displayFunc(arr, n, testSize, cap);
    }
    else {
        cout << "Invalid Command" << endl;
        displayFunc(arr, n, testSize, cap);
    }
}


int main() {

    //Gives a random seed value for the array based on the current computer time
    int seed = time(0);
    srand(seed);

    //Building Master array using srand()
    for (int i = 0; i < n; i++) {
        sortArr[i] = rand();
    }

    cout << "Type 'help' for a list of commands." << endl;
    displayFunc(sortArr, n, testSize, ARR_SIZE);

    //Array display output
    /*
    cout << "\nDisplaying array \n";
    for (int j = 0; j < testSize; j++) {
        cout << sortArr[j] << endl;
    }


    //Running Array through heap
    sortArray(sortArr, n);

    cout << "\nDisplaying Min Heap Array \n";
    for (int j = 0; j < testSize; j++) {
        cout << sortArr[j] << endl;
    }
    //*/

    return 0;
}

