#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
#define mp make_pair
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
const int MN = 220;
int f[MN][MN], a[MN][MN], vs[MN][MN], dis[MN];
int ans[MN];
queue<pair<int, int> > q;
int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   	int n = read();
   	for(int i = 1; i <= n; ++i)
   		for(int j = 1; j <= n; ++j)
   			a[i][j] = read();
   	int k = read();
   	for(int i = 1; i <= k; ++i) {
		dis[i] = read();
	}
   	f[1][0] = 1, vs[1][0] = 1;
   	q.push(mp(1, 0));
   	while(!q.empty()) {
		pair<int, int> pos = q.front(); q.pop();
		int u = pos.first, dep = pos.second;
		for(int i = 1; i <= n; ++i) {
			if(dep + 1 <= k && a[u][i] == dis[dep + 1]) {
				f[i][dep + 1] = 1;
				if(!vs[i][dep + 1]) q.push(mp(i, dep + 1)), vs[i][dep + 1] = 1;
			}
		}   	
	}
	int cur = 0;
	for(int i = 1; i <= n; ++i)
		if(f[i][k]) ans[++cur] = i;
	sort(ans + 1, ans + 1 + cur);
	printf("%d\n", cur);
	for(int i = 1; i <= cur; ++i)
		printf("%d ", ans[i]);
	puts("");
    return 0;
}