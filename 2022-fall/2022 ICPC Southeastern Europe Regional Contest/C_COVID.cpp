#include "bits/stdc++.h"
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
const int MN = 1024;

bitset<1024> b[1<<15];
int cn[1<<15], id[MN];

struct bgnum {
    int a[1024];
    int id;
    void init(int n) {
        memset(a, 0, sizeof a);
        a[n] = 1;
    }
    void mk() {
        for(int i = 0; i < 1023; ++i) {
            if(a[i] < 0) {
                int br = (-a[i] + 1)/2;
                a[i + 1] -= br;
                a[i] += br * 2;
            } else {
                a[i + 1] += a[i] / 2;
                a[i] %= 2;
            }
        }
    }
    bool cmp(bgnum &o) {
        for(int i = 1023; ~i; --i) {
            if(a[i] > o.a[i]) return 1;
            else if(a[i] < o.a[i]) return 0;
        }
        return id > o.id;
    }
}_[MN];

bool mcmp(int x, int y) {
    return _[y].cmp(_[x]);
}

void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x = (1 << i);
        int y; cin >> y;
        while(y--) {
            int dig; cin >> dig;
            b[x][dig] = 1;
        }
    }
    for(int i = 1; i < (1<<m); ++i) cn[i] = cn[i-(i&-i)] + 1;
    for(int i = 1; i < (1<<m); ++i) if(cn[i] > 1) b[i] = b[i-(i&-i)] | b[i&-i];


    // for(int i = 0; i < (1<<m); ++i) cout << b[i].count() << " "; cout << "\n";

    for(int i = 1; i <= n; ++i) {
        id[i] = i; _[i].id = i; _[i].init(n-1);
        vector<bool> csd(m); int nS = 0;
        for(int j = 0; j < m; ++j) csd[i] = !b[1<<j][i], nS |= (b[1<<j][i]) << j;

        // cout << i << " " << nS << endl;

        for(int s = 1; s < (1<<m); ++s) if((s & nS) == 0){
            int siz = n - 1 - b[s].count();
            _[i].a[siz] += (cn[s]&1) ? (-1) : 1;
            // cout << i << " " << siz << " " << ((cn[s]&1) ? (-1) : 1) << endl;
        }
    }
    for(int i = 1; i <= n; ++i) _[i].mk();
    sort(id + 1, id + n + 1, mcmp);
    for(int i = 1; i <= n; ++i) cout << id[i] << " ";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
}