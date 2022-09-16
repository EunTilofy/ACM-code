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
#define M 310
struct node {
	int s, v, id;
} a[M];
pair<ll, ll> b[M];
int n;
int chk(node x,node y,node z) {
	y.s -= x.s, y.v -= x.v, y.id -= x.id;
	z.s -= x.s, z.v -= x.v, z.id -= x.id;
	if(1ll * y.s * z.id == 1ll * z.s * y.id && 1ll * y.v * z.id == 1ll * z.v * y.id) return 2;
	if(1ll * y.v * z.id == 1ll * z.v * y.id) return 1;
	return 0;
}

ll gcd(ll A, ll B) {
	return B ? gcd(B, A % B): A;
}

pair<ll, ll> get(node x, node y, node z) {
	y.s -= x.s, y.v -= x.v, y.id -= x.id;
	z.s -= x.s, z.v -= x.v, z.id -= x.id;
	ll A = 1ll * z.id * y.v - 1ll * z.v * y.id;
	ll B = 1ll * z.s * y.id - 1ll * z.id * y.s;
	ll tmp = gcd(abs(A), abs(B));
	if(tmp) A /= tmp, B /= tmp;
	if(B < 0) A = -A, B = -B;
	if(B == 0) A = 0;
	return make_pair(B, A);
}

int main() {
//	node A=(node){-7,1,0};
//	node B=(node){-6,2,4};
//	node C=(node){-5,3,8};
//	printf("%d",chk(A,B,C));
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		a[i].s = read(), a[i].v = read();
		a[i].id = i;
	}
	int Ans = min(2, n);
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++) {
			int res=2, tot = 0;
			for(int k=1; k<=n; k++)
				if(k!=i&&k!=j) {
					int pos = chk(a[i],a[j],a[k]);
					if(pos == 2)res++;
					else if(!pos) {
						pair<ll, ll> tmp = get(a[i], a[j], a[k]);
						if(tmp.second >= 0) b[++tot] = tmp;
					}
			}
			sort(b + 1, b + 1 + tot);
			for(int u = 1; u <= tot; ++u) {
				int v = u;
				for(; v + 1 <= tot && b[v + 1] == b[u]; ++v) ;
				Ans = max(Ans, res + v - u + 1);
				u = v;
			}
	}
	printf("%d\n", Ans);
	return 0;
}