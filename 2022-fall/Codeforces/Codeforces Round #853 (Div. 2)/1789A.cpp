#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

void solve(){
    int n;
	cin>>n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int fl = 0;
    for(int i = 0; i < n; ++i) for(int j = 1; j < n; ++j) {
        if(gcd(a[i], a[j]) <= 2) fl = 1;
    }
    cout << (fl?"Yes":"No") << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}