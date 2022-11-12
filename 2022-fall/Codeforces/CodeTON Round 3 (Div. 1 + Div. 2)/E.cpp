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
const int MN = 4e5 + 5;
int a[MN], b[MN], n;
long long t1[MN], t2[MN];
void C(long long *t, int x, long long y) {
    for(;x<=(n*2+1);x=x+(x&-x)) t[x]+=y;
}
long long G(long long *t, int x) {
    long long ret = 0ll;
    for(;x;x-=(x&-x)) ret = ret + t[x];
    return ret;
}
long long cal(long long *t, int l, int r) {
    return G(t, r) - G(t, l - 1);
} 
signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) {
        cin>>n; string s; cin>>s;
        REP(i, 0, n) a[i] = s[i] == '(' ? 1 : -1;
        b[0] = a[0];
        REP(i, 1, n) b[i] = b[i - 1] + a[i];
        long long ans = 0ll;
        DREP(i, n - 1, -1) {
            C(t1, b[i]+n+1, 1);
            C(t2, b[i]+n+1, b[i]);
            int L = b[i]-a[i];
            ans += cal(t2, L+n+1, n+n+1) - 1ll * cal(t1, L+n+1, n+n+1) * L;
        }
        REP(i, 0, n * 2 + 2) t1[i] = t2[i] = 0;
        stack<pii> st;
        DREP(i, n - 1, -1) {
            while(st.size() && st.top().se>=b[i]) {
                int id = st.top().fi, val = st.top().se;
                st.pop();
                int Latter = n;
                if(st.size()) Latter = st.top().fi;
                C(t1, val + n + 1, -(Latter - id));
                C(t2, val + n + 1, -1ll * (Latter - id) * val);
            }
            int Latter = n;
            if(st.size()) Latter = st.top().fi;
            C(t1, b[i] + n + 1, (Latter - i));
            C(t2, b[i] + n + 1, 1ll * (Latter - i) * b[i]);
            st.push({i, b[i]});
            int L = b[i] - a[i];
            ans += 1ll * cal(t1, 1, L+n+1) * L - cal(t2, 1, L+n+1);
        }
        cout<<ans<<endl;
        REP(i, 0, n * 2 + 2) t1[i] = t2[i] = 0;
    }
    return 0;
}