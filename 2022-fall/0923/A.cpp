#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define db double
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define y1 y1111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x<<1) + (x<<3) + ch - '0'; ch = getchar();}
	return x * f;
}
const int MN = 3e5 + 5;
int n, m, T;
long long a[MN], M;
std::map<long long, int> ct;
std::map<long long, int>::iterator it;
std::map<long long, int> mp;
int tot;
long long b[MN];
bool chk(int x, int num, int len) {
	int now = x;

	for(int i = 1; i <= len; ++i) {
		if(!ct[now]) 
	}
	return true;
}
signed main() {
	//std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	n = read();
	REP(i, 1, n + 1) {
		a[i] = read();
		M = max(a[i], M);
		ct[a[i]] ++;
	}
	int num = n;
	long long _ = 1ll;
	ct[1] --; num --;
	while(1) {
		if(!ct[_ * 2]) break;
		ct[_ * 2]--; num--;
		_ <<= 1;
	}
	M = max(M, _);
	int mx = 0;
	int all = 0;
	for(it = ct.begin(); it != ct.end(); ++it) {
		mx = max(mx, it->second);
		all += it->second != 0;
	}
	for(it = ct.begin(); it != ct.end(); ++it) {
		if(it->second == mx) b[++tot] = it->first;
	}
	std::sort(b + 1, b + tot + 1);
	for(int i = 1; i <= tot;)
	int i;
	for(i = 1; i <= tot; ++i) {
		if(i == tot || b[i + 1] >= _) break;
	}
	for(; i; --i) {
		if(chk(i, num, all)) printf("%lld\n", _ + _ - i);
	}
	return 0;
}