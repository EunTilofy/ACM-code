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
int a[MN], b[MN], c[MN];

void solve(){
	int n, m;
    cin >> n;
    string s;
    cin >> s;
    m = s.size();
    int _ = 0, __ = 0;
    for(int i = 0; i < m-1-i; ++i) {
        _ += s[i] != s[m-1-i];
        __ += s[i] == s[m-1-i];
    }
    for(int i = 0; i <= m; ++i) {
        if(i < _) cout << "0";
        else {
            if((i - _) % 2 == 1 && m%2 == 0) {
                cout << "0";
            } else if((i-_)/2>__) {
                cout << "0";
            } else {
                cout << "1";
            }
        }
    }
    cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}