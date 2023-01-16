#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	vector<int> a(n+1);
	int j = m;
	for(int i = n; i > 0; i-=2) {
		a[i] = a[i - 1] = j;
		if(j != 1) --j;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i] == j) cout<<"1 ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
	return 0;
}