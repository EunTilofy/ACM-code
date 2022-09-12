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
//Timur
std::set<std::pair<string, int> > a;
signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        int n = read();
        a.clear();
        REP(i, 0, n) {
            string s;
            cin >> s;
            a.insert(mkp(s, 1));
        }
        REP(i, 0, n) {
            string s;
            cin>>s;
            a.insert(mkp(s, 2));
        }
        REP(i, 0, n) {
            string s;
            cin>>s;
            a.insert(mkp(s, 3));
        }
        int nm[4];
        nm[1] = nm[2] = nm[3] = 0;
        for(auto x : a) {
            string s = x.fi; int _ = x.se;
            int NUM = a.count(mkp(s, 1)) + a.count(mkp(s, 2)) + a.count(mkp(s, 3));
            if(NUM == 1) nm[_] += 3;
            else if(NUM == 2) nm[_] += 1; 
        }
        printf("%d %d %d\n", nm[1], nm[2], nm[3]);
    }
    return 0;
}