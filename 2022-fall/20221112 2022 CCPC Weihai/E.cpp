#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, k;
	cin >> n >> k;
	k--;
	vector<int> a(n);
	int id = -1;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if(a[n-1]<a[n-2]) {
		id=(k-a[n-1])/(a[n-1]-a[n-2]);
		id+=((k-a[n-1])%(a[n-1]-a[n-2])!=0)+n;
		cout << "Python 3." << id << " will be faster than C++\n";
	} else cout << "Python will never be faster than C++\n";
	return 0;
}