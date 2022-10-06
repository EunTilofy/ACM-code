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
#define mod 1000000007
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
int n;
struct xxx {
	char s[10005];
	int k;
}a[105];
int num[26];
std::map<long long, int> qz, g, str;
int main() {
	n = read();
	REP(i, 0, n) scanf("%s", a[i].s + 1), a[i].k = read();
	int pos = 0;
	qz[0] = 0;
	str[0] = -1;
	REP(i, 0, n) {
		int len = strlen(a[i].s + 1);
		REP(j, 1, len + 1) {
			if(a[i].s[j] != str[pos + j - 1]) g[pos + j] = pos + j - 1;
			else g[pos + j] = g[pos + j - 1];
			str[pos + j] = a[i].s[j] - 'a' + 1;
		}
		if(g[pos + len] < pos) {
			
		}
		else {
			
		}
		pos += len * k;
	} 
}