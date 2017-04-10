#include<bits/stdc++.h>
#define sze 100
using namespace std;
int m[sze][sze];
bool visited[sze][sze];

int matrix_chain_order(int p[], int i, int j)
{
    if(i >= j){
        return 0;
    }
    if(visited[i][j]){
        return m[i][j];
    }
    int k,cost;
    int minimum = INT_MAX;

    for (k=i; k<=j-1; k++){
        cost = matrix_chain_order(p, i, k) + matrix_chain_order(p, k+1, j) + p[i-1]*p[k]*p[j];
        minimum = min(cost,minimum);
    }

    visited[i][j] = true;
    m[i][j] = minimum;
    return m[i][j];
}

int main()
{
    int n,ans;
    cout << "How many matrices do you want to input?\n";
    cin >> n;
    int aray[n+1];

    cout << "Enter "<<n+1<<" numbers: ";
    for(int i=0; i<n+1; i++){
        cin >> aray[i];
    }
    n+=1;
    ans = matrix_chain_order(aray, 1, n-1);
    cout << "Minimum number of multiplications is: "<< ans << endl;
    return 0;
}
