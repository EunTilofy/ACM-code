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
    string s, t;
    cin >> s >> t;
    vector<int> nm1(26), nm2(26);
    for(int i = 0; i < n; ++i) {
        if(i - m < 0 && i + m >= n) {
            if(s[i]!=t[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            ++nm1[s[i]-'a'];
            ++nm2[t[i]-'a'];
        }
    }
    for(int i = 0; i < 26; ++i) {
        if(nm1[i]!=nm2[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}