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
    string s;
    cin >> s;
    if(s.substr(0, 2) == "00") {
        s[0] = '1'; s[1] = '2';
        cout << s << " AM\n";
        return;
    }
    if(s.substr(0, 2) == "12") {
        cout << s << " PM\n";
        return ;
    }
    if(stoi(s.substr(0, 2)) < 12) {
        cout << s << " " << "AM\n";
    }
    else {
        int x = stoi(s.substr(0, 2));
        x -= 12;
        if(x < 10) cout << "0";
        cout << x;
        for(int i = 2; i < s.size(); ++i) cout << s[i];
        cout << " PM\n";
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}