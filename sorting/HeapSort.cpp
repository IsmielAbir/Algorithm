#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int rootIndex) {
    int largest = rootIndex; 
    int leftChild = 2 * rootIndex + 1; 
    int rightChild = 2 * rootIndex + 2; 

    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != rootIndex) {
        swap(arr[rootIndex], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
