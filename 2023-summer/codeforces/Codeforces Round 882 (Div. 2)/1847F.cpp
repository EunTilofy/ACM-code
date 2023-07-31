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
int st[MN][19];
int n, q;

int get(int l, int r) {
    int N = 31 - __builtin_clz(r - l + 1);
    return st[l][N] | st[r - (1<<N) + 1][N];
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i], a[i + n] = a[i];

    // pos, num
    vector<pair<long long, int>> num(n+1);

    for(int i = 1; i <= n * 2; ++i) {
        st[i][0] = a[i];
    }
    for(int j = 1; j <= 18; ++j) for(int i = 1; i <= n * 2; ++i) {
        if(i + (1<<j) - 1 > n * 2) break;
        st[i][j] = st[i][j - 1] | st[i + (1<<(j-1))][j - 1];
    }

    for(int i = 1; i <= n; ++i) {
        num.push_back({i, a[i]});
        int now = a[i];
        int j = i;
        while(j < i + n - 1) {
            int l = j + 1, r = i + n - 1, gt = j;
            while(l <= r) {
                int mid = (l + r) >> 1;
                int num = get(j, mid);
                if((num | now) == now) gt = mid, l = mid + 1;
                else r = mid - 1;
            }
            j = gt + 1;
            if(j == n + 1) ++j, now |= a[1];
            if(j <= i + n - 1) {
                now |= a[j];
                num.push_back({1ll * (j - i - (j >= n + 1)) * n + i, now});
            }
        }
    }
    sort(all(num));
    vector<pair<long long, long long>> tr;
    int now = -1;
    for(auto &[pos, num] : num) {
        if(num > now) {
            now = num;
            tr.push_back({num, pos});
        }
    }
    long long MX = 100000000000000LL;
    while(q--) {
        int x;
        cin >> x;
        pair<ll, ll> que = make_pair(x, MX);
        if(upper_bound(tr.begin(), tr.end(), que) == tr.end()) {
            cout << "-1" << endl;
        }
        else {
            cout << upper_bound(tr.begin(), tr.end(), que) -> second << endl;
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