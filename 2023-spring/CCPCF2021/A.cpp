#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main() {
	int cnt = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> q;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		if(s == "echo") {
			char c;
			cin >> c;
			q.push_back({1, (int)c});
		}
		else {
			int x;
			cin >> x;
			q.push_back({0, x});
		}
	}
	for(int i = 1; i <= m; ++i) {
		auto o = q[i-1];
		if(o.first) {
			cout << (char)o.second;
		}
		else {
			if(q.size()<m) {
				for(int j = 0; j < q.size()&&
                j<o.second&&j<m-i; ++j) {
					q.push_back(q[j]);
				}
			}
		}
	}
	return 0;
}