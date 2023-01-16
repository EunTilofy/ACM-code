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
int a[MN], c[MN], d[MN], n;
int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>n; n>>=1;
        std::set<int> ss;
        bool fl1 = 1;
        REP(i, 1, n + 1) {
            cin>>a[i];
            if(ss.count(a[i])) fl1 = 0;
            ss.insert(a[i]);
        }
        if(fl1 == 0) {
            cout<<"-1"<<endl;
            continue;
        }
        std::vector<int> b, tt;
        REP(i, 1, n + 1) b.pb(a[i]);
        std::sort(b.begin(), b.end());
        for(int i = 1; i <= n; ++i) {
            c[i] = b[i-1] - 1 - (i - 1);
            tt.pb(c[i]);
        }
        bool fl = 1;
        std::sort(tt.begin(), tt.end());
        for(int i = 1; i <= n; ++i) {
            fl &= i <= tt[i-1];
        }
        if(!fl) cout<<"-1"<<endl;
        else {
            std::set<int> ap;
            for(int i = 1; i <= n; ++i) {
                ap.insert(a[i]);
            }
            std::set<int> _;
            for(int i = 1; i <= n * 2; ++i) if(!ap.count(i)) _.insert(i);
            for(int i = n; i; --i) {
                std::set<int>::iterator it;
                it=_.lower_bound(a[i]); --it;
                int num = a[i];
                d[i] = *it;
                _.erase(d[i]);
            }
            for(int i = 1; i <= n; ++i) cout<<d[i]<<" "<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}