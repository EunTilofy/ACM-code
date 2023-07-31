#include<bits/stdc++.h>
using namespace std;
#define MN 300005
#define INF 1000000000LL

long long L, R, ans;
int n,k;
int a[MN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >>k;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	sort(a+1, a+n+1);
	long long sum = 0;
	for(int i = 1; i <= n; ++i) sum += a[i];

	L = (sum + n - 1) / n;
	R = INF;
	int id = (n + 1)/2;
	L = max(L, (long long)a[id]);
	ans = INF + INF/2;

	while(L <= R) {
		// cerr << L << " " << R << " ";
		long long mid = (L + R) >>1;
		long long lef = 0;
		for(int i = id; i <= n; ++i) if(a[i] < mid) lef += mid - a[i];
		// cerr << lef << endl;
		if(lef <= (1ll * mid * n - sum)) ans = mid, R = mid - 1;
		else L = mid + 1;
	}

	ans = 1ll * ans * n - sum;
	if(ans <= k) cout << ans <<endl;
	else cout << -1 << endl;
}