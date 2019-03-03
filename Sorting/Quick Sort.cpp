#include<bits/stdc++.h>
using namespace std;

int Partition(int *A, int start, int end)
{
    int pivot = A[end];
    int partitionIndex = start; /// set partition index start initially

    for(int i=start; i<end; i++){
        if(A[i] <= pivot){
            swap(A[i], A[partitionIndex]); ///swap if element is lesser than pivot.
            partitionIndex++;
        }
    }
    swap(A[partitionIndex], A[end]); ///swap pivot with element at partition index.
    return partitionIndex;
}


void QuickSort(int *A, int start, int end)
{
    if(start < end){
        int partitionIndex = Partition(A, start, end); /// calling partition.
        QuickSort(A, start, partitionIndex-1);
        QuickSort(A, partitionIndex+1, end);
    }
}


int main()
{
    int A[] = {6,5,4,3,2,1,0};
    QuickSort(A, 0, 6);

    for(int i=0; i<7; i++){
        cout << A[i] <<" ";
    }
}
