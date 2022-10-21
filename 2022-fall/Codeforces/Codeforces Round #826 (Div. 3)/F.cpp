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
int a[MN], b[MN], c[MN], ans[MN], n, m;
int cal(int l, int r, int x) {
    if(x >= l && x <= r) return 0;
    return min(abs(x - l), abs(x - r));
}
std::vector<pair<pii, pii > > p;
void solve2(int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    solve2(l, mid);
    solve2(mid + 1, r);

    // dbg1(l); dbg2(r);

    std::vector<pii> cc; cc.clear();
    REP(i, l, mid + 1) {
        // dbg1(p[i].fi.fi); dbg1(p[i].fi.se);
        // dbg2(p[i].se.fi); dbg2(p[i].se.se);
        cc.pb(mkp(p[i].fi.se, p[i].se.fi));
    }
    std::sort(cc.begin(), cc.end());
    std::vector<pii> ccc;
    DREP(i, cc.size() - 1, -1) {
        // dbg1(xx.fi), dbg2(xx.se);
        if(!ccc.size()) ccc.pb(cc[i]);
        else if(cc[i].se != ccc[0].se) {ccc.pb(cc[i]); break;}
    }
    int siz = cc.size() - 1;
    REP(i, mid + 1, r + 1) {
        int col = p[i].se.fi;
        // dbg2(col);
        REP(j, 0, ccc.size()) {
            // dbg1(cc[j].se);
            // dbg2(cc[j].fi);
            if(col != ccc[j].se && ccc[j].fi >= p[i].fi.se) {
                // dbg2(p[i].se.se);
                ans[p[i].se.se] = 0;
                // dbg2(n);
                // dbg1(cc[j].se);
                // dbg2(cc[j].fi);
                // dbg1(p[i].fi.fi);
                // dbg1(p[i].fi.se);
                // dbg1(p[i].se.fi);
                // dbg2(p[i].se.se);
            }
        }
    }
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read();
        REP(i, 1, n + 1) a[i] = read(), b[i] = read(), c[i] = read();
        p.clear();
        REP(i, 1, n + 1) p.pb(mkp(mkp(a[i], b[i]), mkp(c[i], i)));
        assert(p.size() == n);
        std::sort(p.begin(), p.end());
        REP(i, 1, n + 1) ans[i] = 0x3f3f3f3f;


        // for(auto XX : p) {
        //     dbg1(XX.fi.fi);
        //     dbg1(XX.fi.se);
        //     dbg1(XX.se.fi);
        //     dbg2(XX.se.se);
        // }

        std::multiset<int> Sl, Sr;
        std::multiset<int>::iterator it;
        REP(i, 1, n + 1) Sl.insert(a[i]), Sr.insert(b[i]);
        std::vector<int> col[n + 1];
        REP(i, 1, n + 1) col[c[i]].pb(i);
        REP(i, 1, n + 1) {
            for(auto id : col[i]) {
                Sl.erase(Sl.find(a[id]));
                Sr.erase(Sr.find(b[id]));
            }
            // for(auto l : Sl) dbg1(l); dbg3();
            // for(auto r : Sr) dbg1(r); dbg3();
            for(auto id : col[i]) {
                int l = a[id], r = b[id];
                int ret = 0x7fffffff;

                if(Sl.lower_bound(l) != Sl.end()) {
                    // if(id == 3) dbg2(*Sl.lower_bound(l));
                    ret = min(ret, cal(l, r, *Sl.lower_bound(l)));
                }
                if((it = Sr.upper_bound(r)) != Sr.begin()) 
                    ret = min(ret, cal(l, r, *(--it)));
                ans[id] = ret;
            }
            for(auto id : col[i]) {
                Sl.insert(a[id]);
                Sr.insert(b[id]);
            }
        }
        solve2(0, n - 1);
        REP(i, 1, n + 1) printf("%d ", ans[i]);puts("");
    }
    return 0;
}