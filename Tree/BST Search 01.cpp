#include<bits/stdc++.h>

using namespace std;

int ary[100];

void create_BST(int value, int index)
{
    if(ary[index] == -1){
        ary[index] = value;
    }
    else{
        if(value <= ary[index]){
            create_BST(value, index*2); ///left child.
        }
        else{
            create_BST(value, (index*2)+1); ///right child.
        }
    }
}


int search_bst(int index, int value)
{
    if(ary[index] == value){
        return index;
    }
    else if(value >= ary[index]){
        search_bst(index*2 + 1, value);
    }
    else{
        search_bst(index*2, value);
    }
}

int main()
{
    int value, index=1, num;
    memset(ary, -1, sizeof(ary));

    while(scanf("%d", &value) != EOF){
        create_BST(value, index);
    }

    cout<< "\nBST is: ";

    for(int i=0; i<30; i++){
        cout << ary[i] << " ";
    }
    cout << "\n\nInput what you want to search: ";
    cin >> num;
    printf("\nIndex: %d ", search_bst(index, num));
}

