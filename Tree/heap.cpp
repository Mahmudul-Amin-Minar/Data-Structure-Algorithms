#include<bits/stdc++.h>
using namespace std;


void max_heapify(int heap[], int heap_size, int i)
{
    int l, r, largest, temp;

    l = 2*i; ///left child.
    r = 2*i+1; ///right child.

    ///finding the largest value.
    if(l <= heap_size && heap[l] > heap[i]){
        largest = l;
    }
    else{
        largest = i;
    }

    if(r <= heap_size && heap[r] > heap[largest]){
        largest = r;
    }

    ///checking if parent is the largest.
    ///if parent is not largest then swap parent with largest(make largest as parent).
    if(largest != i){
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        max_heapify(heap, heap_size, largest);
    }
}


void build_max_heap(int heap[], int heap_size)
{
    int i;

    for(i = heap_size/2; i>=1; i--){
        max_heapify(heap, heap_size, i);
    }
}


void print_heap(int heap[], int heap_size)
{
    int i;
    for(i=1; i<=heap_size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}


int main()
{
    int heap_size;
    int heap[] = {0, 90,50,60,55,45};

    heap_size = sizeof(heap)/sizeof(heap[0])-1;

    printf("Normal Binary Tree: ");
    print_heap(heap, heap_size);

    build_max_heap(heap, heap_size);

    printf("\nBinary Tree converted to Max-Heap: ");
    print_heap(heap, heap_size);

    return 0;
}
