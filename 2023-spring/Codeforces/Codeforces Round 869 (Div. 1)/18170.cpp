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
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN];

void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> tmp;
    for(int i = 1; i <= n; ++i) {
        int j = i;
        while(j+1<=n && a[j+1]<=a[j]) ++j;
        tmp.push_back(i);
        if(j != i)tmp.push_back(j);
        // cerr << i << "? " << j << endl;
        i = j;
    }
    // for(auto x : tmp) cerr << x << " "; cerr << endl;
    for(int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            cout << "1" << endl;
            continue;
        }
        int pos1 = lower_bound(all(tmp), l) - tmp.begin();
        int pos2 = upper_bound(all(tmp), r) - tmp.begin() - 1;
        // cerr << pos1 << " " << pos2 << endl;
        if(pos1 > pos2) {
            cout << "2" << endl;
            continue;
        }
        int cnt = pos2 - pos1 + 1;
        if(tmp[pos1] > l) ++cnt;
        if(tmp[pos2] < r) ++cnt;
        cout << cnt << endl;
    }
    return ;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
}