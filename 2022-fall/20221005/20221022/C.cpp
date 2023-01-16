#include<bits/stdc++.h>
using namespace std;
typedef double NUM;

const NUM EPS=1e-12;

struct VEC{
	NUM x, y;
}a[4], b[4], oa, ob;

struct RAY{
	VEC u, v;
};

inline NUM sqr(NUM a) {return a * a;}
inline NUM cmp(NUM a, NUM b) {return fabs(a-b)>=EPS+fabs(a)*EPS?a-b:0;}

inline NUM sqr(const VEC &a) {
	return sqr(a.x)+sqr(a.y);
}
inline NUM abs(const VEC &a) {
	return sqrt(sqr(a));
}
inline NUM cmp(const VEC &a, const VEC &b) {
	NUM at = cmp(a.x,b.x);
	return !at?cmp(a.y,b.y):at;
}
inline VEC operator+(const VEC &a, const VEC &b) {
	return (VEC){a.x+b.x,a.y+b.y};
}
inline VEC operator-(const VEC &a, const VEC &b) {
	return (VEC){a.x-b.x,a.y-b.y};
}
inline VEC operator*(const VEC &a, const NUM &b) {
	return (VEC){a.x*b,a.y*b};
}
inline VEC operator ~(const VEC &a) {
	return (VEC){-a.y, a.x};
}
inline bool operator ==(const VEC &a, const VEC &b) {
	return !cmp(a,b);
}
NUM cmp_side(const VEC &a, const VEC&b) {
	return cmp(a.x*b.y, a.y*b.x);
}
bool CHK(VEC u, VEC v) {
	for(int i = 0; i < 4; ++i) 
		for(int j = i + 1; j < 4; ++j) {
			if(cmp_side(v - u, a[i] - u) >= EPS  && cmp_side(v - u, a[j] - u) <= -EPS) return 0;
			if(cmp_side(v - u, a[j] - u) >= EPS  && cmp_side(v - u, a[i] - u) <= -EPS) return 0;
		}
	for(int i = 0; i < 4; ++i) 
		for(int j = i + 1; j < 4; ++j) {
			if(cmp_side(v - u, b[j] - u) >= EPS  && cmp_side(v - u, b[i] - u) <= -EPS) return 0;
			if(cmp_side(v - u, b[i] - u) >= EPS  && cmp_side(v - u, b[j] - u) <= -EPS) return 0;			
		}
	return 1;
}
bool chk(VEC u, VEC v, int na, int nb) {
	if(!CHK(u, v)) return 0;
	int ma = 0, mb = 0;
	for(int i = 0; i < 4; ++i) if(cmp_side(u - v, a[i] - v) == 0) ++ma;
	for(int i = 0; i < 4; ++i) if(cmp_side(u - v, b[i] - v) == 0) ++mb;
	return na==ma&&nb==mb;
}
bool CHK_infi() {
	int co = 0;
	for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) 
		if(a[i] == b[j]) ++co;
	return co == 1;
}
int main() {
	freopen("equal-squares.in","r",stdin);
	freopen("equal-squares.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin>>a[0].x>>a[0].y>>a[2].x>>a[2].y;
	std::cin>>b[0].x>>b[0].y>>b[2].x>>b[2].y;
	oa = (a[0] + a[2]) * 0.5;
	ob = (b[0] + b[2]) * 0.5;
	a[1] = oa + (~(a[0]-oa));
	b[1] = ob + (~(b[0]-ob));
	a[3] = oa - (~(a[0]-oa));
	b[3] = ob - (~(b[0]-ob));
	
	if(CHK_infi()) {
		cout<<"Infinity";
		return 0;
	}
	int ans = 0;
	// 1 + 1
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j) {
			ans += chk(a[i], b[j], 1, 1);
		} 
	// 1 + 2
	for(int i = 0; i < 4; ++i) 
		for(int j = i + 1; j < 4; ++j) {
			ans += chk(a[i], a[j], 2, 1);
		}
	// 2 + 1
	for(int i = 0; i < 4; ++i) 
		for(int j = i + 1; j < 4; ++j) {
			ans += chk(b[i], b[j], 1, 2);
		}
	// 2 + 2
	for(int i = 0; i < 4; ++i) 
		for(int j = i + 1; j < 4; ++j) {
			ans += chk(a[i], a[j], 2, 2);
		}
	cout<<ans;
	return 0;
}