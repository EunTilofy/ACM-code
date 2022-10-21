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
const int MN = 1e5 + 5;
//int a[MN], b[MN], c[MN], n, m;
int n, m;
long long lazy[MN<<2], t[MN<<2];
void build(int k, int l, int r) {
	if(l == r) t[k] = (long long)(1ll<<31) - 1;
	else {
		int mid = (l + r) >> 1;
		build(k<<1, l, mid);
		build(k<<1|1, mid + 1, r);
	}
}
std::pair<int, std::pair<int, int>> Q[MN];
void pushup(int k) {
	t[k] = min(t[k<<1], t[k<<1|1]);
}
void pushdown(int k) {
	if(lazy[k]) {
		t[k<<1] = t[k<<1|1] = lazy[k];
		lazy[k<<1] = lazy[k<<1|1] = lazy[k];
		lazy[k] = 0;
	}
}
void upd(int k, int l, int r, int a, int b, int val) {
	if(l == a && r == b) {
		t[k] = val;
		lazy[k] = val;
		return;
	}
	pushdown(k);
	int mid = (l + r) >> 1;
	if(b <= mid) upd(k<<1,l,mid,a,b,val);
	else if(a > mid) upd(k<<1|1,mid+1,r,a,b,val);
	else upd(k<<1,l,mid,a,mid,val),upd(k<<1|1,mid+1,r,mid+1,b,val);
	pushup(k);
}
int que(int k,int l,int r,int a,int b) {
	if(l==a&&r==b) return t[k];
	pushdown(k);
	int mid = (l + r) >> 1;
	if(b <= mid) return que(k<<1,l,mid,a,b);
	else if(a > mid) return que(k<<1|1,mid+1,r,a,b);
	else return min(que(k<<1,l,mid,a,mid),que(k<<1|1,mid+1,r,mid+1,b));
}
signed main() {
    freopen("rmq.out", "w", stdout);
    freopen("rmq.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	n = read(), m = read();
	build(1, 1, n);
	REP(i, 1, m + 1) {
		Q[i].se.fi = read();
		Q[i].se.se = read();
		Q[i].fi = read();
	}
	std::sort(Q + 1, Q + m + 1);
	bool fl = 1;
	REP(i, 1, m + 1) {
		upd(1, 1, n, Q[i].se.fi, Q[i].se.se, Q[i].fi);
	}
	REP(i, 1, m + 1) {
		fl &= que(1, 1, n, Q[i].se.fi, Q[i].se.se) == Q[i].fi;
	}
	if(fl) {
		puts("consistent");
		REP(i, 1, n + 1) printf("%d ", que(1,1,n,i,i));
	}
	else puts("inconsistent");
    return 0;
}