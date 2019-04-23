#include <iostream>
#include <climits>
using namespace std;

int findMinCoins(int S[], int n, int cost)
{
	if(cost==0){
        return 0;
	}
	int res = INT_MAX;
	for(int i=0; i<n; i++){
        if(S[i] <= cost){
            int sub_res = findMinCoins(S, n, cost-S[i]);
            if(sub_res != INT_MAX && sub_res+1 < res){
                res = sub_res+1;
            }
        }
	}
	return res;
}

int main()
{
	cout << "Number of coins and cost"<<endl;
	int n,i, cost;
	cin >> n >> cost;
	int coins[n];
	for(i=0; i<n; i++){
        cin>>coins[i];
	}

	cout << "Minimum number of coins required to get desired change is "
			<< findMinCoins(coins, n, cost);

	return 0;
}
