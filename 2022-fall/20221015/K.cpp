#include<bits/stdc++.h>
#define ll unsigned long long
#define int unsigned long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
//inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y) {
	return (x + y) % mod;
}
inline int Mul(int x, int y) {
	return 1ll * x * y % mod;
}
// inline int read() {
// 	int x=0,f=1;
// 	char ch=getchar();
// 	while(ch<'0'||ch>'9') {
// 		if(ch=='-')f=-1;
// 		ch=getchar();
// 	}
// 	while(ch>='0'&&ch<='9') {
// 		x=(x<<3)+(x<<1)+ch-'0';
// 		ch=getchar();
// 	}
// 	return x*f;
// }
const int MN = 105, LOG = 64;
int f[MN][LOG + 1];
pair<int, int> pr[MN][LOG + 1];
int a[MN], nm[MN], n, tot;

int mk[MN];
int now = 0;
int GET(int x) {
	int nm = 0;
	while(x) {
		++nm;
		x -= (x & -x);
	}
	return nm;
}
void dfs(int id, int k) {
	if(id == 1) {
		unsigned long long cur = 0;
		for(int i = 0; i < nm[1]; ++i) {
			cur += 1ull << i;
			mk[i] = 1;
		}
		now ^= cur;
		cout<<cur<<" ";
		assert(GET(cur) == GET(a[id]));
		assert(GET(cur) <= tot);
		return ;
	}
	dfs(id - 1, pr[id][k].second);
	int pos = pr[id][k].first, tmp = nm[id] - pr[id][k].first;
	unsigned long long cur = 0;
	for(int i = 0; i < tot; ++i) {
		if(mk[i] && pos) mk[i] = 0, --pos, cur += 1ull << i;
		else if(!mk[i] && tmp) mk[i] = 1, --tmp, cur += 1ull << i;
	}
	now ^= cur;
	cout<<cur<<" ";
	if(id == n) assert(now == 0);
	assert(GET(cur) == GET(a[id]));
	assert(GET(cur) <= tot);
}

signed main() {
//	printf("%lld ",1ll>>63);
	// long long x = 1;
	// x = x << 63;
	// dbg2(x);
	freopen("xor.out", "w", stdout);
	freopen("xor.in", "r", stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	// n = read();
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i];
		int pos = 0;
		for(int j = 0; j < 63; ++j) {
			if((a[i] >> j) & 1) nm[i]++, pos = j;
		}
		tot = max(tot, pos + 1);
	}
	f[1][nm[1]] = 1;
	for(int i = 2; i <= n; ++i)
		for(int j = 0; j <= tot; ++j) {
			if(!f[i - 1][j]) continue;
			for(int k = 0; k <= min(nm[i], j); ++k) {
				int len = nm[i] - k + j;
				if(len > tot) continue;
				int pos = j - k + nm[i] - k;
				pr[i][pos] = make_pair(k, j);
				f[i][pos] = 1;
			}
		}
	if(!f[n][0]) {
		cout<<"impossible"<<endl;
		//("impossible") * 0;
		return 0;
	}
	dfs(n, 0);
	return 0;
}