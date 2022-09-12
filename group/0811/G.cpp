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
#define M 200005
int n,h[M],i,k,cnt[M],mx[M],si,f1,f2,m1,m2,l,r;
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&h[i]);
		if(i==1||(h[i]&1)!=(h[i-1]&1))si++,cnt[si]=1,mx[si]=h[i];
		else cnt[si]++,mx[si]=max(mx[si],h[i]);
	}
	for(i=1; i<=si; i++) {
		if(cnt[i]&1)l++,mx[l]=mx[i],cnt[l]=cnt[i];
		else {
			k=i+1;
			int f=0;
			while((!(cnt[i]&1))&&k<=si&&l) {
				f=mx[i];
				if(!(cnt[l]&1)&&!(cnt[k]&1))mx[i]=max(mx[i],max(mx[k],mx[l]));
				else mx[i]=max(mx[i]+1,max(mx[k],mx[l]));
				cnt[i]+=cnt[k]+cnt[l],k++,l--;
				if(mx[i]==f) {
					f=-1;
					break;
				}
			}
//			printf("!!%d %d %d\n",i,l,k);
			if(f==-1) {
				if(l)cnt[l]+=cnt[i],mx[l]=max(mx[l],mx[i]);
				else l++,cnt[l]=cnt[i],mx[l]=mx[i];
				if(k<=si)cnt[l]+=cnt[k],mx[l]=max(mx[l],mx[k]);
				if(k<=si)cnt[k]=cnt[l],mx[k]=mx[l],l--;
				i=k-1;
			} else l++,cnt[l]=cnt[i],mx[l]=mx[i],i=k-1;
		}
//		printf("%d %d %d\n",i,l,mx[1]);
	}
	int fl=0,ans=0,ff=0;
	for(i=1; i<=l; i++)
		if(cnt[i]&1)ans=max(ans,mx[i]),ff=1;
		else ans=max(ans,mx[i]+1);
	if(!ff)ans--;
	for(i=1; i<=l; i++)if(cnt[i]&1&&(ans-mx[i])&1)fl=1;
	if(fl)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}