#include <iostream>
using namespace std;

int main()
{
    
    int x[5] = {5,8,15,19,13};
    int even_sum=0, odd_sum=0;
    
    for(int i=0; i<5; i++){
        if(x[i] % 2 == 0){
            even_sum += x[i];
        }
        else{
            odd_sum += x[i];
        }
    }
    
    cout << " even sum : " << even_sum << endl;
    cout << " odd sum : " << odd_sum << endl;
    
}
