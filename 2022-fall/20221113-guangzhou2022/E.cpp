#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;
struct node {
	int x, id;
} a[N];

ll ans[N];
bool cmp(node A, node B) {
	return A.x == B.x ? A.id < B.id : A.x < B.x;
}

int tr[N];
void upd(int x, int k) {
	for(; x < N; x += x & (-x)) tr[x] += k;
}
int get(int x) {
	int ans = 0;
	for(; x; x -= x & (-x)) ans += tr[x];
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].x;
		a[i].id = i;
	}
	
	sort(a + 1, a + 1 + n, cmp);
	ll pos = 0;
	for(int i = 1; i <= n; ++i) {
		int id = a[i].id;
		ans[id] = 1ll * a[i].x * (i - 1) - pos + get(id);
		ans[id] = ans[id] > m - 2 ? -1 : ans[id];
		pos += a[i].x, upd(id, 1);
	}
	
	for(int i = 1; i <= n; ++i) cout << ans[i] << "\n";
	return 0;
}