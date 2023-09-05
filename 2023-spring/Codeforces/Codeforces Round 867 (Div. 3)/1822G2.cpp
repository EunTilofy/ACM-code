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
int a[MN], b[MN];
int pos[10000005];

int get_pos(int val, int r) {
    if(val <= 10000000) return pos[val];
    int pos = lower_bound(a + 1, a + r + 1, val) - a;
    if(a[pos] == val) return pos;
    return 0;
}

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1,a+n+1);
    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        int j = i;
        while(j + 1 <= n && a[i] == a[j + 1]) ++j;
        b[i] = j - i + 1;
        if(b[i] >= 3) {
            ans += (1ll * b[i] * (b[i] - 1) * 1ll * (b[i] - 2));
        }
        for(int x = 1; 1ll * x * x * x <= a[i]; ++x) {
            int pos1 = 0, pos2 = 0;
            int sqr = (int)sqrt(a[i] / x + 0.5);
            if(a[i] % x == 0 && 1ll * x * sqr != a[i] && 1ll * x * sqr * sqr == a[i]) {
                pos1 = get_pos(x, i);
                pos2 = get_pos(x * sqr, i);
                ans += 1ll * b[i] * b[pos1] * b[pos2];
            }
            if(a[i] % (1ll * x * x) == 0 && x != 1) {
                pos1 = get_pos(a[i] / x, i);
                pos2 = get_pos(a[i] / x / x, i);
                if(x != a[i] / x / x) ans += 1ll * b[i] * b[pos1] * b[pos2];
            }
        }
        if(a[i] <= 10000000) {
            pos[a[i]] = i;
        }
        i = j;
    }
    cout << ans << endl;
    for(int i = 1; i <= n; ++i) {
        int j = i;
        while(j + 1 <= n && a[i] == a[j + 1]) ++j;
        if(a[i] <= 10000000) {
            pos[a[i]] = 0;
        }
        i = j;
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}