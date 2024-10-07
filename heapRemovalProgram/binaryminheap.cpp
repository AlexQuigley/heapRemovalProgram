#include <iostream>
#include <stdexcept>
#include <algorithm>  // For swap
#include <chrono>
#include <thread>
using namespace std;

void percolateDown(int arr[], int& n, int index) {
	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	//cout << "Percolating Down...\n";

	// Check if left child exists and is smaller than the current element
	if (left < n && arr[left] < arr[smallest])
		smallest = left;

	// Check if right child exists and is smaller than the current element
	if (right < n && arr[right] < arr[smallest])
		smallest = right;

	//If the smallest element is no longer the current element, then swap the 
	if (smallest != index) {
		cout << "Swaping " << arr[index] << " with " << arr[smallest] << endl;
		this_thread::sleep_for(chrono::milliseconds(1));
		swap(arr[index], arr[smallest]);
		percolateDown(arr, n, smallest); //Recursively percolate down
	}
}

void percolateUp(int arr[], int index) {
	int parent = (index - 1) / 2;
	//cout << "Percolating Up...\n";

	//If index is not root and if parent is grater than index, swap parent with index.
	if (index > 0 && arr[parent] > arr[index]) {
		cout << "Swaping " << arr[parent] << " with " << arr[index] << endl;
		this_thread::sleep_for(chrono::milliseconds(1));
		swap(arr[parent], arr[index]);
		percolateUp(arr, parent);
	}
}

void insert(int arr[], int& n, int cap, int val) {
	//If there is no space in array, throw error.
	if (n == cap)
		throw overflow_error("Heap Overflow: Not enough space, failed to insert new element!\n");
	
	//Insert new value at end of array
	arr[n] = val;
	n++;

	percolateUp(arr, n - 1);
	cout << "\nElement " << val << " has been inserted!\n";
}

void deleteMin(int arr[], int& n) {
	if (n == 0)
		throw out_of_range("Heap is empty!\n");

	int root = arr[0];		
	arr[0] = arr[n - 1];	//Move the last element in the heap to the root
	n--;
	//Allows the root to be overwritten next time a new integer is inserted

	percolateDown(arr, n, 0);
	cout << "Deleted minimum element!\n";
}

void remove(int arr[], int& n, int index) {
	if (index >= n)
		throw out_of_range("Index is out of bounds!\n");

	arr[index] = arr[n - 1];
	n--;

	percolateUp(arr, index);
	percolateDown(arr, n, index);
	cout << "\nIndex [" << index << "] has been removed!\n";
}

void sortArray(int arr[], int& n) {
	for (int i = 0; i < n; i++) { 
		percolateDown(arr, n, i);  
		percolateUp(arr, i); 
	}
}
