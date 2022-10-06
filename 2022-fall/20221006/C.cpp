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
long long N;
int nm[10];
long long sm = 0;
int main() {
	scanf("%lld", &N);
	if(N == 0) return 0 * puts("-1");
	if(N == 999999999) return 0 * puts("-1"); 
	long long NN = N;
	while(N) {
		nm[N % 10] ++;
		sm += N % 10;
		N /= 10;
	}
	if(sm < 10) {
		if(sm == NN) return 0 * printf("%lld", sm * 10);
		return 0 * printf("%lld", sm);
	}
	if(NN <= 100000000) {
		return 0 * printf("%lld\n", NN * 10);
	}
	if(nm[0] > 0) {
		REP(i, 1, 10) REP(j, 0, nm[i]) printf("%d", i);
		return 0;
	}
	REP(i, 1, 10) {
		if(nm[i] == 9) {
			REP(j, 0, 7) printf("%d", i);
			printf("%d%d", i - 1, i + 1);
			return 0;
		}
	}
	long long nm1 = 0, nm2 = 0;
	REP(i, 1, 10) REP(j, 0, nm[i]) nm1 = nm1 * 10 + i;
	DREP(i, 9, 0) REP(j, 0, nm[i]) nm2 = nm2 * 10 + i; 
	if(nm1 != NN) return 0 * printf("%lld\n", nm1);
	printf("%lld\n", nm2);
	return 0;
}