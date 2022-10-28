#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
int X, Y;
const int mod = 1e9 + 7;
long long ans = 0;
long long res = 1;
long long f[35];
int Add(int x, int y) {return (x + y) % mod;}
int Mul(int x, int y) {return ((1ll * x * y) % mod + mod) % mod;}
int Ans[35][2][2];
long long dfs(int _1, int _2, int now, int nowx, int nowy) {
	if(now == -1) {return 1;}
	if(!_1 && !_2) {return f[now + 1];}
	if(Ans[now][_1][_2]) {
		// puts("xxxxx");
		return Ans[now][_1][_2];
	}
	long long tmp = 0;
	// 1 0 
	if((X>>now&1) || !_1) {
		tmp = Add(tmp, dfs(_1&((X>>now&1)==1), _2&((Y>>now&1)==0), now - 1, nowx + (1<<now), nowy));
	}
	// 0 1
	if((Y>>now&1) || !_2) {
		tmp = Add(tmp, dfs(_1&((X>>now&1)==0), _2&((Y>>now&1)==1), now - 1, nowx, nowy + (1<<now)));
	}
	// 0 0
	tmp = Add(tmp, dfs(_1&((X>>now&1)==0), _2&((Y>>now&1)==0), now - 1, nowx, nowy));
	Ans[now][_1][_2] = tmp;
	return tmp;
}
signed main() {
	int T;
	cin>>T;
	f[1] = 3;
	for(int i = 2; i <= 32; ++i) {
		f[i] = Mul(f[i - 1], 3);
	}
	while(T--) {
		cin>>X>>Y;
		ans = 0; res = 1;
		for(int i = 0; i <= 30; ++i) {
			long long num = dfs((X>>(i+1))==0, (Y>>(i+1))==0, i, 0, 0);
			ans = Add(ans, Mul((num - res), (i + 1)));
			res = num;
		}
		cout<<ans<<endl;
		memset(Ans, 0, sizeof Ans);
	}
	return 0;
}