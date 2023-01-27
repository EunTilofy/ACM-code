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
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN];

void solve(){
	long long val;
    cin >> val;
    long long val1 = 0, val2 = 0;
    bool las = 1;
    for(int i = 0; i < 30; ++i) {
        if(val>>i&1) {
            if(las) {
                cout << "-1" << endl;
                return;
            }
            val1+=1<<(i-1);
            val2+=1<<(i-1);
            val2+=1<<i;
        }
        las = (val>>i&1);
    }
    // assert(val1 + val2 == val * 2ll);
    // assert(val1^val2==val);
    cout << val1 << " " << val2 << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}