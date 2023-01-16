#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int _[2]; _[0] = _[1] = 0;
	vector<int> a(n+1);
	for(int i = 1; i <= n; ++i) cin>>a[i], _[a[i]&1]++;
	if(abs(_[0]-_[1]) <= 1) cout<<"Good";
	else cout<<"Not Good";
	return 0;
}