#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, edge, node, n1, n2;
    cout<<"Enter number of nodes & edges." <<endl;

    cin>>node>>edge;

    int adjacency_mtrx[node][node];
    for(i=1; i<=node; i++){
        for(j=1; j<=node; j++){
            adjacency_mtrx[i][j] = 0;
        }
    }

    cout<<"Enter connected nodes"<<endl;

    for(i=1; i<=edge; i++){
        cin>>n1>>n2;
        adjacency_mtrx[n1][n2] = 1;
        adjacency_mtrx[n2][n1] = 1;
    }

    printf("\n\nAdjacency Matrix From Adjacent Nodes: \n");
    for(int l=0; l<=node; l++){
        for(int k=0; k<5; k++){
            printf("-");
            if(k==4){
                printf("+");
            }
        }
    }
    printf("\n");
    for(i=0; i<=node; i++){
        for(j=0; j<=node; j++){
            if(i==0 && j==0){
                printf("Nodes|");

            }
            else if(i==0 && j!=0){
                printf("    %d|", j);
            }
            else if(i!=0 && j==0){
                printf("    %d|", i);
            }
            if(i!=0 && j!=0){
                printf("    %d|", adjacency_mtrx[i][j]);
            }
        }
        printf("\n");
        for(int l=0; l<=node; l++){
            for(int k=0; k<5; k++){
                printf("-");
                if(k==4){
                    printf("+");
                }
            }
        }
        printf("\n");
    }
}

///input
/*Enter number of nodes & edges.
5 5
Enter connected nodes
1 2
2 3
2 3
2 4
1 5

///Output

Adjacency Matrix From Adjacent Nodes:
-----+-----+-----+-----+-----+-----+
Nodes|    1|    2|    3|    4|    5|
-----+-----+-----+-----+-----+-----+
    1|    0|    1|    0|    0|    1|
-----+-----+-----+-----+-----+-----+
    2|    1|    0|    1|    1|    0|
-----+-----+-----+-----+-----+-----+
    3|    0|    1|    0|    0|    0|
-----+-----+-----+-----+-----+-----+
    4|    0|    1|    0|    0|    0|
-----+-----+-----+-----+-----+-----+
    5|    1|    0|    0|    0|    0|
-----+-----+-----+-----+-----+-----+
*/
