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
const int MN = 30;
char s[30][30];
bool a[30][30];

int d[65], q[65], top;
#define S 0
#define T 60
struct edge{int to, w, nex;}e[65 * 65 * 10];
int en = 1, hr[65], cur[65];
void ins(int x, int y, int w) {
//	dbg1(x), dbg1(y), dbg2(w);
	e[++en] = (edge){y, w, hr[x]}; hr[x] = en;
	e[++en] = (edge){x, 0, hr[y]}; hr[y] = en;
}
bool bfs() {
	memset(d, 0, sizeof d);
	int i, j;
	for(d[q[i=top=1]=S]=1;i<=top;++i)
		for(j=hr[q[i]];j;j=e[j].nex)
			if(e[j].w&&!d[e[j].to])
				d[q[++top]=e[j].to]=d[q[i]]+1;
	return d[T];
}
int dfs(int x, int f) {
	if(x == T) return f;
	int used = 0;
	for(int &i = cur[x]; i; i = e[i].nex)
		if(d[e[i].to]==d[x]+1&&e[i].w) {
			int tmp = dfs(e[i].to, min(f-used, e[i].w));
			e[i].w -= tmp; e[i^1].w += tmp; used+=tmp;
			if(used == f) return used;
		}
	return d[x] = -1, used;
}
int dinic() {
	int mf = 0;
	while(bfs()) {
//		dbg3(sssss);
		memcpy(cur, hr, sizeof cur);
		mf += dfs(S, inf);
	}
	return mf;
}

int nm[30][30];

int main() {
	 freopen("output.txt", "w", stdout);
     freopen("input.txt", "r", stdin);
	int n = read();
	int m = read();
	REP(i, 1, n + 1) scanf("%s", s[i] + 1);
	REP(i, 1, n + 1) REP(j, 1, m + 1) {
		if(s[i][j] == '*') a[i][j] = 1; //ins(i, n + j, 1);
	}
	int ans = 0;
	while(1) {
		bool fl = 0;
		memset(nm, 0, sizeof nm);
		REP(i, 1, n + 1) REP(j, 1, m + 1) {
			if(a[i][j] == 1) {
				fl = 1;
				REP(ii, 1, n + 1) ++nm[ii][j];
				REP(jj, 1, m + 1) ++nm[i][jj];
				--nm[i][j];
			} 
		} 
//		dbg2(fl);
		if(!fl) break;
		int maxx = 0;
		int _i, _j;
		REP(i, 1, n + 1) REP(j, 1, m + 1) {
			if(nm[i][j] > maxx) {
				maxx = nm[i][j];
				_i = i;
				_j = j;
			}
		}
		// _i, _j
//		dbg1(_i); dbg2(_j);
		REP(i, 1, n + 1) a[i][_j] = 0; 
		REP(j, 1, m + 1) a[_i][j] = 0;
		++ans;
	}
	printf("%d\n", ans);
//	REP(i, 1, n + 1) ins(S, i, 1);
//	REP(i, 1, m + 1) ins(i + n, T, 1);
//	printf("%d\n", dinic());
	return 0;
}