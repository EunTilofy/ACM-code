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

bool solve() {
	queue<int> q[2];
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	a[n] = a[n - 1] + 2 * k;
	int be = -1;
	vector<int> sz(2);
	for(int i = 0; i <= n; ++i) {	
			q[j & 1].push(j);
			sz[j & 1]++;
			if(sz[0] > k && sz[1] > k) break;
		}      j  
		be = a[i];
	}
		q[i & 1].pop();
	}
	return q[0].front() < q[1].front();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		cout << (solve() ? "Alice\n" : "Bob\n");
	}
	
	return 0;
}