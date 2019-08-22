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

void inorder(int index)
{
    ///First, visit all the nodes in the left subtree
    ///Then the root node
    ///Visit all the nodes in the right subtree

    if(ary[index] != -1){

        inorder(index*2);
        printf("%d ", ary[index]);
        inorder(index*2 + 1);
    }
}

void preorder(int index)
{
    ///Visit root node
    ///Visit all the nodes in the left subtree
    ///Visit all the nodes in the right subtree

    if(ary[index] != -1){
        printf("%d ", ary[index]);
        preorder(index*2);
        preorder(index*2 + 1);
    }
}

void postorder(int index)
{
    ///visit all the nodes in the left subtree
    ///visit the root node
    ///visit all the nodes in the right subtree

    if(ary[index] != -1){
        postorder(index*2);
        postorder(index*2 + 1);
        printf("%d ", ary[index]);
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

    //printf("\nInorder: ");
    //inorder(index);
    //printf("\nPreorder: ");
    //preorder(index);
    //printf("\nPostorder: ");
    //postorder(index);

    cout<< "\nBST is: ";

    for(int i=0; i<30; i++){
        cout << ary[i] << " ";
    }
    cout << "\n\nInput what you want to search: ";
    cin >> num;
    printf("\nIndex: %d ", search_bst(index, num));
}
