#include <iostream>
using namespace std;


int main() {
  int arr[100] = {1, 2, 3, 4, 5};
  int size = 5, delete_position = 2;


  for (int i = delete_position-1; i < size-1; i++) {
    // cout<< "arr[i] : "<< arr[i]<< endl;
    // cout<< "arr[i+1] : " << arr[i+1]<< endl;
    arr[i] = arr[i+1];
  }

      
  cout << "Array after Delete: ";
  for (int i = 0; i < size-1; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
