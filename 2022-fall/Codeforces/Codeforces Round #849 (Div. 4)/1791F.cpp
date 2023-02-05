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
int a[MN], b[MN], c[MN];

void solve(){
	int n, m;
    cin >> n >> m;
    set<int> S;
    set<int>::iterator it;
    for(int i = 1; i <= n; ++i) S.insert(i);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    while(m--) {
        int opt;
        cin >> opt;
        if(opt == 1) {
            int l, r;
            cin >> l >> r;
            it = S.lower_bound(l);
            set<int> upd;
            while(1) {
                if(it == S.end()) break;
                int num = *it;
                // cout << num << endl;
                if(num > r) break;
                int _ = 0;
                while(a[num]) {
                    _+=a[num]%10;
                    a[num]/=10;
                }
                a[num]=_;
                if(a[num]<10) upd.insert(num);
                it++;
            }
            for(auto x : upd) S.erase(x);
        } else {
            int x;
            cin >> x;
            cout << a[x] << endl;
        }
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}