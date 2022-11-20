//直接找一条从左到右路径是不对的
//路径可以是往回走的那种，所以要写成最短路
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
const int MN = 4e5 + 5;
int n, m;
string s[MN];
signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; cin>>T;
    while(T--) {
        cin>>n>>m;
        REP(i, 0, n) cin>>s[i];
        std::vector<std::vector<bool>> a(n);
        REP(i, 0, n) {
            REP(j, 0, m) a[i].pb(s[i][j]=='#');
        }
        std::vector<std::vector<unsigned int>> f(n);
        unsigned int INF = -1;
        REP(j, 0, m) {
            REP(i, 0, n) {
                f[i].pb(INF);
                if(a[i][j]) {
                    if(j==0) {
                        f[i][j]=0;
                    }
                    if(i>0&&j>0&&f[i-1][j-1]!=INF) f[i][j]=min(f[i][j], f[i-1][j-1]);
                    if(i+1<n&&j>0&&f[i+1][j-1]!=INF) f[i][j]=min(f[i][j],f[i+1][j-1]);
                }
                else {
                    if(i&&a[i-1][j]) continue;
                    if(i+1<n&&a[i+1][j]) continue;
                    if(j+1<m&&a[i][j+1]) continue;
                    if(j&&a[i][j-1]) continue; 
                    if(j==0) {
                        f[i][j]=1;
                    }
                    if(i>0&&j>0&&f[i-1][j-1]!=INF) {
                        f[i][j]=min(f[i][j], f[i-1][j-1]+1);
                    }
                    if(i+1<n&&j>0&&f[i+1][j-1]!=INF) {
                        f[i][j]=min(f[i][j],f[i+1][j-1]+1);
                    }
                }
            }
        }
        int ID=-1;
        REP(i, 0, n) {
            if(f[i][m-1] != INF) {
                if(ID==-1) ID=i;
                else if(f[i][m-1]<f[ID][m-1]) ID=i;
            }
        }
        if(ID==-1) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            DREP(j, m-1, -1) {
                // dbg1(ID);
                int _=-1; 
                if(j>0) {
                    if(ID>0&&f[ID-1][j-1]+(!a[ID][j])==f[ID][j]) _=ID-1;
                    if(ID+1<n&&f[ID+1][j-1]+(!a[ID][j])==f[ID][j]) _=ID+1;
                }
                a[ID][j]=1;
                ID=_;
                assert(ID!=-1||j==0);
            }
            REP(i,0,n){
                REP(j,0,m) cout<<(a[i][j]?"#":".");
                cout<<endl;
            }
        }
    }
    return 0;
}