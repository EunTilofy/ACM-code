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
const int MN = 2e5+10;
long long a[MN];
long long b[MN], c[MN], d[MN], e[MN], pw2[MN];
// std::set<long long> pw2;
// map<long long, int> lg;
void solve(){
	int n, m;
    cin >> n;
    for(int i = 0; i < 35; ++i) b[i] = c[i] = d[i] = e[i] = 0;
    long long sm = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], sm += a[i];
    if(sm % n != 0) {
        cout << "No\n";
        return ;
    }
    sm /= n;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == sm) continue;
        long long x = 0, fl = 0;
        for(x = 0; x < 35; ++x) {
            if(a[i]+pw2[x]-sm==0) continue;
            int y=63-__builtin_clzll((long long)(a[i] + pw2[x] - sm));
            if(pw2[y] != a[i] + pw2[x] - sm) continue;
            b[y] ++;c[x]++;
            fl = 1;
            if(x + 1 == y) {
                e[y] ++;
            }
            if(x - 1 == y) {
                d[x] ++;
            }
            break;
        }
        if(!fl) {
            cout << "No\n";
            return;
        }
    }
    bool fl = 1;
    for(int i = 0; i <= 34; ++i) if(b[i] != c[i]) {
        fl = 0;
    }
    if(fl) cout << "Yes\n";
    else {
        for(int i = 0; i <= 34; ++i) b[i] -= c[i];
        for(int i = 34; i >= 0; --i) {
            if(b[i] > 0) {
                if(i > 0 && b[i] <= e[i]) {
                    b[i - 1] += 2*b[i];
                    b[i] = 0;
                }
            }
            if(b[i] < 0) {
                if(i > 0 && -b[i] <= d[i]) {
                    b[i - 1] += 2*b[i];
                    b[i] = 0;
                }
            }
            if(b[i] != 0) {
                cout << "No\n";
                return ;
            }
        }
        cout << "Yes\n";
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
    pw2[0] = 1;
    for(int i=1; i<=34; ++i) pw2[i] = pw2[i - 1] * 2;
	while(T--) 
		solve();
}