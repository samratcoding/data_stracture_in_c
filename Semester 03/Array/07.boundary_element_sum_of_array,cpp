#include <iostream>

using namespace std;

int main() {
    int rows = 3, cols = 4;  // Sample array dimensions
    int arr[rows][cols] = {  // Sample array initialization
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int sum = 0;

    // Add the corners
    sum += arr[0][0];          // Top-left corner
    sum += arr[0][cols-1];     // Top-right corner
    sum += arr[rows-1][0];     // Bottom-left corner
    sum += arr[rows-1][cols-1];// Bottom-right corner

    // Add the first and last row, excluding corners
    for (int j = 1; j < cols - 1; j++) {
        sum += arr[0][j];       // First row
        sum += arr[rows-1][j];  // Last row
    }

    // Add the first and last column, excluding corners
    for (int i = 1; i < rows - 1; i++) {
        sum += arr[i][0];       // First column
        sum += arr[i][cols-1];  // Last column
    }

    cout << "Sum of boundary elements: " << sum << endl;

    return 0;
}
