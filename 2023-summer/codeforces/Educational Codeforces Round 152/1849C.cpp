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
    cin >> n >> m;
    string s;
    cin >> s;
    // int ans = m;
    set<pair<int,int>> S;
    // vector<set<int>> _1(n+1), _0(n+1);
    // set<pair<int,int>> dd;
    // set<int> du;
    // for(int i = 1; i <= n; ++i) {
    //     int j = i;
    //     while(s[j] == s[i-1] && j < n) ++j;
    //     dd.insert({i, s[i-1] == '1'});
    //     i = j;
    // }
    for(int i = n; i; --i) {
        if(i == n) c[i] = n + 1;
        else if(s[i] != s[i-1]) c[i] = i + 1;
        else c[i] = c[i + 1];
    }
    for(int i = 2; i <= n; ++i) {
        if(s[i-1] != s[i - 2]) b[i] = i - 1;
        else b[i] = b[i - 1];
    }
    for(int i = 1; i <= m; ++i) {
        int L, R;
        cin >> L >> R;
        bool _l = s[L - 1] == '1';
        bool _r = s[R - 1] == '1';
    
        if(_l == 0) {
            // cerr << L << " !" << endl;
            L = c[L];
            _l = 1;
        }
        if(_r == 1) {
            R = b[R];
            _r = 0;
        }
        // cerr << L << " " << R << "\n";
        if(L > R) {
            S.insert({-1,-1});
        }
        else {
            S.insert({L, R});
        }
    }
    cout << S.size() << "\n";
    // for(int i = 1; i <= m; ++i) {
    //     int l, r;
    //     cin >> l >> r;
    //     if(S.count({l, r})) --ans;
    //     else {
    //         S.insert({l, r});
    //         auto [L, _l] = *dd.lower_bound({l, -2});
    //         auto [R, _r] = *dd.lower_bound({r, -2});
    //         if(L == R) {
    //             if(du.count(L)) --ans;
    //             else {
    //                 du.insert(L);
    //             }
    //         } 
    //         else {
    //             if(_l == 0 && _r == 1) {
    //                 if(_01.count({L, R})) --ans;
    //                 else _01.insert({L, R});
    //             } else if(_l == 0 && _r == 0){
    //                 if(_0[r].count(L)) --ans;
    //                 else _0[r].insert(L);
    //             } else if(_l == 1 && _r == 1) {
    //                 if(_1[l].count(R)) --ans;
    //                 else _1[l].insert(R);
    //             }
    //         }
    //     }
    // }
    // cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}