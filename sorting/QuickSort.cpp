#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout <<endl;
}

int main() {
    vector<int> arr = { 64, 25, 12, 22, 11 };
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
