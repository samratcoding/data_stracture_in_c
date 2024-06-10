#include <iostream>
using namespace std;

int main()
{
    
    int x[5] = {5,8,15,19,13};
    int targte = 15, temp=0;
    
    for(int i=0; i<5-1; i++){
        if(x[i] == targte){
            temp=1;
        }
    }
    
    if(temp==1){
        cout << "Found";
    }
    else{
        cout << "Not Found";
    }
    
}
