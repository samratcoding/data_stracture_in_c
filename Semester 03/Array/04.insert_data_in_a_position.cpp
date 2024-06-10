#include <iostream>
using namespace std;

int main() {
  int arr[100] = {1, 2, 3, 4, 5};
  int size = 5, element = 6, position = 4;

  if (position < 0 || position > size) {
    cout << "Invalid position\n";
  }
  else{
      
    // Shift elements to the right to make space for the new element
      for (int i = size-1; i >= position; i--) {
        // cout<< "arr[i + 1] : "<< arr[i + 1]<< endl;
        // cout<< "arr[i] : " << arr[i]<< endl;
        arr[i + 1] = arr[i];
      }
      arr[position] = element;
  }
      
      
  cout << "Array after insertion: ";
  for (int i = 0; i <= size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
