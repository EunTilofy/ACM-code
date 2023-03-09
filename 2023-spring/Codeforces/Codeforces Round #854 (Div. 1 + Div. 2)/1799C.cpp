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
	string s;
    cin >> s;
    sort(all(s));
    int n = s.size();
    string pre="", suf="";
    char mx = s[n-1];
    for(int i = 0; i < n; i+=2) {
        if(i + 1 < n) {
            char a = s[i], b = s[i+1];
            if(a == b) pre += a, suf += b;
            else {
                if(i + 2 < n && s[i + 2] == b && s[i + 2] == mx) {
                    pre += b;
                    suf += b;
                    i = i + 3;
                    while(i + 1 < n) {
                        if(s[i] == s[i + 1] && s[i] == b) {
                            pre += s[i];
                            suf += s[i + 1];
                            i += 2;
                        } else break;
                    }
                    suf += a;
                    for(int j = i; j < n; ++j) pre += s[j];
                    break;
                }
                else {
                    pre += b; suf += a;
                    for(int j = i + 2; j < n; ++j) pre += s[j];
                    break;
                }
                break;
            }
        }
        else pre += s[i];
    }
    reverse(all(suf)); pre += suf;
    cout << pre << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}