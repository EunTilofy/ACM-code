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
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN], n, m;
int ans1, ans2;
signed main() {
     freopen("output.txt", "w", stdout);
     freopen("input.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n = read();
    REP(i, 1, n + 1) a[i] = read();
    double ans = 20000 * 400.00;
    REP(i, 1, n + 1) REP(j, i + 1, n + 1) {
		double aans = 0.0;
		REP(k, 1, n + 1) {
			if(k == i || k == j);	
			else {
				double pos = a[i] + (k - i) * (db)(a[i] - a[j]) / (db)(i - j);
				aans += fabs(pos - (db)a[k]);
			}
		}
		if(aans < ans) {
			ans = aans;
			ans1 = i;
			ans2 = j;
		}
	}
	printf("%.10lf\n", ans);
	REP(i, 1, n + 1) {
		if(i == ans1 || i == ans2) {
			printf("%.10lf ", (db)a[i]); 
		}
		else {
			double pos = a[ans1] + (i - ans1) * (db)(a[ans2] - a[ans1]) / (db)(ans2 - ans1);
			printf("%.10lf ", (db)pos);
		}
	}
	return 0;
}