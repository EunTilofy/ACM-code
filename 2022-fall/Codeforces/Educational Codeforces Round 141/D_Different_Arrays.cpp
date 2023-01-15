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
int a[MN], f[305][300*300*3];
const int VAL = 300*300+1;
void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    f[2][a[2]+VAL] = 1;
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= VAL + VAL; ++j) if(f[i][j]) {
            if(j - VAL == 0) f[i+1][a[i+1]+VAL] = Add(f[i+1][a[i+1]+VAL], f[i][j]);
            else {
                f[i+1][a[i+1]+j] = Add(f[i+1][a[i+1]+j], f[i][j]);
                f[i+1][a[i+1]-j+VAL+VAL] = Add(f[i+1][a[i+1]-j+VAL+VAL], f[i][j]);
            }
        }
    } 
    int Ans = 0;
    for(int i = 1; i <= VAL + VAL; ++i) Ans = Add(Ans, f[n][i]);
    cout << Ans << endl; 
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;
	while(T--) solve();
}