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
inline int qpow(int x,ll y,int m=mod) {
	int r=1;
	for(; y; y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;
	return r;
}
inline int read() {
	int x=0,f=1;
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
int T,i;
long long n,m,q;
__int128 ans;
char s[10];
long long num(long long q) {
	return (((q-1)/n)+1)+((q-1)%n)*m;
}

__int128 getr(__int128 l, __int128 r) {
    // dbg1(l); dbg2(r);
	return (l + r) * (r - l + 1) / 2;
}
__int128 getc(__int128 l, __int128 r) {
    // dbg1(l); dbg2(r);
	return ((l - 1) * m + 2 + (r - 1) * m) * (r - l + 1) / 2;
}
__int128 ccc(long long l, long long r, long long xx, long long xk) {
    // dbg3(ccc);
    // dbg1(l); dbg2(r);
    // dbg1(xx); dbg2(xk);
	long long len = r - l + 1;
	long long mxlen = n / 2;
    --l, --r;
	while(mxlen >= len) {
		if(xk > mxlen) {
			xk -= mxlen;
			l ^= mxlen;
		}
		mxlen>>=1;
	}
	long long ret  = getc(l + 1, l + len) + (xx - 1ll) * len;
    // dbg2(ret);
    return ret;
}
__int128 cal_c(long long x, long long y) {
    // dbg1(x); dbg2(y);
	__int128 ret = 0;
	long long xk = (x - 1) / m + 1;
	long long xx = (x - 1) % m + 1;
	long long _ = 0ll, nowl = n / 2;
	for(; nowl; nowl >>= 1) {
		if(y >= nowl) {
			ret += ccc(_ + 1, _ + nowl, xx, xk);
			_ += nowl;
			y -= nowl;
		}
	}
    return ret;
}
__int128 ccr(long long l, long long r, long long xx, long long xk) {
    // dbg3(ccr);
    // dbg1(l); dbg2(r);
    // dbg1(xx); dbg2(xk);
	long long len = r - l + 1;
	long long mxlen = m / 2;
    --l, --r;
	while(mxlen >= len) {
		if(xk > mxlen) {
			xk -= mxlen;
			l ^= mxlen;
		}
		mxlen>>=1;
	}
	return getr(l + 1, l + len) + (xx - 1ll) * len * m;
}
__int128 cal_r(long long x, long long y) {
    // dbg1(x); dbg2(y);
	__int128 ret = 0;
	long long xk = (x - 1) / n + 1;
	long long xx = (x - 1) % n + 1;
	long long _ = 0ll, nowl = m / 2;
	for(; nowl; nowl >>= 1) {
		if(y >= nowl) {
			ret += ccr(_+1, _+nowl, xx, xk);
			_ += nowl;
			y -= nowl;
		}
	}
    return ret;
}

void solve2(int x,long long q,long long now) {
	if(!now)return;
	if(x==0) { //<m
		ans += cal_r(q, now);
		return;
	}
	int l=1<<x,z=1<<x-1;//z:si
	long long i=q;
	if(i%l>z||i%l==0)i-=z;
	else i+=z;
	long long j=num(q);
	long long st=(j-1)/(m*z)*(m*z)+1,ed=st+(m*z)-1;
	// printf("!!%d %lld %lld %lld %lld %lld %lld\n",x,now,q,j,i,st,ed);
	if(m*z<=now) {
		ans+=(st+ed)*(ed-st+1)/2,solve2(x-1,i,now-m*z);
	} else {
		solve2(x-1,q,now);
	}
}
void solve(int x,long long now) {
	if(!now)return;
	int l=1<<x,z=1<<x-1;//z:si
	long long i=q;
	if(i%l>z||i%l==0)i-=z;
	else i+=z;
	long long j=num(i);
	long long st=(j-1)/(m*z)*(m*z)+1,ed=st+(m*z)-1;
	// printf("%d %lld %lld %lld %lld\n",x,i,j,st,ed);
	if(now>=m*z) {
		ans+=(st+ed)*(ed-st+1)/2;//int128?
		solve(x+1,now-m*z);
	} else {
		solve2(x-1,i,now);
	}
}
void lsolve2(int x,long long q,long long now) {
	if(!now)return;
	if(x==0) { //<n
		ans += cal_c(q, now);
		return;
	}
	int l=1<<x,z=1<<x-1;//z:si
	long long i=q;
	if(i%l>z||i%l==0)i-=z;
	else i+=z;
	long long st=(i-1)%m+1,ed=st+(n-1)*m;
	// printf("!!%d %lld %lld %lld %lld %lld\n",x,now,q,i,st,ed);
	if(n*z<=now) {
		ans+=(st+ed)*n*z/2,lsolve2(x-1,i,now-n*z);
	} else {
		lsolve2(x-1,q,now);
	}
}
void lsolve(int x,long long now) {
	if(!now)return;
	int l=1<<x,z=1<<x-1;//z:si
	long long i=q;
	if(i%l>z||i%l==0)i-=z;
	else i+=z;
	long long st=(i-1)%m+1,ed=st+(n-1)*m;
	// printf("%d %lld %lld %lld\n",x,i,st,ed);
	if(now>=n*z) {
		ans+=(st+ed)*n*z/2;//int128?
		lsolve(x+1,now-n*z);
	} else {
		lsolve2(x-1,i,now);
	}
}
void write(__int128 x) {
	if(x>=10) write(x/10);
	printf("%d", (int)(x % 10));
}
long long st,ed,j;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld",&n,&m),n=1<<n,m=1<<m,ans=0;
		scanf("%s",s);
		scanf("%lld",&q);
		if(s[0]=='t'||s[0]=='b') {
			if(s[0]=='b')q=n*m+1-q;
			if(q-n>=0) {
				st=(q-1)%m+1,ed=st+(n-1)*m;
				ans=(st+ed)*n/2,lsolve(1,q-n);
			} else {ans=cal_c(q,q);}
		} else {
			if(s[0]=='r')q=n*m+1-q;
			j=num(q);
			if(j-m>=0) {
				st=(j-1)/(m)*(m)+1,ed=st+(m)-1;
				ans=(st+ed)*(ed-st+1)/2,solve(1,j-m);
			} else {ans=cal_r(q,q);}
		}
		write(ans);
		puts("");
	}
	return 0;
}
