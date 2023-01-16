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
int mod;
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return ((x + y) % mod + mod)%mod;}
inline int Mul(int x, int y){return (1ll * x * y % mod + mod) % mod;}
const int MN = 3e6 + 5;
int a[MN], b[MN], c[MN];
int n;
int C(int x, int y) {
    return Mul(a[x], Mul(b[y], b[x-y]));
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> mod;
    int ans = 0;
    a[0] = 1;
    for(int i = 1; i <= n*3; ++i) a[i] = Mul(a[i-1], i);
    int ans1 = ans, ans2 = 0, ans3 = a[3*n];
    ans1 =  Add(Mul(Add(a[n*2], mod-1), 2), Add(1, mod - a[n]));
    b[0] = b[1] = 1;
    for(int i = 2; i <= n*3; ++i) b[i] = Mul(b[mod%i],mod-mod/i);
    for(int i = 2; i <= n*3; ++i) b[i] = Mul(b[i-1],b[i]);
    ans2 = Mul(a[n],Mul(a[2*n],C(2*n,n)));
    ans2 = Mul(ans2, 2);
    for(int i = 0; i <= n; ++i) ans2 = Add(ans2, mod-Mul(Mul(Mul(a[n],a[i]),a[2*n-i]),Mul(C(n,i),Mul(C(n,i),C(n,i)))));
    //   for(int i = 1; i <= n; ++i) ans2 = Add(ans2, Mul(Mul(C(n,i),C(n,i)),Mul(a[i],Mul(C(),Mul(a[2*n-i],a[n])))));
    // cout << ans1 << " " << ans2 << " " << ans3 <<endl;
    ans = Add(ans1, Add(Mul(2, Add(ans2, mod-ans1-1)), Mul(3, Add(ans3, mod-ans2))));
    // cout << ans1 << ans2 << ans3 << endl;
    cout << ans << endl;
    return 0;
}