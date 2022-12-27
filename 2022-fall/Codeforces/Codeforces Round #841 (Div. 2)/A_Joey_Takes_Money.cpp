#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

void solve(){
	int n;
    cin >> n;
    vector<int> a(n);
    long long ans = 1;
    for(auto &x : a) {
        cin >> x;
        ans = ans * (long long)x;
    }
    ans += n - 1;
    ans *= 2022;
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}