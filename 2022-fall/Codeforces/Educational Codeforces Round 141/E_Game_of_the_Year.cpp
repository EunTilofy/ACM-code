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
const int MN = 2e5 + 5;
int a[MN], b[MN], c[MN],cnt,req;
bool ok[MN];

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    cnt = 0, req = 0;
    for(int i = 0; i <= n+1; ++i) c[i] = ok[i] = 0;
    for(int i = 1; i <= n; ++i) if(a[i] > b[i]) {
        ++req;
        ++c[a[i]]; --c[n+1];
        int val = a[i] - b[i];
        for(int j = val; j < a[i]; ++j) {
            int l = j;
            int r = (a[i]-1)/((a[i]-1)/l);
            int sh = (a[i]-1)/l;
            int R = (a[i]-1-val)/sh;
            if(R >= l) {
                ++c[l], --c[R+1];
            }
            j=r;
        }
    }
    for(int i = 1; i <= n; ++i) {
        c[i] += c[i-1];
        if(c[i] == req) ok[i] = 1, ++cnt;
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; ++i) if(ok[i]) cout << i << " ";
    cout << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}