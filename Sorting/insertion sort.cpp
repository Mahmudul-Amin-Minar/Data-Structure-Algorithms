#include<bits/stdc++.h>

using namespace std;

int main()
{
    int given_array[9] = {9,10,1,3,4,20,50,4 ,30}, i, j, key;

    for(j=1; j<9; j++){
        key = given_array[j];
        i = j-1;

        ///Interchange position if 1st element greater than 2nd element.
        while(i>=0 && (given_array[i] > key)){
            given_array[i+1] = given_array[i];
            i = i-1;
        }
        given_array[i+1] = key;
    }

    cout<<"Sorted array: ";
    for(i=0; i<9; i++){
        printf("%d ", given_array[i]);
    }
    return 0;
}
