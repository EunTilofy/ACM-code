#include<bits/stdc++.h>
#define ll long long
#define int long long
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
int a[MN], b[MN], c[MN], d[MN], n, m;
// int t[MN<<2];
// bool lazy[MN<<2];
// void build(int k, int l, int r) {
//     if(l == r) {t[k] = a[l]; return;}
//     int mid = (l + r) >>1;
//     build(k<<1,l,mid);
//     build(k<<1|1,mid+1,r);
//     t[k]=t[k<<1]+t[k<<1|1];
// }
// void pd(int k,int l,int r) {
//     if(lazy[k]) {
//         int mid = (l+r)>>1;
//         lazy[k<<1]=lazy[k<<1|1]=1;
//         t[k<<1]=c[mid]-c[l-1];
//         t[k<<1|1]=c[r]-c[mid];
//         lazy[k] = 0;
//     }
// }
// int que(int k,int l,int r,int a, int b) {
//     if(l==a&&r==b){return t[k];}
//     pd(k,l,r);
//     int mid=(l+r)>>1;
//     if(b<=mid) return que(k<<1,l,mid,a,b);
//     else if(a>mid) return que(k<<1|1,mid+1,r,a,b);
//     else return que(k<<1,l,mid,a,mid)+que(k<<1|1,mid+1,r,mid+1,b);
// }
char s[MN];
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    int T = read();
    while(T--) {
        n = read(), m = read();
        std::vector<int> G[n+1];
        int i, j;
        REP(i, 1, n + 1) a[i] = read(), d[i] = d[i - 1] + a[i];
        REP(i, 1, n + 1) b[i] = read(), c[i] = c[i - 1] + b[i];
        REP(i, 1, n + 1) d[i] -= c[i];//, dbg1(d[i]);dbg3();
        std::set<int> S;
        std::queue<int> q;
        REP(i, 1, n + 1){if(d[i]) S.insert(i); else q.push(i);}
        REP(i, 1, m + 1){
            int x = read()-1;
            int y = read();
            G[x].pb(y); G[y].pb(x);
        }
        // std::sort(p.begin(), p.end());
        S.insert(n+1);
        q.push(0);
        while(!q.empty()) {
            int x=q.front(); q.pop();
            //dbg2(x);
            for(auto y : G[x]) {
                //dbg2(y);
                int l=min(x,y);
                int r=max(x,y);
               // dbg1(x); dbg2(y); dbg2(d[y]);
                if(d[l]==0&&d[r]==0) {
                    int nm=*S.lower_bound(l);
                   // dbg2(nm);
                    while(nm<=r){
                        S.erase(nm);
                        q.push(nm);
                        d[nm]=0;
                        nm=*S.lower_bound(nm);
                    }
                }
            }
        }
        if(S.size()==1) puts("YES");
        else puts("NO");
    }
    return 0;
}