#include<bits/stdc++.h>
#define dbg1(x) std::cerr<<#x<<'='<<(x)<<" "
#define dbg2(x) std::cerr<<#x<<"="<<(x)<<endl
#define dbg3(x) std::cerr<<#x<<endl
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
using namespace std;
typedef double NUM;
const NUM EPS = 1e-12;
struct VEC{
	NUM x, y;
}a[1005];
struct Po{
	int X, Y;
	NUM v;
}c[1005];
bool b[1005][1005];
NUM f[1005];

struct RAY{
	VEC u;
	NUM r;
};
inline NUM sqr(NUM a) {
	return a*a;
}
inline NUM cmp(NUM a, NUM b) {
	return fabs(a-b)>=EPS+fabs(a)*EPS?a-b:0;
}
inline NUM sqr(const VEC &a) {
	return sqr(a.x) + sqr(a.y);
}
inline double abs(const VEC &a) {
	return sqrt(sqr(a));
}
inline NUM cmp(const VEC &a, const VEC &b) {
	NUM at=cmp(a.x, b.x);
	return !at?cmp(a.y,b.y):at;
}
inline VEC operator+(const VEC&a, const VEC&b) {
	return (VEC){a.x+b.x, a.y+b.y};
}
inline VEC operator-(const VEC&a, const VEC&b) {
	return (VEC){a.x-b.x, a.y-b.y};
}
inline NUM operator*(const VEC&a, const VEC&b) {
	return a.x*b.y-a.y*b.x;
}
inline NUM operator%(const VEC&a, const VEC&b) {
	return a.x*b.x+a.y*b.y;
}
inline VEC operator-(const VEC&a) {
	return (VEC){-a.x,-a.y};
}
NUM cmp_side(const VEC &a, const VEC &b) {
	return cmp(a.x*b.y, +a.y*b.x);
}
NUM cmp_axis(const VEC &a, const VEC &b) {
	return cmp(a.x*b.x, -a.y*b.y);
}
bool CMP(std::pair<VEC, int> x, std::pair<VEC, int> y) {
	VEC xx = x.fi;
	VEC yy = y.fi;
	double pos = atan2(xx.y, xx.x), tmp = atan2(yy.y, yy.x);
	double cur = cmp(pos, tmp);
	if(cur < 0) return 1;
	else if(cur > 0) return 0;
	return cmp(abs(xx), abs(yy));
}
NUM solve() {
	memset(b, 0, sizeof b);
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i].x>>a[i].y>>c[i].v;
		c[i].X = (int)(a[i].x*10000 + .5);
		c[i].Y = (int)(a[i].y*10000 + .5);
	}
	/***init-b***/
	for(int i = 1; i < n; ++i) {
		std::vector<std::pair<VEC, int> > _;
		for(int j = 1; j <= n; ++j) if(i != j) {
			_.pb(mkp(a[j] - a[i], j));
		}
		std::sort(_.begin(), _.end(), CMP);
		int last = -1;
		VEC las;
		for(auto y : _) {
			if(last == -1 || !(cmp_side(las, y.fi)&&cmp_axis(las, y.fi)>=EPS)) {
				if(y.se > i) b[i][y.se] = 1;
				dbg1(i); dbg2(y.se);
			}
			last = 1;
			las = y.fi;
		}
	}
	
	double ans = c[1].v;
	for(int i = 1; i <= n; ++i) f[i] = 0.0;
	for(int i = 2; i <= n; ++i) {
		f[i] = -1e18;
		for(int j= 1; j < i; ++j)if(b[j][i]) {
			f[i] = max(f[i], f[j] - abs(a[i] - a[j]) + c[i].v);
		}
	}
	for(int i = 1; i <= n; ++i) ans = max(ans, f[i]);
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		double ans = solve();
		cout << "Case #" << o << ": " << fixed << setprecision(10) << ans << "\n";
	}
	return 0;
}
/*
3
4
0.0000 0.0000 0.0000
1.0000 0.0000 0.5000
1.0000 1.0000 2.0000
0.0000 1.0000 0.5000
5
0.0000 0.0000 0.0000
1.0000 1.0000 0.5000
2.0000 0.0000 2.0000
2.0000 2.0000 3.0000
0.0000 2.0000 0.0000
11
0.0000 0.0000 100.0000
1.0000 1.0000 100.0000
2.0000 0.0000 100.0000
2.0000 2.0000 100.0000
3.0000 2.0000 100.0000
3.0000 -2.0000 100.0000
1.0000 0.0000 100.0000
1.0000 -3.0000 100.0000
4.0000 -3.0000 100.0000
4.0000 4.0000 100.0000
0.0000 4.0000 100.0000
*/