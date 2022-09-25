#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define ll long long
//#define int long long
#define dbg1(x) cerr<<#x<<'='<<(x)<<" "
#define dbg2(x) cerr<<#x<<'='<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define MN 1000005
#define mod 1000000007
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int n, m;
int fac[MN], inv[MN];
int Mul(int x, int y) {return 1ll * x * y % mod;}
int Add(int x, int y) {return ((x + y) % mod + mod) % mod;}
int C(int x, int y) {return Mul(fac[x], Mul(inv[y], inv[x - y]));}
int len[MN], step;
std::vector<int> nm[MN];
typedef std::pair<int, int> pii;
pii p[MN];
#define fi first
#define se second
#define pb push_back
int _l[MN], _r[MN];
int main() {
	n = read(), m = read();
	REP(i, 1, m + 1) {
		p[i].fi = read();
		p[i].se = read();
	}
	fac[1] = fac[0] = inv[1] = inv[0] = 1;
	REP(i, 2, MN) fac[i] = Mul(fac[i - 1], i), inv[i] = Mul((mod - mod / i), inv[mod % i]);
	REP(i, 1, MN) inv[i] = Mul(inv[i - 1], inv[i]);
	m = unique(p + 1, p + m + 1) - p - 1;
	REP(i, 1, m + 1) {
		++_r[p[i].fi];
		++_l[p[i].se];
	}
	// dbg3(------);
	step = 0;
	memset(len, 0, sizeof len);
	++_r[1]; ++_l[n];
	REP(i, 1, n + 1) {
		REP(j, 0, _r[i]) {
			step++;
			len[step] = 0;
			nm[step].clear();
		}
		// dbg2(step);
		len[step]++;
		REP(j, 0, _l[i]) {
			int kk = nm[step].size();
			int prod = 1;
			REP(k, 0, nm[step].size())	
				prod = Mul(prod, nm[step][k]);
			int sum = len[step];
			step--;
			// dbg1(sum); dbg1(kk); dbg1(prod); dbg2(Mul(fac[sum+kk], prod));
			nm[step].pb(Mul(fac[sum+kk], prod));
		}
	}
	// dbg3(-----);
	printf("%d\n", nm[0][0]);
	return 0;
}