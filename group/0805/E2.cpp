#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
int a[100005],w1[50005],w2[50005];
int ww1[50005],ww2[50005];
int sum1[50005],sum2[50005];
int ton[4000005],pos[50005];
struct node{
	int l,r,id;
	long long ans;
	node(int _l=0,int _r=0,int i=0):l(_l),r(_r),id(i),ans(0ll){}
	bool operator <(const node &b){
		return pos[l]!=pos[b.l]?(l<b.l):(pos[l]&1?r<b.r:r>b.r);
	}
}item1[100005],item2[100005];
int q1,q2;
long long ans[100005];
long long newton=0;
void work(node* item,int *w,int n,int q,int *nw){
	memset(ton,0,sizeof ton);
	newton=0;
	int sz=(int) sqrt(n);
	pos[1]=0;
	for(int i=1;i<=n;i++)
		pos[i]=pos[i-1]+(i%sz==0);
	std::sort(item+1,item+q+1);
	int l=1,r=0;
	long long nowans=0;
	for(int i=1;i<=q;i++){
		for(;r<item[i].r;r++) nowans+=(ton[w[r+1]]++),newton+=(nw[r+1]==0);
		for(;l>item[i].l;l--) nowans+=(ton[w[l-1]]++),newton+=(nw[l-1]==0);
		for(;r>item[i].r;r--) nowans-=(--ton[w[r]]),newton-=(nw[r]==0);
		for(;l<item[i].l;l++) nowans-=(--ton[w[l]]),newton-=(nw[l]==0);
		item[i].ans=(r-l+1ll)*(r-l+2ll)/2-nowans-newton;
	}
	for(int i=1;i<=q;i++) ans[item[i].id]+=item[i].ans;
}
long long nans[100005];
signed main(){
	int n,q;
	int q1=0,q2=0;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]-=1;
	}
	nans[1]=1;
	for(int i=2;i<=n;i++) nans[i]=nans[i-1]+(i+1)/2;
	int n1=0,n2=0;
	for(int i=1;i<n;i+=2){
		w1[++n1]=a[i]^a[i+1];
		sum1[n1]=sum1[n1-1]^w1[n1];
	}
	for(int i=2;i<n;i+=2){
		w2[++n2]=a[i]^a[i+1];
		sum2[n2]=sum2[n2-1]^w2[n2];
	}
	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		ans[i]+=nans[b-a+1];
		if((a+2)/2<=b/2)
			item1[++q1]=node((a+2)/2,b/2,i);
		if((a+1)/2<=(b-1)/2)
			item2[++q2]=node((a+1)/2,(b-1)/2,i);
	}
	work(item1,sum1,n1,q1,w1);
	work(item2,sum2,n2,q2,w2);
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}