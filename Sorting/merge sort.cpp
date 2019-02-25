#include<bits/stdc++.h>

using namespace std;

///merging two subarrays

void merging(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1; ///size of left array.
    int n2 = r-m;   ///size of right array.

    int L[n1], R[n2]; ///initialize left and right array.

    for(i=0; i<n1; i++){
        L[i] = arr[l+i]; ///copy elements to left array.
    }
    for(j=0; j<n2; j++){
        R[j] = arr[m+1+j]; ///copy elements to right array.
    }

    i=0; ///initial index of first subarray.
    j=0; ///initial index of second subarray.
    k=l; ///initial index of merged subarray.

    ///copying into main array according to smaller to greater.
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    ///copy the rest of the elements of left array.
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    ///copy the rest of the elements of left array.
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

///divide the whole array.
void mergeSort(int arr[], int l, int r)
{
    if(l < r){
        int m = (l+r)/2; ///find the middle position.


        mergeSort(arr, l, m); ///divide the first half into pieces.
        mergeSort(arr, m+1, r); ///divide the second half into pieces.
        merging(arr, l, m, r); ///merging them.
    }
}

void printArray(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {7, 3, 1, 12, 5, 9, 10};
    int size_of_array = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, size_of_array);

    mergeSort(arr, 0, size_of_array-1);

    printf("Sorted array is \n");
    printArray(arr, size_of_array);

    return 0;
}
