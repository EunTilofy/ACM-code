#include<bits/stdc++.h>
#include<iostream>
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
int a[26], cnt[26];
string s;
bool cmp(int x,int y) {return cnt[x] < cnt[y];}
void solve(){
	int n; cin >> n; cin >> s;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; ++i) cnt[s[i]-'a'] ++;
    for(int i = 0; i < 26; ++i) a[i] = i;
    sort(a,a+26,cmp);
    // for(int i = 0; i < 26; ++i) cout << a[i] << " "; cout << endl;
    int ans = n, nm = 1;
    for(int i = 1; i<=n; ++i) if(n%i==0&&(n/i)<=26) {
        int cn = i, num = n/i;
        int cc = 0;
        for(int j = 26-num; j < 26; ++j) {
            cc += min(cn,cnt[a[j]]);
            // cout << cc << " " << cn << " < " << cnt[a[j]] << endl;
        }
        cc = n - cc;
        // cout << cn << " " << cc << endl;
        // for(int j = 26-num; j<26; ++j) cc += abs(cn - cnt[a[j]]);
        if(ans > cc) ans = cc, nm = num;
    } 
    cout << ans << endl;
    multiset<int> se;
    for(int i = 26-nm; i < 26; ++i) {
        cnt[a[i]] = min(cnt[a[i]], n/nm);
        for(int j = min(n/nm, cnt[a[i]])+1; j <= n/nm; ++j) se.insert(a[i]);
    }
    for(int i = 0; i < 26-nm; ++i) cnt[a[i]] = 0;
    vector<int> _(26);
    for(int i = 0; i < n; ++i) {
        if(_[s[i]-'a']<cnt[s[i]-'a']) {
            ++_[s[i]-'a'];
            cout << s[i];
        }
        else {
            cout << (char)('a'+*se.begin());
            se.erase(se.begin());
        }
    }
    cout << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}