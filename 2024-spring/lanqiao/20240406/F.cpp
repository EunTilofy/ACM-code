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
#define mod 1000000007
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

struct mat
{
    int siz;
    int a[55][55];
    mat(int _siz) : siz(_siz) {
        memset(a, 0, sizeof a);
    }
    mat operator * (const mat& o) const {
        mat r(siz);
        for(int k = 0; k < siz; ++k)
            for(int i = 0; i < siz; ++i)
                for(int j = 0; j < siz; ++j) 
                {
                    r.a[i][j] = Add(r.a[i][j], Mul(o.a[i][k], a[k][j]));
                }
        return r;
    }
};

mat fpow(mat x, int y)
{
    // cerr << x.a[0][0] << "\n";
    mat r(x.siz);
    for(int i = 0; i < x.siz; ++i) r.a[i][i] = 1;
    for(; y; y >>= 1, x = x * x) if(y & 1) r = x * r;
    return r;
}



void solve()
{
	int a, b, n;
    cin >> a >> b >> n;
    if(a == 1)
    {
        cout << qpow(2, n) << "\n";
        return;
    }
    mat r(a);
    for(int i = 0; i < a; ++i) {
        int j = (i - 1 + a) % a;
        r.a[i][i] = 1;
        r.a[i][j] = 1;
    }


    // for(int i = 0; i < a; ++i, cerr << "\n")
    // for(int j = 0; j < a; cerr << r.a[i][j] << " ",++j);
    // cerr << "\n";

    r = fpow(r, n);

    // for(int i = 0; i < a; ++i, cerr << "\n")
    // for(int j = 0; j < a; cerr << r.a[i][j] << " ",++j);
    // cerr << "\n";

    cout << r.a[b][0] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}