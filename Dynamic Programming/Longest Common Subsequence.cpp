#include<bits/stdc++.h>
#define sze 5000
using namespace std;

int c[sze][sze],b[sze][sze];
string sequence;

void lcs(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int i,j;

    for(i=0; i<m; i++){
        c[i][0] = 0;
    }
    for(j=1; j<n; j++){
        c[0][j] = 0;
    }
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}

///printing lcs..

void print_lcs(string X, int i, int j)
{
    if(i==0 || j==0){
        return;
    }
    if(b[i][j]==1){
        sequence += X[i-1];
        print_lcs(X,i-1,j-1);
    }
    else if(b[i][j]==2){
        print_lcs(X,i-1,j);
    }
    else{
        print_lcs(X,i,j-1);
    }
}

int main()
{
    string A,B;
    int m,n,length;

    getline(cin,A);
    getline(cin,B);

    m = A.length();
    n = B.length();

    lcs(A,B);
    cout << "Length of Lcs is: "<< c[m][n] << endl;

    print_lcs(A,m,n);
    reverse(sequence.begin(),sequence.end());
    cout << sequence << endl;

    return 0;
}
