#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define mod 998244353
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 100 + 5;
int a[MN], b[MN], c[MN], dep[MN];
vector<int> G[MN];

int MX=2;
int dfs(int x, int f, int lastdep) {
    if(MX==3) return -1;
    c[x]=-1;
    if(x != 1 && b[x]==1) {
        if(lastdep != -1 && (lastdep+dep[x])%2 !=0) {
            MX=3;
            return -1;
        } 
        lastdep=dep[x];
        c[x]=1;
    }
    int mi=100001, MI=100001;
    for(auto y : G[x]) {
        mi=dfs(y, x, lastdep);
        MI=min(mi, MI);
        // if(x==2&&y==7)cerr<<mi<<"`````\n";
        // if(x==7&&y==17)cerr<<mi<<"!!!!\n";
        if(x != 1) {
            // if(x == 2) cerr<<mi<<" "<<c[x]<<"\n";
            // if(x==7) cerr<<mi<<" xx "<<c[x]<<"\n";
            if(mi!=100001&&c[x]!=-1&&(mi+c[x]+dep[x])%2!=1) MX=3;
            if(MX==3) return -1;
            if(mi!=100001&&c[x]==-1) {
                if((mi-dep[x])%2==0) c[x]=1;
                else c[x]=2;
            }
            // if(x == 2) cerr<<mi<<" " << c[x]<<"\n";
            // if(x==7) cerr<<mi<<" xx "<<c[x]<<"\n";
        }
    }
    if(MX==3) return -1;
    if(a[x]==1&&c[x]==-1) c[x]=1;
    if(b[x]==1) return dep[x];
    else return MI;
}

void solve(){
	int n, m;
    cin >> n;
    b[1]=dep[1]=0;
    int mx=0;
    for(int i=2;i<=n;++i) {
        cin>>a[i];
        G[a[i]].push_back(i);
        ++b[a[i]];
        dep[i]=dep[a[i]]+1;
    }
    dfs(1, 0, -1);
    for(int i=2;i<=n;++i) {
        if(a[i]==1) {
            if(MX==3) c[i]=1;
        }
        else {
            c[i]=c[a[i]]%MX+1;
            // if(b[i]==1&&i!=1&&c[i]==2) cerr << i << " " << c[i] << " " << a[i] << "\n";
        }
        mx=max(mx, c[i]);
    }
    cout<<mx<<endl;
    for(int i=2;i<=n;++i) cout<<c[i]<<" ";cout<<endl;
    while(1) {
        int opt;
        cin>>opt;
        if(opt==1) return;
        if(opt==0) {
            if(mx==3) {
                int a, b, c;
                cin >> a >> b >> c;
                if(a==0&&b==0) cout<<3<<endl;
                else if(a==0&&c==0) cout<<2<<endl;
                else if(b==0&&c==0) cout<<1<<endl;
                else if(a==0) cout<<2<<endl;
                else if(b==0) cout<<3<<endl;
                else if(c==0) cout<<1<<endl;
            }
            if(mx<=2) {
                int a, b;
                cin >> a;
                if(mx==2) cin>>b;
                else b=0;
                if(a==1) cout<<1<<endl;
                else cout<<2<<endl;
            }
        }
        else return;
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;
	while(T--) 
		solve();
}