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
	int n, m;
    cin >> n;
    if(n%2==0) {
        cout << n/2 << " " << n/2 << endl;
        return ;
    }
    string s="", t="";
    bool _ = 0;
    while(n){
        int x = n%10;
        n/=10;
        if(x%2==0) s+=(char)(x/2+'0'), t+=(char)(x/2+'0');
        else {
            if(_) s+=(char)(x/2+'0'), t+=(char)(x/2+1+'0');
            else t+=(char)(x/2+'0'), s+=(char)(x/2+1+'0');
            _^=1;
        }
    }
    reverse(all(s));
    reverse(all(t));
    // cout << s << " " << t << endl;
    int S=0,T=0;
    for(auto x : s) {
        S = S*10 + x-'0';
    }
    for(auto x : t) {
        T = T*10 + x - '0';
    }
    cout << S << " " << T <<endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}