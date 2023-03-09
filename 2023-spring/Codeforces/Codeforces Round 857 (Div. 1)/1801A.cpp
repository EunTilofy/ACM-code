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
#define int unsigned long long
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
unsigned long long a[2][MN], b[2][MN], c[1000][1000];
void print(int n, int m) {
    for(int i = 1; i <= n; ++i, cout << endl) for(int j = 1; j <= m; ++j) {
        cout << c[i][j] << " ";
    }
}
unsigned long long get(int x, int y){
    return c[x][y]^c[x+1][y]^c[x][y+1]^c[x+1][y+1];
}
std::set<unsigned long long> s;
unsigned long long sd=time(0);
unsigned long long _rand() {
    while(1) {
        sd^=sd<<17ll,sd^=sd>>5ll,sd^=sd<<23ll;
        if(!s.count(sd&((1ull<<63)-1))) return sd&((1ull<<63)-1);
    }
}
void solve(){
	int n, m;
    cin >> n >> m;
    cout << n * m << endl;
    // int X = 44444, cnt = 0;
    // for(int i = 1; i <= n; i += 2) {
    //     for(int j = 1; j <= m; j += 2) {
    //         c[i][j] = cnt * X + (j)/2*4;
    //         c[i+1][j] = cnt*X + 1 + (j)/2*4;
    //         c[i][j+1] = cnt*X + 3 + (j)/2*4;
    //         c[i+1][j+1] = cnt*X + 2 + (j)/2*4;
    //     }
    //     cnt ++;
    // }
    // long long N = (1ll<<62ll)-1ll;
    // int cnt = 0;
    // c[1][1] = 0;
    // c[1][2] = 1;
    // c[2][1] = 2;
    // c[2][2] = (N-12)^3;
    for(int i = 1; i <= m; i += 2) {
        c[1][i] = _rand();
        c[1][i+1] = _rand();
    }
    for(int j = 1; j <= n; j+=2) {
        c[j][1] = _rand();
        c[j+1][1] = _rand();
    }
    for(int i = 2; i <= n; ++i) for(int j = 2; j <= m; ++j) {
        c[i][j] = c[i-1][j] ^ c[i-1][j-1] ^ c[i][j-1];
    }
    print(n,m);
    bool chk = 1;
    for(int i = 1; i+3 <= n; ++i)for(int j=1;j+3<=m;++j){

        chk&=get(i,j)==get(i+2,j+2);
        if(chk == 0) {
            cerr << i << "s " << j << " " << get(i, j) << " "<< get(i+2,j+2) << endl;
            cerr << c[i][j] << " " << c[i+2][j+2] << endl;
            return;
        }
        chk&=get(i,j+2)==get(i+2,j);
        if(chk == 0) {
            cerr << i << "r " << j << " " << get(i, j+2) << " "<< get(i+2,j) << endl;
            return;
        }
        
    }
    set<long long> s;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        assert(s.count(c[i][j])==0);
        s.insert(c[i][j]);
    }
    assert(chk);
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}