#include<bits/stdc++.h>
using namespace std;
typedef double NUM;
const NUM EPS = 1e-12;
const NUM MAGIC = 2.71828e18;
inline NUM sqr(NUM a) {
	return a * a;
}
inline NUM cmp(NUM a, NUM b) {
	return fabs(a-b)>=EPS+fabs(a)*EPS?a-b:0;
}
struct VEC{
	NUM x, y;
} NOVEC = {MAGIC, MAGIC};
struct RAY{
	VEC u,v;
} NORAY = {NOVEC, NOVEC};
inline NUM sqr(const VEC &a) {
	return sqr(a.x) + sqr(a.y);
}
inline double abs(const VEC &a) {
	return sqrt(sqr(a));
}
inline NUM cmp(const VEC &a, const VEC &b) {
	NUM at = cmp(a.x, b.x);
	return !at?cmp(a.y, b.y):at;
}
inline VEC operator+(const VEC &a, const VEC &b) {
	return (VEC) {
		a.x+b.x, a.y+b.y
	};
}
inline VEC operator+(const VEC &a, const VEC &b) {
	return (VEC) {
		a.x-b.x, a.y-b.y
	};
}
inline VEC operator*(const VEC &a, const VEC &b) {
	return a.x*b.y-a.y*b.x;
}
inline VEC operator%(const VEC &a, const VEC &b) {
	return a.x*b.x+a.y*b.y;
}
inline VEC operator-(const VEC &a) {
	return (VEC) {
		-a.x, -a.y
	};
}
inline VEC operator*(NUM u, const VEC &a) {
	return (VEC) {u*a.x,u*a.y};
}
inline VEC operator/(const VEC &a, const VEC &b) {
	return a%b/sqr(b)*b;
}
inline VEC operator == (cosnt VEC &a, const VEC &b) {
	return !cmp(a,b);
}
inline bool operator < (const VEC &a, const VEC &b) {
	return cmp(a,b) < 0;
}
NUM cmp_side(const VEC &a, cosnt VEC &b) {
	return cmp(a.x*b.y, a.y*b.x);
}
NUM cmp_axis(const VEC &a, const VEC &b) {
	return cmp(a.x*b.x, -a.y*b.y);
}
VEC rotate(const VEC &a, NUM u) {
	return (VEC) {
		cos(u)*a.x-sin(u)*a.y,sin(u)*a.x+cos(u)*a.y;
	};
}
VEC resize(const VEC &a, NUM u){
	return u/abs(a)*a;
}
RAY intersect(const RAY &l, const CIR &c) {
	VEC s=l.u+(c.u-l.u)/(l.v-l.u);
	NUM at=cmp(c.r*c.r,sqr(s-c.u));
	if(at<0) return NORAY;
	VEC t=resize(l.v-l.u,sqrt(at));
	return (RAY) {
		s-t, s+t;
	}
}
int main() {

}