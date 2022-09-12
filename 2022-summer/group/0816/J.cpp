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
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1000 + 5;
int n;
string s, t, a[MN];
int fs[MN], ft[MN], f[MN][MN];

int dp[10005][10005];

int getf(string S, string T) {
    int lens = S.size(), lent = T.size();
    REP(i, 0, lens + 1) REP(j, 0, lent + 1) dp[i][j] = inf;
    dp[0][0] = 0;
    REP(i, 0, lens + 1) REP(j, 0, lent + 1) if(i + j > 0) {
        if(i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        if(i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (S[i-1]!=T[j-1]));        
    }
    return dp[lens][lent];
}

int id[MN], _ans[MN], pre[MN];
bool cmp(int x, int y) {
    return fs[x] < fs[y];
}
void dfs(int _) {
    if(!_) return;
    dfs(pre[_]);
    std::cout<<a[id[_]]<<'\n';
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s>>t;
    n = read();
    REP(i,1,n + 1) cin>>a[i];
    REP(i,1,n + 1) fs[i] = getf(s, a[i]);
    REP(i,1,n + 1) ft[i] = getf(a[i], t);
    REP(i,1,n + 1) REP(j, i+1, n + 1) f[i][j]=f[j][i]=getf(a[i],a[j]);
    REP(i,1,n + 1) id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    int ans = getf(s, t);
    REP(i,1,n + 1) {
        if(ans == fs[id[i]] + ft[id[i]]) {
            _ans[i] = 1; pre[i] = 0;
            REP(j, 1, i) if(_ans[j]) if(ans == fs[id[j]] + ft[id[i]] + f[id[j]][id[i]])
                if(_ans[j] + 1 > _ans[i]) {
                    _ans[i] = _ans[j] + 1;
                    pre[i] = j; 
                }
        }
    }
    int ans_id = 0;
    REP(i,1,n + 1) if(_ans[i]>_ans[ans_id]) ans_id = i;
    printf("%d %d\n", ans, _ans[ans_id]);
    dfs(ans_id);
    return 0;
}