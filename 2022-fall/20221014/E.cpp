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
inline int qpow(int x,ll y,int m=mod) {
	int r=1;
	for(; y; y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;
	return r;
}
inline int Add(int x, int y) {
	return (x + y) % mod;
}
inline int Mul(int x, int y) {
	return 1ll * x * y % mod;
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
const int MN = 3e5 + 5;
//int a[MN], b[MN], c[MN], n, m;
signed main() {
//	freopen("pour.out", "w", stdout);
//	freopen("pour.in", "r", stdin);
	// std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, a, b;
	n = read();
	a = read();
	b = read();
	b = b / a;
	a = 1;
	if(b == 1) puts("2");
	else if(b == 2) {
		if((n/b)&1) puts("1");
		else puts("2");
	} else if(n <= b) {
		if(n & 1) puts("2");
		else puts("1");
	} else {
		int f=0,x=0,y;
		for(int i=1; i<=n; i++) {
			if(!x) {
				if(i==n) {
					x=1;
					break;
				} else x=2,i++;
			} else {
				x++;
				if(x==b)y=x,x=0;
			}
			f=!f;
//			printf("%d %d %d\n",i,x,f);
		}
		if(x&&x+y<=b)f=!f;
//		printf("%d %d\n",x,f);
		f=!f,printf("%d",f+1);
	}
	return 0;
}