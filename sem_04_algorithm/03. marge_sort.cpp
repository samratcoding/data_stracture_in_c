#include <iostream>
using namespace std;

// Merge function to combine two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left sub-array
    int n2 = right - mid;    // Size of right sub-array

    int leftArr[n1], rightArr[n2];

    // Copying the left half into leftArr[]
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    // Copying the right half into rightArr[]
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i]; // Corrected from leftArr to rightArr
    }

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {  // Corrected the condition
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) { // Corrected from i to j
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
