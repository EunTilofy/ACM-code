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
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
int n, m;
bool a[52][52];
int cnt(int x, int y, int xx, int yy){
    int cn = 0;
    for(int i = x; i <= y; ++i) {
        for(int j = xx; j <= yy; ++j) {
            cn += a[i][j];
        }
    }
    // cout << x << y << xx << yy << cn << 's' << endl;
    return cn;
}
void prt(){
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 1) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}
void fill1(){
    for(int i = 1; i <= n; ++i) {
        int l = m + 1, r = -1;
        for(int j = 1; j <= m; ++j) {
            if(a[i][j]) l = min(l, j), r = max(r, j);
        }
        for(int j = l; j <= r; ++j) a[i][j] = 1;
    }
}
void fill2(){
    for(int i = 1; i <= m; ++i) {
        int l = n + 1, r = -1;
        for(int j = 1; j <= n; ++j) {
            if(a[j][i]) l = min(l, j), r = max(r, j);
        }
        for(int j = l; j <= r; ++j) a[j][i] = 1;
    }
}
int getl(int x, int y, int xx, int yy){
    int cn = m+1;
    for(int i = x; i <= y; ++i) {
        for(int j = xx; j <= yy; ++j) {
            if(a[i][j]) cn = min(cn, j);
        }
    }
    return cn;
}
int getr(int x, int y, int xx, int yy){
    int cn = 0;
    for(int i = x; i <= y; ++i) {
        for(int j = xx; j <= yy; ++j) {
            if(a[i][j]) cn = max(cn, j);
        }
    }
    return cn;
}
int getu(int x, int y, int xx, int yy){
    int cn = n+1;
    for(int i = x; i <= y; ++i) {
        for(int j = xx; j <= yy; ++j) {
            if(a[i][j]) cn = min(cn, i);
        }
    }
    return cn;
}
int getd(int x, int y, int xx, int yy){
    int cn = 0;
    for(int i = x; i <= y; ++i) {
        for(int j = xx; j <= yy; ++j) {
            if(a[i][j]) cn = max(cn, i);
        }
    }
    return cn;
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        for(int j = 1; j <= m; ++j) a[i][j] = s[j-1] == '#';
    }
    // prt();
    for(int i=1;i<=n*m;++i) fill1(),fill2();
    int all = cnt(1,n,1,m);
    bool fd = 0;
    for(int i = 1; i <= n; ++i) {
        if(fd) break;
        for(int j = 1; j <= m; ++j) {
            int lu = cnt(1,i-1,1,j-1);
            int ru = cnt(1,i-1,j,m);
            int ld = cnt(i,n,1,j-1);
            int rd = cnt(i,n,j,m);
            // cout << lu << ru << ld << rd << all << endl;
            if(lu&&rd&&lu+rd==all) {
                int r = getr(1,i-1,1,j-1);
                int d = getd(1,i-1,1,j-1);
                int l = getl(i,n,j,m);
                int u = getu(i,n,j,m);
                a[d][r]=a[u][l]=1;
                for(int k = r; k <= l; ++k) a[d][k] = 1;
                for(int k = d; k <= u; ++k) a[k][l] = 1;
                fd=1;break;
            } else if(ru&&ld&&ru+ld==all) {
                // cout << "!" << endl;
                int l = getl(1,i-1,j,m);
                int d = getd(1,i-1,j,m);
                int r = getr(i,n,1,j-1);
                int u = getu(i,n,1,j-1);
                a[d][l]=a[u][r]=1;
                for(int k = l; k <= r; ++k) a[d][k] = 1;
                for(int k = d; k <= u; ++k) a[k][l] = 1;
                fd=1;break;
            }
        }
    }
    for(int i=1;i<=n*m;++i) fill1(),fill2();
    prt();
    
    // cout << "--------------------" << endl;
    // cout << n << m << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}