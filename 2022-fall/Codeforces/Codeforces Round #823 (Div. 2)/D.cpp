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
int n;
char s[2][MN];
int nm[26][2][2], mid[2];
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read();
        scanf("%s", s[0]+1);
        scanf("%s", s[1]+1);
        memset(nm, 0, sizeof nm);
        REP(i, 1, n + 1) {
            if(i + i - 1 == n) mid[0] = s[0][i] - 'a', mid[1] = s[1][i] - 'a';
            else {
                bool fl = (i + i <= n);
                REP(j, 0, 2) {
                    nm[s[j][i]-'a'][j][fl]^=1;
                }
            }
        }
        bool ans = 1;
        REP(i, 0, 26) {
            if(n&1) {
                REP(j,0,2)if(mid[j]==i){
                    if(nm[i][0][0]!=nm[i][1][0]) nm[i][0][0]^=1;
                    else nm[i][0][1]^=1;
                }
            }
            ans&=!((nm[i][0][0]-nm[i][1][0])^(nm[i][0][1]-nm[i][1][1]));
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}