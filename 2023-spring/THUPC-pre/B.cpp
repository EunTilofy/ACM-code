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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(m + m <= n) cout << "Poor E.S.!";
    else {
        int lm = max(0, n-m);
        cout << 1 + lm << endl;
    }
    return 0;
}