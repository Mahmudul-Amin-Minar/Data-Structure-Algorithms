/***This program will return the index of the last occurrence of the number in the array 

input:
5 1
1 2 3 4 1  searching 1 in the array of 5 elements..

output:
5

***/


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
