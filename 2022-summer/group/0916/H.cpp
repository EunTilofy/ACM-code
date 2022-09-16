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
int T,n,i,j,r,d,sa,sb,la;
long long k,K,bit[70],ans,mx;
char a[1000],b[1000];
bool f;
int main() {
	bit[0]=1;
	for(i=1; i<=60; i++)bit[i]=bit[i-1]*2;
	scanf("%d%d",&T,&n);
	while(T--) {
		scanf("%lld",&k),K=k,sa=sb=la=r=d=0;
		if(k&1) {
			printf("-1\n");
			continue;
		}
		for(i=60; i>=0; i--)
			if(k>=bit[i]) {
				if(la) {
					a[++sa]='R',la--,r++;
					while(la>=i)a[++sa]='D',d++,la--;
				}
				k-=bit[i],la=i;
			}
		if(la) {
			a[++sa]='R',la--,r++;
			while(la>=1)a[++sa]='D',d++,la--;
		}
		r=n-1-r,d=n-1-d;
		b[++sb]='D',b[++sb]='R',b[++sb]='U',b[++sb]='L';
		if(K==2) {
			for(i=1; i<=d; i++)b[++sb]='D';
			for(i=1; i<=r; i++) {
				b[++sb]='R';
				b[++sb]='R',b[++sb]='U',b[++sb]='L',b[++sb]='D';
			}
		} else {
			for(i=1; i<=r; i++) {
				b[++sb]='R';
				for(j=1; j<=2; j++)b[++sb]='D',b[++sb]='R',b[++sb]='U',b[++sb]='L';
			}
			for(i=1; i<=d; i++)b[++sb]='D';
		}
		for(i=1; i<=sa; i++)b[++sb]=a[i];
//		for(i=1; i<=sb; i++)printf("%c",b[i]);
//		puts("");
		b[sb+1]='\0';
		printf("%s\n",b+1);
	}
	return 0;
}