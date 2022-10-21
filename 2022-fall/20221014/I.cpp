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
const int MN = 2e5 + 5;
int a[MN], f[MN], n;
string s;
std::vector<int> G[MN];
int mx[MN], len[MN], dep[MN];
void DFS(int x, int fa) {
    f[x] = fa;
    dep[x] = dep[fa] + 1;
    len[x] = 1;
    for(auto y : G[x]) {
        if(y == fa) continue;
        DFS(y, x);
        if(len[y] > len[mx[x]]) mx[x] = y;
        len[x] = len[mx[x]] + 1;
    }
}
int tot = 0;
int pos[MN], LEN[MN];
void DFS2(int x, int fa, int top) {
    if(x == top) {
        pos[x] = tot + 1;
        tot += len[x] * 2 + 3;
        LEN[x] = len[x] + 1;
    }
    else pos[x] = pos[fa], LEN[x] = LEN[fa];
    if(mx[x]) DFS2(mx[x], x, top);
    for(auto y : G[x]) {
        if(y == fa || y == mx[x]) continue;
        DFS2(y, x, y);
    }
}
int q[MN<<2];
int L[MN], R[MN]; // val
int LL[MN], RR[MN]; // pos_id
int ans0[MN], ans1[MN][2], len1[MN];
void DFS3(int x, int fa) {
    if(mx[x]) {
        DFS3(mx[x], x);
        L[x] = L[mx[x]] + a[x];
        R[x] = R[mx[x]] + a[x];
        LL[x] = LL[mx[x]];
        RR[x] = RR[mx[x]];
        if(a[x] < L[x]) q[--LL[x]] = x, L[x]--;
        if(a[x] > R[x]) q[++RR[x]] = x, R[x]++;
    }
    if(len[x] == 1) {
        L[x] = R[x] = a[x];
        LL[x] = RR[x] = pos[x] + LEN[x];
        q[LL[x] + a[x] - L[x]] = x;
        // dbg1(x); dbg1(L[x]); dbg2(R[x]);
        // dbg1(LL[x]); dbg2(RR[x]);
        return;
    }

    if(L[x]<=0&&R[x]>=0) ans0[x] = q[LL[x] + 0 - L[x]];

    for(auto y : G[x]) {
        if(y == mx[x] || y == fa) continue;
        DFS3(y, x);
        REP(val, L[y], R[y] + 1) {
            int vval = -val;
            if(vval <= R[x] && vval >= L[x]) {
                int xx = q[LL[y] + val - L[y]];
                int yy = q[LL[x] + vval - L[x]];
                if(dep[xx] + dep[yy] - 2 * dep[x] + 1 > len1[x]) {
                    len1[x] = dep[xx] + dep[yy] - 2 * dep[x] + 1;
                    ans1[x][0] = xx;
                    ans1[x][1] = yy;
                }
            }
        }
        int LLL = L[y] + a[x];
        int RRR = R[y] + a[x];
        REP(val, LLL, RRR + 1) {
            if(val < L[x]) {LL[x] -= L[x] - val; L[x] = val;}
            if(val > R[x]) {RR[x] += val - R[x]; R[x] = val;}
            if(dep[q[LL[y] + val - a[x] - L[y]]] > dep[q[LL[x] + val - L[x]]]) 
                q[LL[x] + val - L[x]] = q[LL[y] + val - a[x] - L[y]];
        }
    }
}
signed main() {
    freopen("shoes.out", "w", stdout);
    freopen("shoes.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read();
    std::cin>>s;
    REP(i, 1, n + 1) {
        a[i] = (s[i - 1] == 'L') ? 1 : -1;
        ans0[i] = len1[i] = -1;
    }
    REP(i, 1, n) {
        int x = read();
        int y = read();
        G[x].pb(y);
        G[y].pb(x);
    }
    DFS(1, 0);
    DFS2(1, 0, 1);
    DFS3(1, 0);
    int Ans = -1, if0 = -1, id = -1;
    REP(i, 1, n + 1) {
    	if(ans0[i] != -1) {
			if(Ans < dep[ans0[i]] - dep[i] + 1) {
				Ans = dep[ans0[i]] - dep[i] + 1;
				if0 = 1;
				id = i;
			}
		}
		if(len1[i] > Ans) {
			Ans = len1[i];
			if0 = 0;
			id = i;
		}
    }
    if(Ans == -1) puts("0");
    else {
        std::vector<int> prt[2];
        if(if0) {
            int oo = ans0[id];
            while(oo != id) prt[0].pb(oo), oo = f[oo];
            prt[0].pb(oo);
        }
        else {
            // dbg1(id); dbg1(ans1[id][0]); dbg2(ans1[id][1]);
            // dbg2(len1[id]);
            int oo = ans1[id][0];
            while(oo != id) prt[0].pb(oo), oo = f[oo];
            prt[0].pb(oo);
            oo = ans1[id][1];
            while(oo != id) prt[1].pb(oo), oo = f[oo];
        }
        printf("%d\n", prt[0].size() + prt[1].size());
        for(auto o : prt[0]) printf("%d ", o);
        reverse(prt[1].begin(), prt[1].end());
        for(auto o : prt[1]) printf("%d ", o);
    }
    return 0;
}