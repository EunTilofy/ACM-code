#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

int a[100005];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) a[i] = n + 1;
	for(int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		if(x > y) swap(x, y);
		a[x] = min(a[x], y);
	}
	long long ans = 0;
	int now = n + 1;
	for(int i = n ; i ; --i) {
		now = min(now, a[i]);
		ans = ans + (now - i);
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}