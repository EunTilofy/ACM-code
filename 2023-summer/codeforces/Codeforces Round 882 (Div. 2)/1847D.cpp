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
const int MN = 3e5 + 5;
bool in[MN], a[MN];
int pos[MN], t[MN];
int n, m, q;
void C(int x, int ad) {
    for(;x <= n; x += (x&(-x))) t[x] += ad; 
}
int Q(int x) {
    int sm = 0;
    for(;x; x -= (x&(-x))) sm += t[x];
    return sm;
}

void solve(){
    cin >> n >> m >> q;

    string s;
    cin >> s;
    for(int i = 1; i <= n; ++i) a[i] = (s[i - 1] == '1');
    
    vector<int> im;
    set<int> S;
    for(int i = 1; i <= n; ++i) S.insert(i), pos[i] = 0, in[i] = 0;
    
    for(int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        while(S.lower_bound(l) != S.end()) {
            int _;
            if((_ = *(S.lower_bound(l))) > r) break;
            im.push_back(_);
            S.erase(_);
        }
    }
    for(int i = 1; i <= n; ++i) in[i] = S.count(i);

    for(int i = 0; i < im.size(); ++i) pos[im[i]] = i + 1;
    int sum = 0;

    for(int i = 1; i <= n; ++i) sum += (in[i] & a[i]), t[i] = 0;

    for(int i = 1; i <= n; ++i) if(!in[i]) C(pos[i], a[i]);

    // cout << sum << endl;
    // return;

    while(q--) {
        int x;
        cin >> x;
        if(in[x]) {
            if(a[x] == 1) --sum;
            else ++sum;
        } else {
            if(a[x] == 0) C(pos[x], 1);
            else C(pos[x], -1);
        }
        // cerr << sum << endl;
        a[x] ^= 1;

        int ans = 0;
        int l = 0, r = im.size(), fd = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(mid - Q(mid) <= sum) fd = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans += fd - Q(fd);
        l = fd + 1;
        r = im.size();
        if(l <= r) {
            int num = Q(r) - Q(l - 1);
            // cerr << num << endl;
            ans += num - Q(l + num - 1) + Q(l - 1);
        }
        cout << ans << endl;
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T = 1;
	// cin>>T;
	while(T--) 
		solve();
}