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
int a[101][101];
std::bitset<100> b[101], base[101];
bool has[101];

bool chk(int il, int jl, int ir, int jr) {
//	dbg1(il); dbg1(jl); dbg1(ir); dbg2(jr);
	REP(i, il, ir + 1) REP(j, jl, jr + 1) {
		b[i - il][j - jl] = a[i][j];
		base[i-il][j-jl]=0;
	}
	int n=ir-il;
	REP(i, 0, n + 1) has[i] = 0;
	int i,j,k;
    for(i=0;i<=n;++i)for(j=n;~j;--j) {
        if(b[i][j])
        {
            if(has[j]) b[i]^=base[j];
            else
            {
                base[j]=b[i];
                has[j] = 1;
                break;
            }
        }
	}
	int nm=0;
	REP(i, 0, n + 1) nm += has[i];
	if(nm == n + 1 || nm == n);
	else assert(0);
	
	return nm == n + 1;
}
signed main() {
     freopen("determinant.out", "w", stdout);
     freopen("determinant.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n = read();
    REP(i, 1, n + 1) a[1][i] = 1;
    REP(i, 1, n + 1) a[2][i] = i & 1;
	REP(i, 3, n + 1) {
		a[i][1] = 1;
		REP(j, i + 1, n + 1) {
			if(!chk(1, j - i + 1, i, j)) a[i][j] = 1;
		}
	}
    REP(i, 1, n + 1) {
		REP(j, 1, n + 1) printf("%d ", a[i][j]);
		puts("");
	}
    return 0;
}