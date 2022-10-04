#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define DREP(i,a,b) for(int i=(a);i>(b);--i)
#define pb push_back
#define int long long
using namespace std;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN = 1e5+5;
int n, q, a[MN];
bool vis[MN];
std::vector<int> G[MN];
int len1[MN], len2[MN];
int nm[MN], mx[MN];
int step;
void dfs(int x) {
//	printf("x = %d\n", x);
	vis[x] = 1;
	if(vis[a[x]]) {
		if(len2[a[x]]) {
			len1[x] = len1[a[x]] + 1;
			len2[x] = len2[a[x]];
		}
		else {
			step = 0;
			int nowx = a[x];
//			puts("in");
			while(nowx!=x) ++step, nowx = a[nowx];
//			puts("out");
			++step;
			nowx = a[x];
			while(nowx!=x) len2[nowx] = step, nowx = a[nowx];
			len2[x] = step;
		}
		return ;
	}
	else dfs(a[x]);
	if(!len2[x]) {
		len1[x] = len1[a[x]] + 1;
		len2[x] = len2[a[x]];
	} 
}
int tot, lenn[MN];
std::vector<int> tt[MN];
signed main() {
	n = read();
	REP(i,1,n+1) a[i]=read();
//	puts("???");
	REP(i,1,n+1) if(!vis[i]) {
//		printf("%d\n", i);
		dfs(i);
//		printf("oo%d\n", i);
	}
	REP(i,1,n+1) {
		G[len2[i]].pb(len1[i]);
	}
	REP(i,1,n+1) std::sort(G[i].begin(), G[i].end());
	REP(i,1,n+1) {
		if(G[i].size()) {
			++tot;
			lenn[tot] = i;
			int j = 0;
			tt[tot].push_back(0);
			REP(k,0,G[i].size()) {
				int _len1 = G[i][k];
				if(_len1 == j){
					tt[tot][j]++;
				}
				else {
					tt[tot].pb(1 + tt[tot][j]);
					++j;
				}
			}		
		}
	}
	int Q = read();
	while(Q--) {
		int l = read();
		int r = read();
		if(l==r) printf("%lld\n", n);
		else {
			int L = min(l, r);
			int E = abs(r - l);
			int ans = 0;
			REP(i, 1, tot + 1) if(E % lenn[i] == 0) {
				int siz = min((int)tt[i].size() - 1, L);
				ans += tt[i][siz];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}