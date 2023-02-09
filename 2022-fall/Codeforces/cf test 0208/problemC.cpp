#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int unsigned long long
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
const int MN = 3e5 + 5;
int q, a, b, n;

void solve(){
	cin >> q;
    int opt, a, b, n;
    unsigned long long L = 1, R = -1;
    while(q--) {
        cin >> opt >> a >> b;
        if(opt == 1) {
            // cerr << L << " " << R << endl;
            cin >> n;
            unsigned long long l,r;
            if(n==1) {
                l = 1;
                r = a;
            } else {
                l=1ll*(n-2)*(a-b)+a+1;
                r=1ll*(n-1)*(a-b)+a;
            }
            if(!(l>R||r<L)) L=max(L,l),R=min(R,r),cout<<1<<endl;
            else cout << 0 << endl;
        }
        else {
            // cerr << L << " " << R << endl;
            unsigned long long ln, rn;
            if(L<=a) ln = 1;
            else ln = (L-b-1)/(a-b)+1;
            if(R<=a) rn = 1;
            else rn = (R-b-1)/(a-b)+1;
            if(ln == rn) cout << ln << endl;
            else cout << -1 << endl;
        }
    }
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}