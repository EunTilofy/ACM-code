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
#define se second y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline long long read() {
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

long long t[100], k[100], tot;

int main() {
	long long x,xxx;// = read();
	long long y,yyy;// = read();
	srand(time(NULL));
	for(xxx=1e17; xxx<=1e17+1e4; xxx++) {
		for(yyy=5e17; yyy<=5e17+5e3; yyy++) {
//	while(1) {
//		xxx=rand()%10000,yyy=rand()%10000;
			tot=0;
			x=xxx,y=yyy;
			while(1) {
				// printf("now %d %d\n", x, y);
				long long xx = abs(x);
				long long yy = abs(y);
				if(xx == 0 || yy == 0) break;
				if(yy > xx) {
					t[++tot] = 2;
					k[tot] = -yy/xx * (y/yy) * (x/xx);
					y += k[tot] * x;
				} else {
					t[++tot] = 1;
					k[tot] = -xx/yy * (y/yy) * (x/xx);
					x += k[tot] * y;
				}
			}
			if(tot>=50) {
				printf("!%d %lld %lld\n",tot,x,y);
				return 0;
			}
			long long a=xxx,b=yyy;
			for(int i=1; i<=tot; i++) {
				if(t[i]==1)a=a+k[i]*b;
				else b=b+k[i]*a;
				if(a>1e18||b>1e18)printf("!!!");
			}
			if(a&&b) {
				printf("!!%d %lld %lld\n",tot,x,y);
				return 0;
			}
//			printf("%lld\n", tot);
//			for(int i = 1; i <= tot; ++i) {
//				printf("%lld %lld\n", t[i], k[i]);
//			}
		}
	}
	return 0;
}