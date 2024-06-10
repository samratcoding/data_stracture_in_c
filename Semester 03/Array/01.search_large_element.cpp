#include <iostream>
using namespace std;

int main()
{
    
    int x[5] = {5,8,15,19,13}; 
    int max = x[0];  // Initially assume zero position value is larger
    
    for(int i=0; i<5-1; i++){
        if(x[i] < x[i+1]){
            max = x[i+1];      // coompare with next position if next position is larger then store it otherwise current position is larger
        }
    }
    
    cout << max << endl;
    
}
