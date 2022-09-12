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
inline long long read()
{
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e6 + 5;
int n;
int a[MN], b[MN];
std::vector<std::pair<int, pii> > I;
int t[MN];
void C(int x, int y) {for(; x <= n; x += (x & -x)) t[x] += y;}
int G(int x) {int ret = 0; for(; x; x -= (x & -x)) ret += t[x]; return ret;}
int cal(int l, int r) {
    if(l > r) return 0;
    return G(r + 1) - G(l);
}
int _[MN];
void upd(int x, int y){C(x + 1, y - _[x]); _[x] = y;}
int app[MN], dis[MN];
std::vector<int> App[MN], Dis[MN];
int main() {
    n = read();
    REP(i, 1, n + 1) a[i] = read();
    int posl = n + 1, posr = n;
    long long ans = 0;
    DREP(i, n, 0) {
        if(a[i] == 1) posl = i;
        if(b[a[i]]) {
            posr = min(posr, b[a[i]] - 1);
        }
        b[a[i]] = i;
        //add interval l = i, r = ?
        int l = i, r = i, val = a[i];
        while(I.size()) {
            pair<int, pii> o = I.back();
            if(o.fi <= val) {
                r = o.se.se;
                upd(I.size() - 1, 0);
                I.pop_back();
            }
            else break;
        }
        I.pb(mkp(val, mkp(l, r)));
        int ID = I.size() - 1;
        int a_ = r - val + 1, b_ = l - val;
        app[ID] = a_;
        dis[ID] = b_;
        if(app[ID] >= i && i > dis[ID]) upd(ID, 1);
        else upd(ID, 0);
        if(app[ID] > 0 && app[ID] < i) App[app[ID]].pb(ID);
        if(dis[ID] > 0 && dis[ID] < i) Dis[dis[ID]].pb(ID);

        REP(o, 0, App[i].size()) {
            int IDD = App[i][o];
            if(app[IDD] == i) upd(IDD, 1);
        }
        REP(o, 0, Dis[i].size()) {
            int IDD = Dis[i][o];
            if(dis[IDD] == i) upd(IDD, 0);
        }
        App[i].clear();
        Dis[i].clear();

        if(posl <= posr) {
            //posl
            int id_l;
            l = 0, r = I.size() - 1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(I[mid].se.fi <= posl && I[mid].se.se >= posl) {id_l = mid; break;}
                else if(posl > I[mid].se.se) r = mid - 1;
                else l = mid + 1;
            }
            //posr
            int id_r;l = 0; r= I.size() - 1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(I[mid].se.fi <= posr && I[mid].se.se >= posr) {id_r = mid; break;}
                else if(posr > I[mid].se.se) r = mid - 1;
                else l = mid + 1;
            }
            int res = cal(id_r + 1, id_l - 1);
            //cal id_l
            int VAL = I[id_l].fi;
            int ned = i + VAL - 1;
            if(ned >= posl && ned <= posr && ned >= I[id_l].se.fi && ned <= I[id_l].se.se) ++res;
            //cal id_r
            VAL = I[id_r].fi;
            ned = i + VAL - 1;
            if(id_l != id_r && ned >= posl && ned <= posr && ned >= I[id_r].se.fi && ned <= I[id_r].se.se) ++res;
            ans += res;
        }
    }
    printf("%lld\n", ans);
    return 0;
}