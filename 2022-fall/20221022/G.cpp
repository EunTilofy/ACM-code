#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
vector<int> S[N], T[N];
int cnt = 0, tmp = 0, na[N], nb[N];
struct node {
	string s;
	int nm, id;
} a[N], b[N];

bool cmp(node A, node B) {
	return A.nm < B.nm;
}
int mk[N];

int main() {
	freopen("powersum.in","r",stdin);
	freopen("powersum.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	cin >> n;
	vector<int> s(n), t(n);
	for(int i = 0; i < n; ++i) {
		b[i].s = a[i].s = "";
		b[i].nm = a[i].nm = 0;
		b[i].id = a[i].id = i;
	}
	for(int i = 0; i < n; ++i) {
		cin >> a[i].s;
		for(int j = 0; j < n; ++j) {
			b[j].s += a[i].s[j];
			b[j].nm += (a[i].s[j] == '1');
			a[i].nm += (a[i].s[j] == '1');
		}
	}
	
	sort(a, a + n, cmp), sort(b, b + n, cmp);
	int flg = 1;
	for(int i = 0; i < n; ++i) {
		int j = i;
		for(; j + 1 < n && a[j + 1].nm == a[j].nm; ++j) {
			if(a[j].s != a[j + 1].s) flg = 0;		
		}
		if(!flg) break;
		for(int k = i; k <= j; ++k) {
			S[cnt].push_back(a[k].id);
		}
		for(int k = 0; k < n; ++k) {
			int pos = a[i].s[k] - '0';
			if(!pos && mk[k]) flg = 0;
			mk[k] = pos;
		}
		i = j, ++cnt;
	}
	memset(mk, 0, sizeof mk);
	for(int i = 0; i < n; ++i) {
		int j = i;
		for(; j + 1 < n && b[j + 1].nm == b[j].nm; ++j) {
			if(b[j].s != b[j + 1].s) flg = 0;		
		}
		if(!flg) break;
		for(int k = i; k <= j; ++k) {
			T[tmp].push_back(b[k].id);
		}
		for(int k = 0; k < n; ++k) {
			int pos = b[i].s[k] - '0';
			if(!pos && mk[k]) flg = 0;
			mk[k] = pos;
		}
		i = j, ++tmp;
	}
	
	if(!flg) { cout << "NO\n"; return 0;}
	int l = 1e9, r = -1e9;
	for(int i = 0; i < cnt; ++i) {
		for(auto x : S[i]) {
			s[x] = i;
//			cout << x << " " ;
		}
//		cout << "\n";
	}
//	cout <<"===\n";
	for(int i = 0; i < tmp; ++i) {
		for(auto x : T[i]) {
//			cout << x << " ";
			t[x] = i;
		}
//		cout << "\n";
	}
	for(int i = 0; i < n; ++i) {
//		cout << "Xxx " << a[i].id << "\n";
		for(int j = 0; j < n; ++j) {
			if(a[i].s[j] == '1') l = min(l, s[a[i].id] + t[j]);
			else r = max(r, s[a[i].id] + t[j]);
		}
	}
//	cout << l << " " << r << "\n";
//	assert(l > r);
	cout << "YES\n";
	for(int i = 0; i < n; ++i) 
		cout << s[i] << " " << t[i] << "\n";
	cout << l << "\n";
	return 0;
}