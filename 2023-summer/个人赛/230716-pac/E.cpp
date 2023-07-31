#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 5;
int t, n, m, l[MN], r[MN], a[MN];

pair<long long, pair<int, pair<int, int>>> f[MN*2];
vector<int> id[MN];
const int INF = 1e9+1;
typedef pair<long long, pair<int, pair<int, int>>> Type;
Type get(Type x, Type  y) {
	if(x.first > y.first) return x;
	if(x.first < y.first) return y;
	if(x.second.first < y.second.first) return x;
	if(x.second.first > y.second.first) return y;
	if(x.second.second < y.second.second) return x;
	else return y;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// init
	cin >> t >> n >> m;
	set<int> all;
	map<int, int> vv; int cc=0;
	for(int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i] >> a[i];
		all.insert(l[i]), all.insert(r[i]);
	}
	for(auto x : all) {vv[x] = ++cc;}
	for(int i = 1; i <= n; ++i) {
		l[i] = vv[l[i]];
		r[i] = vv[r[i]];
		id[r[i]].push_back(i);
	}

	// val, num, min
	f[0] = {0, {0, {INF, INF}}};
	for(int i = 1; i <= cc; ++i) {
		f[i] = f[i - 1];
		for(auto I : id[i]) {
			int L = l[I], R = r[I], A = a[I];
			Type _ = f[L-1];
			if(_.second.first < m) {
				_.first += A;
				_.second.first += 1;
				int tmp[3] = {_.second.second.second, A, _.second.second.first};
				sort(tmp,tmp+3);
				_.second.second = {tmp[0], tmp[1]};
			} else if(_.second.second.first < A){
				_.first += A - _.second.second.first;
				int tmp[2] = {_.second.second.second, A};
				sort(tmp,tmp+2);
				_.second.second = {tmp[0], tmp[1]};
			}
			f[i] = get(f[i], _);
		}
	}
	cout << f[n].first << "\n";
	return 0;
}
