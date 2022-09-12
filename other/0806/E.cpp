#include<bits/stdc++.h>
#define ll long long
#define db double
#define LL __int128
#define DB __float128
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1005;
int a[MN][MN];
bool b[MN];
int fa[MN];
int getf(int x) {return fa[x] == x ? x: fa[x] = getf(fa[x]);}
std::vector<int> G[MN];
int main() {
    int T = read();
    while(T--) {
        int n = read();
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) a[i][j] = read();
        for(int i = 1; i <= n; ++i) b[i] = 0, fa[i] = i, G[i].clear(), G[i].pb(i);
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) if(i != j){
            if(a[i][j] < a[j][i]) {
                //i == j
                int ii = getf(i);
                int jj = getf(j);
                if(ii == jj) continue;
                if(G[ii].size() > G[jj].size()) swap(ii, jj);
                int _ = (b[i] != b[j]);
                for(int k = 0; k < G[ii].size(); ++k) {
                    G[jj].pb(G[ii][k]);
                    b[G[ii][k]] ^= _;
                }
                G[ii].clear();
                fa[ii] = jj;
            }
            else if(a[i][j] > a[j][i]) {
                // i != j
                int ii = getf(i);
                int jj = getf(j);
                if(ii == jj) continue;
                if(G[ii].size() > G[jj].size()) swap(ii, jj);
                int _ = (b[i] == b[j]);
                for(int k = 0; k < G[ii].size(); ++k) {
                    G[jj].pb(G[ii][k]);
                    b[G[ii][k]] ^= _;
                }
                G[ii].clear();
                fa[ii] = jj;
            }
        }
        for(int i = 1; i <= n; ++i, puts("")) for(int j = 1; j <= n; ++j) {
            printf("%d ", (b[i] == b[j]) ? a[i][j] : a[j][i]);
        }
    }
    return 0;
}