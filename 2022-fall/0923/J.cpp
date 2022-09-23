#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define db double
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define y1 y1111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x<<1) + (x<<3) + ch - '0'; ch = getchar();}
	return x * f;
}

const int N = 1e6 + 10;
struct node {
	int x, y;
} a[N];

bool cmp(node A, node B) {
	return A.y == B.y ? A.x < B.x : A.y > B.y;
}

int main() {
	int n = read();
	for(int i = 1; i <= n; ++i) {
		a[i].x = read(), a[i].y = read();
	}
	sort(a + 1, a + 1 + n, cmp);
	int l = 0, r = 0;
	ll ans3 = 0;
	for(int i = 1; i <= n; ++i) {
		int j = i;
		for(; j <= n && a[j].y == a[i].y; ++j) ;
		j--;
		// printf("%d %d\n", i, j);
		if(i == 1) {
			l = a[i].x, r = a[j].x;
			ans3 += (r - l + 1);
		} else {
			ans3 += 1ll * (r - l + 1) * (a[i - 1].y - a[i].y - 1);
			l = min(l, a[i].x), r = max(r, a[j].x);
			ans3 += 1ll * (r - l + 1);
		}
		// printf("%d %d %lld\n", l, r, ans3);
		i = j;
	}
	ans3 += 1ll * (r - l + 1) * a[n].y;
	ll ans2 = 2ll * (a[1].y + 2) + (r - l + 1);
	printf("%lld ", ans2 + 2);
	printf("%lld ", ans2);
	printf("%lld ", ans3);
	return 0;
}