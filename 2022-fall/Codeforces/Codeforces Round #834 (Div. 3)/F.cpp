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
int a[105], n, m;
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; cin>>T;
    while(T--) {
        memset(a, 0, sizeof a);
        cin>>n>>m;
        REP(i, 1, n+1) cin>>a[i];
        std::set<int> S;
        REP(i, 1, n+1) S.insert(a[i]);
        int mx = m - 1, mn = 0;
        while(S.count(mx)) mx--;
        while(S.count(mn)) mn++;
        if(mx == -1) {
            cout<<0<<endl;
        }
        else {
            long long ans = 0;
            if(mx > a[n]){
                ans = mx - a[n];
                if(mn < a[n]) {
                    mn = a[n];
                    ans = m - a[n];
                    a[n] = 0; a[n - 1] ++;
                    for(int j = n - 1; j >= 0; --j) {
                        S.insert(a[j]);
                        if(a[j] < m) break;
                        a[j] = 0;
                        a[j-1] ++;
                    }
                    while(S.count(mn)) mn--;
                    if(mn >= 0) ans += mn;
                }
            }
            else {
                ans = m - a[n];
                mn = a[n];
                a[n] = 0;
                a[n - 1] ++;
                for(int j = n - 1; j >= 0; --j) {
                        S.insert(a[j]);
                        if(a[j] < m) break;
                        a[j] = 0;
                        a[j-1] ++;
                    }
                    while(S.count(mn)) mn--;
                    // dbg2(mn);
                    if(mn >= 0) ans += mn;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}