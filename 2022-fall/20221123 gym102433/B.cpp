#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], mk[N], p[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<int> nm(k + 1), mk(k + 1);
	int pos = k, be = -1, fr = 1, cur = 1;
	for(int i = 1; i <= n; ++i) nm[a[i]]++;
	set<pair<int, int> > s;
	set<pair<int, int> > :: iterator it;
	for(; k; k--) {
		for(int i = fr; i <= n; ++i) {
			if(pos < k) break;
			if(!mk[a[i]]) {
				nm[a[i]]--;
				if(!nm[a[i]]) pos--;
			}
			if(pos < k) {be = i; break;}
		}
//		cerr << "be : " << be << "\n";
		for(int i = fr; i <= be; ++i) {
			if(!mk[a[i]]) s.insert({a[i], i});
		}
		for(it = s.begin(); it != s.end(); ++it) {
			auto[x, y] = *it;
//			cout << "::" << x << " " << y << "\n";
		}
		auto [v, tmp] = *s.begin();
		mk[v] = 1;
		if(nm[v]) pos--;
		cout << v << " ";
		for(int i = cur; i <= tmp; ++i) {
			it = s.find({a[i], i});
			if(it != s.end()) s.erase(it);
		}
		while(s.size() && (*s.begin()).first == v) s.erase(*s.begin());
		fr = be + 1, cur = tmp + 1;
	}
	cout << "\n";
	return 0;
}

/*
5 3
2 3 3 1 2
*/