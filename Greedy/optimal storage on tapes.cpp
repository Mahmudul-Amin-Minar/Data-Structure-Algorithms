#include <bits/stdc++.h>

using namespace std;


void findOrderMRT(int L[], int n)
{
	double MRT = 0;
	sort(L, L + n);

	cout << "Optimal order in which programs are to be stored is: ";
	for (int i = 0; i < n; i++){
		cout << L[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++){
			sum += L[j];
		}
		MRT += sum;
	}

	cout << "\nMinimum Retrieval Time of this order is: " << MRT << "/" << n <<endl;
}


int main()
{
	int n;
	cout << "Enter number of items: ";
	cin >> n;

	int L[n];
	cout << "Enter items lengths: ";

	for(int i=0; i<n; i++){
        cin >> L[i];
	}

	findOrderMRT(L, n);
	return 0;
}
