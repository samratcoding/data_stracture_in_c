#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    // Traverse the array one by one
    for (int i = 0; i < n; i++) {
        // If the target is found, return its index
        if (arr[i] == target) {
            return i;  // Return the index of the target
        }
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {10, 23, 45, 70, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    int target = 70;  // The element to search for

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
