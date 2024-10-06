#pragma once
#include <iostream>

void percolateDown(int arr[], int& n, int index);

void percolateUp(int arr[], int index);

void insert(int arr[], int& n, int cap, int val);

void deleteMin(int arr[], int& n);

void remove(int arr[], int& n, int index);

void sortArray(int arr[], int& n);