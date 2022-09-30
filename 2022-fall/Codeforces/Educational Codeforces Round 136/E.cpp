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
int f[2][MN][2];
int sm[2][MN], n;
char s[2][MN];
std::vector<int> G[2];
int get(int x, int l, int r) {
    if(l > r) return 0;
    return sm[x][r] - sm[x][l];
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read();
    scanf("%s%s", s[0] + 1, s[1] + 1);
    int sum = 0;
    s[0][1] = '1';
    REP(i, 1, n + 2) REP(j,0,2) sm[j][i] = sm[j][i-1] + s[j][i] == '1';
    int pos[2];
    pos[0] = pos[1] = n + 1;
    f[0][n+1][0] = f[0][n+1][1] = f[1][n+1][0] = f[1][n+1][1] = 0;
    DREP(i,n,0) {
    DREP(j,1,-1){
        //f[j][i]
        if(s[j][i] != '1') continue;
        ++sum;
        // from the same line
        int ret = inf;
        if(pos[j] == n+1 || pos[j^1] == n+1) ret = 0;
        ret = min(f[j][pos[j]][0] + sm[j^1][pos[j] - 1] - sm[j^1][i-1], ret);
        ret = min(f[j^1][pos[j^1]][1] + sm[j][pos[j^1]+1] - sm[j][i], ret);
        if(s[j^1][i] == '1') {
            int rett = (s[j][i+1] == '1');
            if(G[j].size() <= 1 && pos[j] == i + 1) {
                ret = min(ret, 1 + f[j^1][pos[j^1]][0]);
            }
            else {
                int nm = G[j].size() - 2;
                int nexj = pos[j] == i + 1 ? G[j][nm] : pos[j];
                int nexj_ = pos[j^1];
                ret = min(ret, f[j^1][nexj_][0] + sm[j][nexj_ - 1] - sm[j][i]);
                ret = min(ret, rett + f[j][nexj][1] + sm[j^1][nexj + 1] - sm[j^1][i]);
            }
        }
        f[j][i][0] = ret;
        // from another line
        ret = inf;
        int nexj_ = pos[j^1];
        if(nexj_ == i + 1 && G[j^1].size() <= 1) ret = 0;
        else {
            if(nexj_ == i + 1) nexj_ = G[j^1][G[j^1].size() - 2];
            int nexj = pos[j];
            ret = min(ret, f[j^1][nexj_][1] + get(j, nexj_ + 1, i));
            ret = min(ret, f[j][nexj][0] + get(j^1, nexj -1 , i + 1));
        }
        f[j][i][1] = ret;
    }
        DREP(j, 1, -1) {
            if(s[j][i] == '1') {
                pos[j] = i;
                G[j].pb(i);
            }
        }
    }
    printf("%d\n", sum-f[0][1][0]);
    return 0;
}