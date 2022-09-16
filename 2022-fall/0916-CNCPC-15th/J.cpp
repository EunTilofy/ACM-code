#include<bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
struct P {
	db x, y, z;
}A, B;
int a,b,c,x,y,z,r;
const db PI = acos(-1.);
db len(P o) {
	return sqrt(o.x * o.x + o.y * o.y + o.z * o.z);
}
P operator / (P u, P v) {
	return (P){u.y*v.z-u.z*v.y, u.z*v.x-u.x*v.z, u.x*v.y-u.y*v.x};
}
P operator * (P u, db x) {
	return (P){u.x*x, u.y*x, u.z*x};
}
db operator * (P u, P v) {
	return u.x*v.x + u.y*v.y +  u.z*v.z;
}
P operator + (P u, P v) {
	return (P){u.x + v.x, u.y + v.y,  u.z + v.z};
}
P operator - (P u, P v) {
	return (P){u.x - v.x, u.y - v.y,  u.z - v.z};
}
int main() {
	int T = read();
	while(T--) {
		a = read(), b = read(), c = read();
		x = read(), y = read(), z = read();
		r = read();
		A.x = a; A.y = b; A.z = c;
		B.x = x; B.y = y; B.z = z;
		P D = A * (B * A * (1.0/len(A)) * (1.0/len(A)));
		P E = D + (A / (B - D)) * (1.0/len(A / (B - D))) * len(B - D);
		P P_ = D + (E - D) * sin(PI * (db)r / 180.0) + (B - D) * cos(PI * (db)r / 180.0);
		P Q_ = D - (E - D) * sin(PI * (db)r / 180.0) + (B - D) * cos(PI * (db)r / 180.0);
		if(P_.z > Q_.z) Q_ = P_;
		printf("%.10lf %.10lf %.10lf\n", Q_.x, Q_.y, Q_.z);
	}
	return 0;
}