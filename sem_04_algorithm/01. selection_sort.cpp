#include<iostream>
using namespace std;

int main(){
  int n = 7, temp, i, j;
  int data[n] = {7,3,2,9,5,10,12};


  for(i = 0; i<n; i++){

    int small_i = i;

    for(j=i+1; j<n; j++){

     if(data[j] < data[small_i]){
        small_i = j;
     } // end condition

    } // end inner loop
    j = i+1;
    temp = data[i];
    data[i] = data[small_i];
    data[small_i] = temp;

  } //end outer loop



  for(int i = 0; i<n; i++){
    cout << data[i] << "\n";
  }


} // end main function
