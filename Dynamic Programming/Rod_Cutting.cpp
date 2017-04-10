#include<bits/stdc++.h>
#define sze 10000
using namespace std;

///recursive top-down implementation...
/*int rodCut(int p[], int n)
{
    if(n==0){
        return 0;
    }
    int q = INT_MIN;
    for(int i=1; i<=n; i++){
        q = max(q,p[i] + rodCut(p,n-i));
    }
    return q;
}*/

///memoized-cut-rod implementation...


int memoized_cut_rod(int p[], int n, int r[])
{
    int q,i;
    if(r[n]>=0){
        return r[n];
    }
    if(n==0){
        q=0;
    }
    else{
        q = INT_MIN;
        for(i=1; i<=n; i++){
            q = max(q, p[i]+memoized_cut_rod(p, n-i, r));
        }
    }
    r[n] = q;
    return q;
}

int main()
{

    int length, i, max_profit, n, price[sze], r[sze];
    memset(r,-1,sze);

    cout<< "How many rod price do you have?\n";
    cin >> n;

    cout << "Enter "<<n<<" rod prices: ";
    for(i=1; i<=n; i++){
        cin >> price[i];
    }


    cout<<"Enter rod length: ";
    cin >> length;

    max_profit = memoized_cut_rod(price, length, r);
    cout<< max_profit << endl;
    return 0;
}
