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
typedef double NUM;
const NUM EPS = 1e-12, MAGIC = 2.71828e18;
const int MN = 1005;
struct VEC {
	NUM x, y;
}a[MN];
struct RAY {
	VEC u, v;
};
inline NUM sqr(NUM a) {return a * a;}
inline NUM sqr(const VEC &a) {
	return sqr(a.x) + sqr(a.y);
}
inline NUM abs(const VEC &a) {
	return sqrt(sqr(a));
}
inline VEC operator - (const VEC &a, const VEC &b) {
	return (VEC) {a.x - b.x, a.y - b.y};
}
inline VEC operator + (const VEC &a, const VEC &b) {
	return (VEC) {a.x + b.x, a.y + b.y};
}
inline VEC operator / (const VEC &a, NUM u) {
	return (VEC) {a.x / u, a.y / u};
}
inline NUM operator % (const VEC &a, const VEC &b) {
	return a.x * b.x + a.y * b.y;
}
inline VEC operator * (const VEC &a, NUM u) {
	return (VEC) {a.x * u, a.y * u};
}
inline VEC operator * (NUM u, const VEC &a) {
	return (VEC) {a.x * u, a.y * u};
}
inline VEC operator / (const VEC &a, const VEC &b) {
	return (VEC) a % b / sqr(b) * b;
}
//const NUM pi = acos(-1.0);
//VEC rotate(const VEC &a, NUM u) {
//	return (VEC) {
//		cos(u) * a.x - sin(u) * a.y, sin(u) * a.x + cos(u) * a.y
//	};
//}
VEC project(const VEC &p, const RAY &l) {
	return (p - l.u) / (l.v - l.u) + l.u;
}
inline NUM cmp(NUM a, NUM b) {
	return fabs(a - b) >= EPS + fabs(a) * EPS ? a - b : 0;
}
inline NUM cmp(const VEC &a, const VEC &b) {
	NUM at = cmp(a.x, b.x);
	return !at?(cmp(a.y, b.y)):at;
}
inline bool operator == (const VEC &a, const VEC &b) {
	return !cmp(a, b);
}
inline bool operator < (const VEC &a, const VEC &b) {
	return cmp(a, b) < 0;
}
NUM cmp_side(const VEC &a, const VEC &b) {
	return cmp(a.x * b.y, a.y * b.x);
}

vector<VEC> ch(vector<VEC> u) {
	sort(u.begin(), u.end());
	u.erase(unique(u.begin(), u.end()), u.end());
	if(u.size() < 3) return u;
	vector<VEC> c;
	for(size_t i = 0, o = 1, m = 1; ~i; i += o) {
		while(c.size() > m) {
			VEC a = c.back() - c[c.size() - 2];
			VEC b = c.back() - u[i];
			if(cmp_side(a, b) < 0) break;
			c.pop_back();
		}
		c.push_back(u[i]);
		if(i + 1 == u.size()) m = c.size(), o = -1;
	}
	c.pop_back();
	return c;
}

NUM get_dis(RAY line, VEC x) {
	VEC y = project(x, line);
	return abs(y - x);
}

int main() {
	int n = read();
	REP(i, 0, n) a[i].x = read(), a[i].y = read();

	std::vector<VEC> g;
	REP(i, 0, n) g.pb(a[i]);
	std::vector<VEC> v = ch(g);
	std::vector<RAY> r;
	REP(i, 0, v.size()) {
		int ii = (i + 1) % v.size();
		r.pb((RAY){v[i], v[ii]});
	}
	
//	REP(i, 0, v.size()) dbg1(v[i].x), dbg2(v[i].y);
	
	double ans = 1e18;
	int id = 0;
	RAY ans_line;
	REP(i, 0, r.size()) {
		RAY line1 = r[i];
//		dbg1(r[i].u.x); dbg1(r[i].u.y);
//		dbg1(r[i].v.x); dbg2(r[i].v.y);
		NUM dis = 0.0, disid = 0;
		REP(j, 0, v.size()) {
			if(get_dis(line1, v[j]) > dis) {
				dis = max(dis, get_dis(line1, v[j]));
				disid = j;
			}
		}
		if(dis < ans) {
			ans = dis;
			id = i;
			VEC _1 = r[i].u, _2 = r[i].v, _3 = project(v[disid], r[i]);
			VEC add = (v[disid] - _3) / 2.0;
			_1 = _1 + add;
			_2 = _2 + add;
			ans_line = (RAY){_1, _2};
		}	
	}
	
//	dbg2(id);
	
	printf("%.15lf\n", ans/2.0);
	REP(i, 0, n) {
		VEC _ = project(a[i], ans_line);
		printf("%.10lf %.10lf\n", _.x, _.y);
	}
	
	return 0;
}