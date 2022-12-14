#include<bits/stdc++.h>
#define ll long long
//#define int long long
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
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 26, M = 1 << 25;
char s[N][N];
int a[N][N], f[M], cnt[M];
void init() {
	for(int i = 1; i < M; ++i)
		cnt[i] = cnt[i >> 1] + (i & 1);
}
int main() {
	freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
	init();
    int n = read(), m = read();
    for(int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for(int j = 0; j < m; ++j) {
			a[i][j] = (s[i][j] == '*');
			f[1 << i] |= (a[i][j] << j);
		}
	}
	int ans = max(n, m), tot = (1 << n);
	for(int i = 0; i < tot; ++i) {
		int pos = i & (-i);
		f[i] = f[i ^ pos] | f[pos];
	}
	for(int i = 0; i < tot; ++i) {
		ans = min(ans, max(cnt[i], cnt[f[(tot - 1) ^ i]]));
	}
	printf("%d\n", ans);
	return 0;
}