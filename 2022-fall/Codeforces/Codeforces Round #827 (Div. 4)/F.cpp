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
int a[MN], b[MN], c[MN], n, m;
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read();
        long long mins = 1, maxt = 1;
        long long nms = 1, nmt = 1;
        long long lens = 1, lent = 1;
        while(n --) {
            int opt = read();
            m = read();
            string s;
            std::cin>>s;
            if(opt == 1) {
                lens += 1ll * m * s.size();
                int _ = 0;
                for(auto x : s) _ += x == 'a';
                nms += 1ll * _ * m;
            }
            else {
                int _ = 0;
                for(auto x : s) {
                    _ += x == 'a';
                    maxt = max(maxt, x - 'a' + 1ll);
                }
                nmt += 1ll * _ * m;
                lent += 1ll * m * s.size();
            }
            if(mins != maxt) puts("YES");
            else {
                if(nms == lens && (nmt > nms || nmt == nms && lent > lens)) puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}