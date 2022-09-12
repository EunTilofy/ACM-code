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
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
inline int qpow(int x,ll y,int m=mod) {
	int r=1;
	for(; y; y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;
	return r;
}
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int MN = 810;
int n, m;
char s[405][405];

#define S 0
#define T 805

int d[T + 5], q[T + 5], top;
int hr[T + 5], cur[T + 5];
struct edge {
	int to, w, nex;
} e[T * T];
int en;
void ins(int x, int y, int w) {
	// dbg1(x); dbg1(y); dbg2(w);
	e[++en] = (edge) {
		y, w, hr[x]
	};
	hr[x] = en;
	e[++en] = (edge) {
		x, 0, hr[y]
	};
	hr[y] = en;
}
bool bfs() {
	memset(d, 0, sizeof d);
	reg int i, j;
	for(d[q[i = top = 1] = S] = 1; i <= top; ++i) {
		for(j = hr[q[i]]; j; j = e[j].nex) {
			if(e[j].w && !d[e[j].to])
				d[q[++top] = e[j].to] = d[q[i]] + 1;
		}
		// dbg3(xxxxxx);
	}
	// dbg2(d[T]);
	return d[T];
}
int dfs(int x, int f) {
	if(x == T) return f;
	int used = 0;
	// dbg1(x); dbg2(f);
	for(int &i = cur[x]; i; i = e[i].nex) {
		// dbg2(e[i].to);
		if(d[e[i].to] == d[x] + 1 && e[i].w) {
			int tmp = dfs(e[i].to, min(f - used, e[i].w));
			e[i].w -= tmp;
			e[i^1].w += tmp;
			used += tmp;
			if(used == f) return used;
		}
	}
	return d[x] = -1, used;
}
int a[MN],ok[MN],ti,cnt[T+5];
int dinic() {
	en = 1,ti++;
	memset(hr, 0, sizeof hr);
	for(int i = 1; i <= n; ++i) if(!ok[i]) {
			for(int j = 1; j <= m; ++j) if(s[i][j] == '1')
					ins(i, n + j, 1);
		}
	for(int i = 1; i <= n; ++i) if(!ok[i]) ins(S, i, 1);
	for(int i = 1; i <= m; ++i) ins(i + n, T, 1);
	int mf = 0;
	while(bfs()) {
		memcpy(cur, hr, sizeof(cur));
		mf += dfs(S, inf);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = hr[i]; j; j = e[j].nex)
			if(e[j].w == 0 && e[j].to > n) {
				ok[i] = ti;
				a[i] = e[j].to - n;
			}
	}
	int num,id;
	for(int i=1; i<=n; i++)
		if(ok[i]==ti) {
			num=cnt[i],id=i;
			for(int j=1; j<=n; j++)if(!ok[j]&&s[j][a[i]]=='1'&&num>cnt[j])id=j,num=cnt[j];
			if(i!=id)ok[i]=0,ok[id]=ti,a[id]=a[i];
		}
	// dbg1(mf);
	return mf;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	n = read(), m = read();
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for(int j=1; j<=m; j++)cnt[i]+=(s[i][j]=='1');
	}
	for(int i = 1; i <= n; ++i) {
		int flag = 0;
		for(int j = 1; j <= m; ++j) flag |= (s[i][j] == '1');
		if(!flag) return 0 * puts("-1");
	}
	for(int i = 1; i <= n; ++i) {
		if(dinic() == 0) break;
	}
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
	return 0;
}
/*
3 3
111
110
100
*/