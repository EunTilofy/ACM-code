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
const int MN = 1005;
int n, m;
struct edge{int from, to, nex;}e[20005];
int en, hr[1005];
void ins(int x, int y) {
	e[++en] = (edge){x, y, hr[x]}; hr[x] = en;
}
int dind, dfn[MN], Bl, low[MN], st[MN], col[MN], top, siz[MN];
bool in[MN];

std::vector<int> newG[MN];

void Tj(int x) {
	low[x] = dfn[x] = ++dind;
	in[st[top++] = x] = true;
	int i;
	for(i = hr[x]; i; i = e[i].nex) {
		if(!dfn[e[i].to]) Tj(e[i].to), low[x] = min(low[x], low[e[i].to]);
		else if (in[e[i].to]) low[x]=min(low[x], dfn[e[i].to]);
	}
	if(dfn[x]==low[x])
		for(++Bl;st[top]^x;in[st[--top]]=false) col[st[top-1]]=Bl, ++siz[Bl];
}
bool mp[1005][1005];
int ans[1005][1005];
int print[20005], tot;

bool vis[MN], mk[MN];
void dfs(int x, int T) {
	vis[x] = 1;
	if(x == T) {
		mk[x] = 1;
		return ;
	}
	REP(i, 0, newG[x].size()) {
		int y = newG[x][i];
		if(!vis[y]) dfs(y, T);
		mk[x] |= mk[y];
	}
	return;
}

signed main() {
     freopen("output.txt", "w", stdout);
     freopen("input.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read(), m = read();
    REP(i, 1, m + 1) {
		int x = read();
		int y = read();
		ins(x, y);
	}
	REP(i, 1, n + 1) if(!dfn[i]) Tj(i);
	REP(i, 1, m + 1) if(col[e[i].from] != col[e[i].to]) {
//		dbg1(col[e[i].from]);
//		dbg2(col[e[i].to]);
		mp[col[e[i].from]][col[e[i].to]] = 1;
		newG[col[e[i].from]].pb(col[e[i].to]);	
	}
//	dbg2(Bl);
//	REP(i, 1, n + 1) dbg2(col[i]);
	int Ans = 0;
	
	REP(i, 1, Bl + 1) Ans = max(Ans, siz[i]);
	int nonAns = Ans;
	
	REP(i, 1, Bl + 1) REP(j, 1, Bl + 1) if(i!=j&&mp[i][j]){
		memset(vis, 0, sizeof vis);
		memset(mk, 0, sizeof mk);
		dfs(i, j);
		REP(k, 1, Bl + 1) if(mk[k]) ans[i][j] += siz[k];
		Ans = max(Ans, ans[i][j]);
	}	
	REP(i, 1, m + 1) 
		if(col[e[i].from] != col[e[i].to] && ans[col[e[i].from]][col[e[i].to]] == Ans) print[++tot] = i;
	if(nonAns == Ans) {
		REP(i, 1, m + 1) print[++tot] = i;
	}
	
	printf("%d\n%d\n", Ans, tot);
	REP(i, 1, tot + 1) printf("%d ", print[i]);
	return 0;
}

/*
5 4
1 2
2 3
1 3
4 1

5 7
1 2
2 1
1 3
3 1
3 4
4 5
3 5

*/