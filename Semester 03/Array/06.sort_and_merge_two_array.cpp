#include <iostream>
using namespace std;

int main() 
{ 
    int arr1[] = { 1, 3, 3, 7, 9 }; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
    int arr2[] = { 2, 4, 6, 8 }; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]); 
    int arr3[n1 + n2]; 

    int i=0, j=0, k=0;  // i for arr1 j for arr2 k for arr3
    
    // loop will run untill finish n1 and n2 size both
    // Decorate it lower to higer 
    
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){   // if Array1 i position value is lower than Array2 j position value
            arr3[k]=arr1[i];
            i++;   // i will incase to when condition is true, otherwise it can skip number
            k++;   // k will incase when any value assign
        }
        else{
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    
    // in the last indexing of Array1 or Arry2 one last value can skip that is larger size
    // cause above loop only assign value when lower than next value
    // So here is loop and condition to assign remaining value in K3
    while(i<n1){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr3[k]=arr1[j];
        j++;k++;
    }
   
   
   
    cout << "Merged Array: "; 
    for (int i = 0; i < n1 + n2; i++) 
        cout << arr3[i] << " "; 
    cout << endl; 

    return 0; 
}
