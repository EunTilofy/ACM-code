#include <bits/stdc++.h>
using namespace std;

struct node {
	int b[3];
};

bool pd(node A, node B, int o) {
	for(int i = 0; i < 3; ++i) {
		if(i == o) continue;
		if(A.b[i] != B.b[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<node> a(n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 3; ++j) 
			cin >> a[i].b[j];
	}
	vector<int> ans(3);
	for(int o = 0; o < 3; ++o) {
		vector<int> mk(n);
		for(int i = 0; i < n; ++i) {
			if(mk[i]) continue;
			for(int j = i + 1; j < n; ++j) {
				if(!pd(a[i], a[j], o)) continue;
				mk[j] = 1;
			}
			ans[o]++;
		}	
	}
	if(ans[0] >= ans[1] && ans[0] >= ans[2]) cout << "X\n";
	else if(ans[1] >= ans[2]) cout << "Y\n";
	else cout << "Z\n";
	return 0;
}