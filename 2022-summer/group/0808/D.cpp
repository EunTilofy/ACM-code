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
inline long long read() {
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 2e5+5;
int a[MN], d[MN];
std::priority_queue<std::pair<int, int> > q;
std::vector<int> G[MN];
int main() {
    int n = read(), m = read();
    for(int i = 1; i <= m; ++i) {
        int x = read(); int y = read();
        G[x].pb(y); G[y].pb(x);
    }
    int x = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    d[1] = (x <= a[1]) ? (x/2) : x;
    q.push(mkp(d[1], 1));
    while(!q.empty()) {
        pii o = q.top(); q.pop();
        int id = o.se, dis = o.fi;
        if(d[id] > dis) continue;
        for(int i = 0; i < G[id].size(); ++i) {
            int to = G[id][i], now = d[id];
            if(d[id] <= a[to]) now /= 2;
            if(now > d[to]) {
                d[to] = now;
                q.push(mkp(d[to], to));
            }
        }
    }
    printf("%d\n", d[n]);
    return 0;
}