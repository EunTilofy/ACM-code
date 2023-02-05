#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define int long long
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
int a[MN], b[MN], c[MN];

void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = min(min(m, a[i]), a[i]-min(m, a[i]));
        c[i] = a[i] - b[i];
        assert(a[i]==b[i]+c[i]);
        assert((b[i]-m)*(c[i]-m)>=0);
    }
    long long ans[2] = {0, 0};
    ans[0] = a[1] * b[2];
    ans[1] = a[1] * c[2];
    for(int i = 3; i < n; ++i) {
        long long _0, _1;
        _0 = min(ans[1] + b[i-1]*b[i], ans[0] + c[i-1]*b[i]);
        _1 = min(ans[1] + b[i-1]*c[i], ans[0] + c[i-1]*c[i]);
        ans[0] = _0;
        ans[1] = _1;
    }
    ans[0] += a[n] * c[n-1];
    ans[1] += a[n] * b[n-1];
    cout << min(ans[0], ans[1]) << endl;
    // long long ans1 = 0ll, ans2 = 0ll, ans3 = 0ll, ans4 = 0ll;
    // ans1 += 1ll * a[1] * b[2] + 1ll * a[n] * c[n-1];
    // ans2 += 1ll * a[1] * c[2] + 1ll * a[n] * b[n-1];
    // for(int i = 2; i < n-1; ++i) {
    //     ans1 += 1ll * c[i] * b[i + 1];
    //     ans2 += 1ll * b[i] * c[i + 1];
    // }
    // ans3 += 1ll * a[1] * b[2] + 1ll * a[n] * b[n-1];
    // ans4 += 1ll * a[1] * c[2] + 1ll * a[n] * c[n-1];
    // for(int i = 2, j = n-1; i < j; ++i, --j) {
    //     if(i + 2 == j) {
    //         int x = c[i], y = c[j];
    //         ans3 += 1ll * b[i+1] * max(x, y) + 1ll * c[i+1] * min(x, y);
    //         x = b[i]; y = b[j];
    //         ans4 += 1ll * b[i+1] * max(x, y) + 1ll * c[i+1] * min(x, y);
    //         break;
    //     }
    //     else if(i + 3 == j) {
    //         long long x = c[i], y = c[j];
    //         ans3 += min(
    //             min(1ll*x*b[i+1]+1ll*c[i+1]*c[i+2]+1ll*b[i+2]*y, 1ll*x*c[i+1]+1ll*b[i+1]*c[i+2]+1ll*b[i+2]*y),
    //             min(1ll*x*b[i+1]+1ll*c[i+1]*b[i+2]+1ll*c[i+2]*y, 1ll*x*c[i+1]+1ll*b[i+1]*b[i+2]+1ll*c[i+2]*y)
    //         );
    //         x = b[i], y = b[j];
    //         ans4 += min(
    //             min(1ll*x*b[i+1]+1ll*c[i+1]*c[i+2]+1ll*b[i+2]*y, 1ll*x*c[i+1]+1ll*b[i+1]*c[i+2]+1ll*b[i+2]*y),
    //             min(1ll*x*b[i+1]+1ll*c[i+1]*b[i+2]+1ll*c[i+2]*y, 1ll*x*c[i+1]+1ll*b[i+1]*b[i+2]+1ll*c[i+2]*y)
    //         );
    //         swap(i, j);
    //         break;
    //     } else {
    //         ans3 += 1ll * c[i] * b[i + 1] + 1ll * c[j] * b[j - 1];
    //         ans4 += 1ll * b[i] * c[i + 1] + 1ll * b[j] * c[j - 1];
    //     }
    //     // if(i+1==j-1) break;
    // }
    // if(n == 3) cout << min(ans1, ans2) << endl;
    // else cout << min(min(ans1, ans2), min(ans3, ans4)) << endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}