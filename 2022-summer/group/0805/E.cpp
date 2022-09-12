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
#define int long long
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
const int MN = 1<<20;
int a[MN], b[MN];
struct que{
    int l, r, id;
}q[MN];
int cnt[1<<20][2], pos[1<<20], fx[1<<20];
long long ans[MN];
bool cmp(que x, que y) {return pos[x.l] == pos[y.l] ? x.r < y.r: pos[x.l] < pos[y.l];}
long long tmp;
void add(int x, int _pos) {
    // printf("Add %d %d\n", x, _pos);
    tmp += cnt[x][_pos & 1];
    ++cnt[x][_pos & 1];
}
void del(int x, int _pos) {
    // printf("DEL %d %d\n", x, _pos);
    --cnt[x][_pos & 1];
    tmp -= cnt[x][_pos & 1];
}
signed main() {
    int n = read(), Q = read();
    int S = b[n];
    for(int i = 1; i <= n; ++i) a[i] = read() - 1, b[i] = b[i - 1] ^ a[i];
    for(int i = 1; i <= Q; ++i) {
        q[i].l = read() - 1;
        q[i].r = read();
        q[i].id = i;
        ans[i] = 1ll * (q[i].r - q[i].l + 1) * (q[i].r - q[i].l) / 2;
    }
    int Bl = (int)sqrt(n + 3);
    for(int i = 0; i < MN; ++i) fx[i] = i ^ S;
    for(int i = 1; i <= n; ++i) pos[i] = (i - 1) / Bl + 1;
    std::sort(q + 1, q + Q + 1, cmp);
    int l = 0, r = -1;
    for(int i = 1; i <= Q; ++i) {
        int L = q[i].l, R = q[i].r;
        if(r < R) {for(r++;r<=R;r++) add(b[r], r);r--;}
        if(r > R) for(;r>R;r--) del(b[r], r);
        if(l < L) for(;l<L;l++) del(b[l], l);
        if(l > L) {for(l--;l>=L;l--)add(b[l], l);l++;}
        // printf("%lld\n", tmp);
       ans[q[i].id] -= tmp;
    } 
    for(int i = 1; i <= Q; ++i) printf("%lld\n", ans[i]);
    return 0;
}