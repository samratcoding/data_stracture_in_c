#include <iostream>
using namespace std;

// Selection sort function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  // Loop through the entire array
        int small_i = i;  // Assume the current element is the smallest

        // Find the smallest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[small_i]) {
                small_i = j;  // Update the index of the smallest element
            }
        }

        // Swap the smallest element found with the first element of the unsorted part
        swap(arr[i], arr[small_i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    const int n = 7;  // Array size is constant
    int data[n] = {7, 3, 2, 9, 5, 10, 12};  // Initialize array
    // Print sorted array
    printArray(data, n);
    
    // Call the selection sort function
    selectionSort(data, n);

    // Print sorted array
    printArray(data, n);

    return 0;
}
