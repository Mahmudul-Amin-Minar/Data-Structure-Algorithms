#include<bits/stdc++.h>

using namespace std;

int main(){
    vector <int> v [2000];
    int dis [2000], from, next, weight, edges;

    cout << "Enter number of edges and nodes: ";
    cin >> edges;

    for(int i = 0; i < edges + 2; i++){

        dis[i] = 2e9;
    }

   for(int i = 0; i < edges; i++){
        cin >> from >> next >> weight;

        v[i].push_back(from);
        v[i].push_back(next);
        v[i].push_back(weight);
   }

    dis[1] = 0;
    for(int i = 0; i < edges - 1; i++){
        int j = 0;
        while(v[j].size() != 0){

            if(dis[ v[j][0]  ] + v[j][2] < dis[ v[j][1] ] ){
                dis[ v[j][1] ] = dis[ v[j][0]  ] + v[j][2];
            }
            j++;
        }
    }

    cout << endl;

    for(int i=1; i<edges; i++){
        if(dis[i] != 0 && dis[i] != 2e9){
            cout << "1 - "<<i << " cost: " << dis[i] << endl;
        }
    }
}


/*

Enter number of edges and nodes: 9
1 2 10
2 1 15
1 3 10
1 4 5
3 5 12
5 3 13
4 5 2
3 4 16
2 4 3

1 - 2 cost: 10
1 - 3 cost: 10
1 - 4 cost: 5
1 - 5 cost: 7
*/
