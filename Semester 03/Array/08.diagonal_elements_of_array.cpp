#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;  // Assuming a square matrix for simplicity
    int arr[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    /*
    
    Example of daiogonal elements: *
    
    * + +  
    + * + 
    * + *
    
    
    */
    
    int i=0, j=0, sum = 0;

    for(i=0;i<rows; i++){
        for(j=0;j<cols;j++){
            if(i==j or i+j==rows-1){     // When ij indexing equal or ij sumation is equal size of rows
                sum+=arr[i][j];
            }
        }
    }

    // Print the results
    cout << "Sum elements: " << sum << endl;

    return 0;
}
