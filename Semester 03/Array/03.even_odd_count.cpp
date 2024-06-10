#include <iostream>
using namespace std;

int main()
{
    
    int x[5] = {5,8,15,19,13};
    int even_count=0, odd_count=0;
    
    for(int i=0; i<5; i++){
        if(x[i] % 2 == 0){
            even_count++;
        }
        else{
            odd_count++;
        }
    }
    
    cout << " even count : " << even_count << endl;
    cout << " odd count : " << odd_count << endl;
    
}
