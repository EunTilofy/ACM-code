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
const int MN = 4e5 + 5;
int a[MN];
#define int long long

void solve(){
	int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int,int>> b;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        b.push_back({(a[i]%y+y)%y, i});
        a[i] = (a[i]%x+x)%x;
    }
    sort(b.begin(), b.end());
    long long ans =0;
    for(int i = 0; i < n; ++i) {
        int j = i;
        while(j+1<n&&b[j+1].first == b[i].first) ++j;
        map<int, int> c;
        for(int k=i;k<=j;++k) {
            if(c.count(a[b[k].second])) c[a[b[k].second]]++;
            else c[a[b[k].second]] = 1;
            if(!c.count(x - a[b[k].second])) c[x - a[b[k].second]] = 0;
        }
        // dbg1(i); dbg2(j); dbg2(b[i].first);
        for(auto [v, num] : c) if(num) {
            // dbg1(v); dbg2(num);
            if(v+v<x) {
                if(v == 0) {
                    ans += 1ll * num * (num - 1) /2;
                } else ans += 1ll * num * c[x-v];
            } else if(v+v==x) {
                ans += 1ll * num * (num - 1) / 2;
            }
            else break;
        }
        i = j;
        // dbg3(----s-----);
    }
    cout << ans << "\n";
    // dbg3(--------------------);
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}