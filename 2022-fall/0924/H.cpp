#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
struct node {
	int id, x, y;
} a[MN], b[MN];
int all[MN], f[MN];

bool cmp(node xx, node yy) {
	return xx.x == yy.x ? xx.y > yy.y : xx.x < yy.x;
}

struct tree {
	int tr[MN];
	int lower(int x) { return x & (-x); }
	void upd(int x, int y) {
//		printf("%d %d\n", x, y);
		for(; x < MN; x += lower(x))
			tr[x] = max(tr[x], y);
	}
	int get(int x) {
		int ans = 0;
		for(; x; x -= lower(x))
			ans = max(ans, tr[x]);
		return ans;
	}
} t;

vector<int> g[MN], ans1, ans2;

void print(vector<int> q) {
	sort(q.begin(), q.end());
	printf("%d ", (int)q.size());
	for(auto x : q) printf("%d ", x);
	puts("");
}

vector<int> p1, p2;

int get(int x, int l, int r) {
	int ans = r + 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(b[mid].x > x) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

void solve(int dep) {
	if(p1.size() == 1) ans2.push_back(a[p1[0]].id);
	int cnt = 0;
	for(auto x : p1) {
		ans1.push_back(a[x].id);
		b[++cnt] = a[x];
	}
	if(!dep) return ;
	p2.clear();
	sort(b + 1, b + 1 + cnt, cmp);
//	printf("dep = %d %d\n", dep, cnt);
	for(auto x : g[dep]) {
		int id = get(a[x].x, 1, cnt);
//		printf("%d %d\n", a[x].x, id);
		if(id <= cnt && a[x].y < b[id].y) {
			p2.push_back(x);
//			printf("x = %d\n", x);
		}
	}
	swap(p1, p2), solve(dep - 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  	int n = read(), cnt = 0;
	for(int i = 1; i <= n; ++i) {
		a[i].id = i;
		a[i].x = read(), a[i].y = read();
		all[++cnt] = a[i].x;
		all[++cnt] = a[i].y;
	} 
	sort(all + 1, all + 1 + cnt);
	int tot = unique(all + 1, all + 1 + cnt) - all - 1;
	for(int i = 1; i <= n; ++i) {
		a[i].x = lower_bound(all + 1, all + 1 + tot, a[i].x) - all;
		a[i].y = lower_bound(all + 1, all + 1 + tot, a[i].y) - all;
//		printf("%d %d\n", a[i].x, a[i].y);
	}
	sort(a + 1, a + 1 + n, cmp);
//	printf("????");
	for(int i = 1; i <= n; ++i) {
		int j = i;
		for(; j + 1 <= n && a[i].x == a[j + 1].x; ++j);
//		printf("%d %d\n", i, j);
		for(int k = i; k <= j; ++k)  
			f[k] = t.get(a[k].y - 1) + 1;
		for(int k = i; k <= j; ++k)
			t.upd(a[k].y, f[k]);
		i = j;
	}
//	puts("????");
	int mx = 0;
	for(int i = 1; i <= n; ++i) {
//		printf("f[%d] = %d\n", i, f[i]);
		g[f[i]].push_back(i);
		mx = max(mx, f[i]);
	}
//	printf("%d\n", mx);
	for(auto x : g[mx]) p1.push_back(x);
//	puts("???");
	solve(mx - 1);
	print(ans1), print(ans2);
    return 0;
}