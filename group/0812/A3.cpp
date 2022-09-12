#include<bits/stdc++.h>
#define ll long long
#define db double
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
const int MN = 5005;
int a[MN], b[MN], tot, c[MN], id[MN], idd[MN];
int e[2][MN];
std::map<int, int> val;
std::vector<pii> pr[MN];
bool lef[MN], putleft[MN];
void solve(int l, int r) {
    // id[l] ~ id[r] in d[L] ~ d[R]
    if(l >= r) return ;
    // dbg1(l); dbg2(r);
    memset(putleft, 0, sizeof(putleft));
    for(int i = r; i >= l; --i) {
        if(pr[id[i]].size()) {
            // dbg2(id[i]);
            for(int j = 0; j < pr[id[i]].size(); ++j) {
                int x = pr[id[i]][j].fi;
                int y = pr[id[i]][j].se;
                // dbg1(x); dbg2(y);
                if(!pr[x].size() && !pr[y].size()) {
                    if(!lef[x]) putleft[x] = 1;
                    if(!lef[y]) putleft[y] = 1;
                }
            }
            int _l = l, __l;
            for(int j = l; j <= r; ++j) {
                if(putleft[id[j]]) idd[_l++] = id[j], lef[id[j]] = 1;
            }
            idd[_l++] = id[i]; lef[id[i]] = 1;
            putleft[id[i]] = 1;
            __l = _l;
            // dbg2(_l);
            for(int j = l; j <= r; ++j) {
                if(!putleft[id[j]]) idd[_l++] = id[j];
            }
            for(int j = l; j <= r; ++j) id[j] = idd[j];
            // for(int j = l; j <= r; ++j) dbg1(id[j]); dbg3();
            solve(__l, r);
            return;
        }
    }
    return ;
}

signed main() {
    int n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    std::sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) {
        if(a[i] > a[i - 1]) {
            b[++tot] = a[i];
            c[tot] = 1;
        }
        else ++c[tot];
    }
    n = tot;
    for(int i = 1; i <= n; ++i) if(c[i]>2) {
        return 0 * puts("NO");
    }
    for(int i = 1; i <= n; ++i) id[i] = i;    
    // for(int i = 1; i <= n; ++i) printf("%d %d %d\n", id[i], b[i], c[i]);
    val.clear();
    for(int i = 1; i <= n; ++i) val[b[i]] = i;
    for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) {
        if((b[i] + b[j])&1) continue;
        int val_mid = (b[i] + b[j]) / 2;
        if(val[val_mid]) {
            pr[val[val_mid]].pb(mkp(i, j));
        }
    }
    solve(1, n);
    puts("YES");
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= c[id[i]]; ++j) printf("%d ", b[id[i]]);
    }
    return 0;
}