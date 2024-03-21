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
int a[MN][26], b[MN];
char c[MN];

void solve(){
	int n, m, k;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    for(int i = 0; i < k; ++i) a[m][i] = m;
    int beg = 0, begc = 'a';
    for(int i = m - 1; i >= -1; --i) {
        int nxt = -1; char ch = 'a';
        for(int j = 0; j < k; ++j) {
            nxt = max(nxt, a[i+1][j]);
            if(nxt == a[i+1][j]) ch = 'a' + j;
        }
        if (i == -1) {
            beg = nxt; begc = ch;
            break;
        }
        for(int j = 0; j < k; ++j) a[i][j] = a[i+1][j];
        a[i][s[i] - 'a'] = i;
        b[i] = nxt; c[i] = ch;
    }
    string t = ""; t += begc;
    for(int i = beg; i < m; ) {
        if(t.size() == n) {
            cout << "YES\n";
            return ;
        }
        t = t + c[i]; i = b[i];
        if(i > m - 1) break;
    }
    cout << "NO\n";
    while(t.size() < n) t = t + 'a';
    cout << t << "\n"; 
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}