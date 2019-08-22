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
}

