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
const int MN = 3e5 + 5;

void solve(){
	int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    bool fl = 1;
    for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) {
        if(a[i] == a[j]) fl = 0;
    }
    if(fl == 1) {
        for(int i = 2; i <= 100; ++i) {
            vector<int> tmp(i);
            for(int j = 1; j <= n; ++j) tmp[a[j] % i]++;
            bool fin = 0;
            for(int j = 0; j < i; ++j) if(tmp[j] < 2) fin = 1;
            if(!fin) {
                fl = 0;
                break;
            }
        }
    }
    if(fl) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
 	int T;
	cin>>T;
	while(T--) solve();
}