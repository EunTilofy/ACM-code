#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int  &x : a) cin >> x;
	sort(a.begin(), a.end());
	cout << n * (a[n - 1] - a[0]) << "\n";
	return 0;
}