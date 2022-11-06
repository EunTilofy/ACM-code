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
int que(int l, int r) {
    if(c[l]>r) return 0;
    return 1;
}
std::set<int> S[MN][2];
std::map<int, int> mp; int ind = 0;
bool chk(int l, int r, int val) {
    if((*S[mp[val]][l&1].lower_bound(l)) <= r) return 1;
        else return 0;
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T--) {
        cin>>n>>m;
        REP(i, 1, n + 1) cin>>a[i];
        REP(i, 1, n + 1) {
            b[i] = b[i - 1] ^ a[i];
            if(!mp[b[i]]) {
                mp[b[i]] = ++ind;
                S[ind][0].insert(n + 1);
                S[ind][1].insert(n + 1);
            }
            S[mp[b[i]]][i&1].insert(i);
        }
        c[n + 1] = n + 1;
        DREP(i, n, 0) {
            if(a[i]) c[i]=i;
            else c[i]=c[i+1];
        } 
        while(m--) {
            int l, r;
            cin>>l>>r;
            // dbg1(b[r]), dbg2(b[l-1]);
            if(b[r]!=b[l-1]) {cout<<"-1"<<endl; continue;}
            // dbg2(c[l]);
            if(c[l]>r) {cout<<"0"<<endl;continue;}
            if((r-l+1)&1) {
                cout<<"1"<<endl;
            }
            else {
                if(b[l] == b[l-1]) cout<<que(l+1, r)<<endl;
                else if(b[r]==b[r-1]) cout<<que(l,r-1)<<endl;
                else if(chk(l,r-1,b[l-1])) cout<<"2"<<endl;
                else cout<<"-1"<<endl;
            }
        }
    }
    return 0;
}