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
long long a[MN], b[MN], c[MN];
std::set<long long> pw2;
map<long long, int> lg;
void solve(){
	int n, m;
    cin >> n;
    for(int i = 0; i < 35; ++i) b[i] = c[i] = 0;
    long long sm = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], sm += a[i];
    if(sm % n != 0) {
        cout << "No\n";
        return ;
    }
    sm /= n;
    for(int i = 1; i <= n; ++i) {
        long long x = 0, fl = 0;
        for(x = 0; x < 35; ++x) {
            // cout << a[i] + (1ll << x) - sm << "\n";
            if(pw2.count(a[i] + (1ll << x) - sm)) {
                b[x]++;
                c[lg[a[i] + (1ll << x) - sm]] ++;
                fl = 1;
                break;
            }
        }
        if(!fl) {
            cout << "No\n";
            // cout << a[i] << "~~~\n";
            return;
        }
    }
    for(int i = 0; i <= 34; ++i) if(b[i] != c[i]) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
    for(int i=0; i<=34; ++i) pw2.insert((1ll<<i)), lg[1ll<<i]=i;
	while(T--) 
		solve();
}