#include<bits/stdc++.h>
#define ll long long
//#define int long long
// #define ll __int128
#define db __float128
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
db a[MN];
int n, m;
db C(int x,int y) {	
	db ret = 1.0;
	REP(i, 1, y + 1) ret = ret * (db)(x - i + 1) / (db)(y - i + 1);
	return ret;
}
signed main() {
    freopen("black-white-balls.out", "w", stdout);
    freopen("black-white-balls.in", "r", stdin);
    n = read(); int l1, l2;
    l1 = read(), l2 = read();
    m = read();
    if(m == 0) {
    	puts("0 0");
    	return 0;
   	}
    REP(i, 0, n + 1) {
    	if(i < l1 || i > (n - l2)) {continue;}
    	a[i] = C(i,l1) * C(n-i,l2);
//    	dbg2((double)a[i]);
    }
    
//    double xx = C(50, 25);
//    printf("%.20lf\n", xx);
    
    REP(i, 1, n + 1) a[i] += a[i - 1];
    
//	REP(i, 1, n + 1) dbg2((double)a[i]);
	
	int ansl = l1, ansr = n - l2;
    REP(l, l1, n-l2+1) {
    	REP(r, l, n-l2+1) {
    		if((a[r]-a[l-1]) * 100.00 >= a[n] * (db)m) {
    			if(ansr-ansl>r-l) {
    					ansr = r;
    					ansl = l;
    				}
    			break;
    		}
    	}
    }
    printf("%d %d",ansl, ansr);
    return 0;
}