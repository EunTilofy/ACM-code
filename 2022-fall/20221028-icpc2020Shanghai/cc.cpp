#include<bits/stdc++.h>
#define ll long long
using namespace std;
int X, Y;
const int mod = 1e9 + 7;
ll add(ll x, ll y) {return (x + y) % mod;}
ll mul(ll x, ll y) {return x * y % mod;}
void Add(ll &x, ll y) {x = add(x, y);}
void Mul(ll &x, ll y) {x = mul(x, y);}
long long f[35];
long long dfs(int now, int lim1, int lim2) {
	if(now == -1) {
		return 1;
	}
	ll tmp = 0;
	if(!lim1 && !lim2) return f[now + 1];
	if(lim1) {
		if((X >> now) & 1) Add(tmp, dfs(now - 1, 1, 0));
		Add(tmp, mul(2, dfs(now - 1, ((X >> now) & 1) == 0, 0)));
	}
	else if(lim2) {
		if((Y >> now) & 1) Add(tmp, dfs(now - 1, 0, 1));		
		Add(tmp, mul(2, dfs(now - 1, 0, ((Y >> now) & 1) == 0)));
	}
	else {
		if((X >> now) & 1) Add(tmp, dfs(now - 1, 1, ((Y >> now) & 1) == 0));
		if((Y >> now) & 1) Add(tmp, dfs(now - 1, ((X >> now) & 1) == 0, 1));
		Add(tmp, dfs(now - 1, ((X >> now) & 1) == 0, ((Y >> now) & 1) == 0));
	}
	return tmp;
}
int main() {
	int T;
	cin>>T;
	f[0] = 1;
	for(int i = 1; i <= 32; ++i) {
		f[i] = mul(f[i - 1], 3);
	}
	while(T--) {
		cin>>X>>Y;
		ll ans = 0;
		for(int i = 0; i <= 31; ++i) {
			ll pos1 = (X >= (1ll << i)) ? dfs(i - 1, X < (1ll << (i + 1)), Y < (1ll << i)) : 0ll;
			ll pos2 = (Y >= (1ll << i)) ? dfs(i - 1, X < (1ll << i), Y < (1ll << (i + 1))) : 0ll;
			cout << i << " " << pos1 << " " << pos2 << "\n";
			Add(ans, mul(i + 1, add(pos1, pos2)));
			cout << "ans = " << ans << endl;
		}
		cout << ans << "\n";
	}
	return 0;
}