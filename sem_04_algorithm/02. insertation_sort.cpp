#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // The current element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            
            arr[j + 1] = arr[j];  // Shift elements to the right
            j = j - 1;
            
        }
        arr[j + 1] = key;  // Insert the key at the correct position
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function to test the insertion sort implementation
int main() {
    int arr[] = {5, 6, 12, 11, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Given array: \n";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;
}
