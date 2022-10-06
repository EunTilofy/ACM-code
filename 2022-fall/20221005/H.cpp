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
int a[MN], b[MN], c[MN], n, m, k;
std::priority_queue<pii> q; 
std::vector<std::pair<pii, int> > G[MN];
std::vector<pii> pre[MN];
pii Pre[MN];
void dij(int S) {
    q.push(mkp(0, S));
    memset(a, 0x3f, sizeof a);
    a[S] = 0;
    // dbg3(survive);
    while(!q.empty()) {
        pii _ = q.top();
        q.pop();
        int x = _.se;
        // dbg2(x);
        int dis = _.fi;
        if(a[x] < -dis) continue;
        REP(i, 0, G[x].size()) {
            int y = G[x][i].fi.fi;
            if(a[y] >= a[x] + G[x][i].fi.se) {
                if(a[y] == a[x] + G[x][i].fi.se) {
                    pre[y].pb(mkp(x, G[x][i].se));
                }
                else {
                    while(pre[y].size()) pre[y].pop_back();
                    pre[y].pb(mkp(x, G[x][i].se));
                    a[y] = a[x] + G[x][i].fi.se;
                    q.push(mkp(-a[y], y));
                }
            }
        }
    }
}
int tot;
int print[MN];
int step[MN];
int id[MN];
bool cmp(int x, int y) {
    return a[x] < a[y];
}
// bool vis[MN];
// void dfs(int x, int st) {
//     // dbg1(x); dbg2(st);
//     if(vis[x]) return;
//     vis[x] = 1;
//     if(st == k) {
//         printf("%d\n", tot);
//         REP(i, 1, tot + 1) {
//             printf("%d ", print[i]);
//         }
//         exit(0);
//     }
//     REP(i, 0, G[x].size()) {
//         int y = G[x][i].fi.fi;
//         int len = G[x][i].fi.se;
//         int ID = G[x][i].se;
//         if(a[y] != a[x] + len) continue;
//         if(step[y] > 0 && step[y] != st + 1) continue;
//         // dbg1(y); dbg1(len); dbg2(ID);
//         print[++tot] = ID;
//         dfs(y, st + (step[y] == st + 1));
//         --tot;
//     }
// }


signed main() {
    freopen("recover.out", "w", stdout);
    freopen("recover.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read(), m = read();
    REP(i, 0, m) {
        int x = read();
        int y = read();
        int t = read();
        G[x].pb(mkp(mkp(y, t), i + 1));
        G[y].pb(mkp(mkp(x, t), i + 1));
    }
    k = read();
    REP(i, 0, k) {
        c[b[i] = read()] = 1;
    }
    if(k == 1) {
        c[b[k++] = b[1] % n + 1] = 1;
    }
    dij(b[1]);
    int _ = b[1];
    REP(i, 0, k) if(a[b[i]] > a[_]) _ = b[i];
    dij(_);
    // dbg1(_);
    int _2 = b[1];
    REP(i, 0, k) if(a[b[i]] > a[_2]) _2 = b[i];
    // dbg1(_); dbg2(_2);
    
    REP(i, 1, n + 1) id[i] = i;
    // REP(i, 1, n + 1) dbg1(a[i]);dbg3();
    std::sort(id + 1, id + n + 1, cmp);


    step[_] = 1;
    assert(id[1] == _);
    REP(i, 2, n + 1) {
        int x = id[i];
        int J = 0;
        REP(j, 0, pre[x].size()) {
            int y = pre[x][j].fi;
            if(step[y] > step[pre[x][J].fi]) J = j;
        }
        Pre[x] = pre[x][J];
        step[x] = step[Pre[x].fi] + (c[x]);
    }
    for(int now = _2; now != _; ) {
        print[++tot] = Pre[now].se;
        now = Pre[now].fi;
    }
    printf("%d\n", tot);
    REP(i, 1, tot + 1) {
        printf("%d ", print[i]);
    }
    return 0;
}