#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define db double
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define dbg1(x) std::cerr<<#x<<"="<<(x)<<' '
#define dbg2(x) std::cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) std::cerr<<#x<<"\n"
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
using namespace std;
int f[366][26][51]; // S
int g[366][51][51]; // N

struct xxx {
	int i, j, k;
};
xxx pref[366][26][51];
xxx preg[366][51][51];

int idf[366][26][51];
int idg[366][51][51];

int Y, N, S;
int H, M;
struct node{
	int ID;
	int id;
	int l, r;
	int last;
	int c;
	bool operator < (const node&o) const{
		return l < o.l;
	}
}a[5005];
#define inf 0x3f3f3f3f

int tot, st[5005];

int main() {
	Y = read(), N = read(), S = read();
	H = read(), M = read();
	REP(i, 1, M + 1) {
		a[i].ID = i;
		a[i].id = read(); a[i].l = read();
		a[i].r = read(); a[i].c = read();
		a[i].last = a[i].r - a[i].l;
	}
	std::sort(a + 1, a + M + 1);
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	f[0][0][1] = g[0][0][1] = 0;
	int ind = 1;
	int ans1 = 0x3f3f3f3f;
	int ans2 = 0x3f3f3f3f;
	int top1, top2;
	xxx Ans1, Ans2;
	REP(i, 0, Y) {
		while(a[ind].l < i && ind <= M) ++ind;
		REP(j, 0, S) REP(k, 1, H + 1) if(f[i][j][k] < inf && j + Y - i >= S) {
			REP(nex, ind, M + 1) if(a[nex].id != k || a[nex].l > i) {
				if(j + 1 == S) {
					if(f[i][j][k] + a[nex].c < ans1) {
						ans1 = f[i][j][k] + a[nex].c;
						Ans1 = (xxx){i, j, k};
						top1 = a[nex].ID;
					}
				}
				else if(f[a[nex].r][j + 1][a[nex].id] > f[i][j][k] + a[nex].c) {
					f[a[nex].r][j + 1][a[nex].id] = f[i][j][k] + a[nex].c;
					pref[a[nex].r][j + 1][a[nex].id] = (xxx){i, j, k};
					idf[a[nex].r][j + 1][a[nex].id] = a[nex].ID;
				}
			}
		}
	}
	ind = 1;
	REP(i, 0, Y) {
		while(a[ind].l < i && ind <= M) ++ind;
		REP(j, 0, N) REP(k, 1, H + 1) if(g[i][j][k] < inf && j + Y - i >= N) {
			REP(nex, ind, M + 1) if(a[nex].id != k || a[nex].l > i) {
				if(j + a[nex].last >= N) {
					if(g[i][j][k] + a[nex].c < ans2) {
						ans2 = g[i][j][k] + a[nex].c;
						Ans2 = (xxx){i, j, k};
						top2 = a[nex].ID;
					}
				}
				else if(g[a[nex].r][j + a[nex].last][a[nex].id] > g[i][j][k] + a[nex].c) {
					g[a[nex].r][j + a[nex].last][a[nex].id] = g[i][j][k] + a[nex].c;
					preg[a[nex].r][j + a[nex].last][a[nex].id] = (xxx){i, j, k};
					idg[a[nex].r][j + a[nex].last][a[nex].id] = a[nex].ID;
				}
			}
		}
	}
	if(ans1 == inf && ans2 == inf) {
		return 0 * puts("IMPOSSIBLE");
	}
	if(ans1 > ans2) {
		puts("NIGHTS");
		st[tot = 1] = top2;
		int i = Ans2.i, j = Ans2.j, k = Ans2.k;
		while(i) {
			st[++tot] = idg[i][j][k];
			xxx PRE = preg[i][j][k];
			i = PRE.i; j = PRE.j; k = PRE.k;
		}
	}
	else {
		puts("STAYS");
		st[tot = 1] = top1;
		int i = Ans1.i, j = Ans1.j, k = Ans1.k;
		while(i) {
			st[++tot] = idf[i][j][k];
			xxx PRE = pref[i][j][k];
			i = PRE.i; j = PRE.j; k = PRE.k;
		}
	}
	printf("%d\n", tot);
	DREP(i, tot, 0) printf("%d ", st[i]);
	return 0;
}