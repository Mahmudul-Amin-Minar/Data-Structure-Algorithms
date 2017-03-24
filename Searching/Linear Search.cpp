#include <iostream>
using namespace std;

int main()
{
    int Elements,number,position,i;
    cin >> Elements >> number;
    int array[Elements];
    
    for(i=0; i<Elements; i++){
        cin >> array[i];
    }
    for(i=0; i<Elements; i++){
        if(array[i] == number){
            position = i+1;
        }
    }
    
    cout << position << endl;
    return 0;
}
