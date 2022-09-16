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
#define ll long long
#define int long long
#define db double
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
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e5 + 5;
int n, m, a[MN], t[MN<<2], tag[MN<<2];
#define lb(x) (x&(-x))
int Mul(int x, int y) {return ((1ll * x * y) % mod + mod) % mod;}
int Add(int x, int y) {return ((x + y) % mod + mod) % mod;}
void pushup(int k) {
	t[k] = Add(t[k<<1], t[k<<1|1]);
}
void pushdown(int k, int l, int r) {
	if(tag[k] != 1) {
		t[k<<1] = Mul(t[k<<1], tag[k]);
		t[k<<1|1] = Mul(t[k<<1|1], tag[k]);
		tag[k<<1] = Mul(tag[k<<1], tag[k]);
		tag[k<<1|1] = Mul(tag[k<<1|1], tag[k]);
		tag[k] = 1;
	}
}
int qry(int k, int l, int r, int a, int b) {
	if(l == a && r == b) {
		return t[k];
	}
	int mid = (l + r) >> 1;
	pushdown(k, l, r);
	if(b <= mid) return qry(k<<1, l, mid, a, b);
	if(a > mid)  return qry(k<<1|1, mid + 1, r, a, b);
	return Add(qry(k<<1, l, mid, a, mid), qry(k<<1|1, mid + 1, r, mid + 1, b)); 
}
void upd(int k, int l, int r, int a, int b) {
//	dbg1(k), dbg1(l), dbg2(r);
	if(l == a && r == b) {
		t[k] = Mul(t[k], 2);
		tag[k] = Mul(tag[k], 2);
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(k,l,r);
	if(b <= mid) upd(k<<1, l, mid, a, b);
	else if(a > mid) upd(k<<1|1, mid + 1, r, a, b);
	else upd(k<<1,l,mid,a,mid), upd(k<<1|1,mid + 1, r, mid + 1, b);
	pushup(k);
}
void add(int k, int l, int r, int pos, int val) {
	if(l == r) {
		t[k] = val;
		tag[k] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(k, l, r);
	if(pos <= mid) add(k<<1, l, mid, pos, val);
	else add(k<<1|1, mid + 1, r, pos, val);
	pushup(k);
}
std::set<int> S;
std::set<int>::iterator it;
std::vector<int> del;
int tt[MN];
void C(int x, int y) {
//	dbg1(x); dbg2(y);
	for(; x<=n; x+=lb(x)) 
		tt[x] = Add(tt[x], y);
//	dbg3(xxxx);
}
int G(int x) {int r = 0; for(;x;x-=lb(x)) r = Add(r, tt[x]); return r;} 
signed main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T = read();
	while(T--) {
		n = read();
		REP(i, 1, n + 1) a[i] = read(), tt[i] = 0;
		REP(i, 1, n * 4 + 1) tag[i] = 1, t[i] = 0;
		S.clear();
		REP(i, 1, n + 1) {
			if(lb(a[i]) == a[i]) {
				add(1, 1, n, i, a[i]);
			}
			else {
				S.insert(i);
				C(i, a[i]);
			}
		}
		m = read();
		while(m--) {
			int opt = read();
			int l = read();
			int r = read();
			if(opt == 1) {
				upd(1, 1, n, l, r);
				it = S.lower_bound(l);
				del.clear();
				while(it != S.end() && (*it) <= r) {
					int id = (*it);
					C(id, lb(a[id]));
					a[id] = a[id] + lb(a[id]);
					if(lb(a[id]) == a[id]) {
						add(1, 1, n, id, a[id] % mod);
//						dda(1, 1, n, id);
						del.pb(id);
					}
					it++;
				}
				REP(i, 0, del.size()) {
					S.erase(del[i]);
					C(del[i], mod - a[del[i]]);
				}
			}
			else {
				int ans = qry(1, 1, n, l, r);
				ans = Add(ans, Add(G(r), mod - G(l - 1)));
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
/*
1
5
1 2 3 4 5
5
2 2 4
1 1 3
2 2 4
1 1 5
2 4 5

*/