#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n = 10;
    int arry[n] = {0,1,2,3,4,5,6,7,8,9};
    int searching = 9;
    int low = 0, high = n-1, mid;

    /**Binary search start.**/

    while(low <= high){
        mid = (low + high)/2;

        if(arry[mid] < searching){
            low = mid+1;
        }

        else if(arry[mid] > searching){
            high = mid-1;
        }

        else{
            printf("Position of the element is: %d\n",mid+1);
            break;
        }
    }
    return 0;
}
