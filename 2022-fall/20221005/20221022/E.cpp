#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
#define P 1000000007
int a,b,i,res,L,R;
void chk(int &x) {
	if(x>=P)x-=P;
	if(x<0)x+=P;
}
struct node {
	int l,r,sum,lazy;
	int si(){
		return r-l+1;
	}
} t[N<<2];
int d(int x) {
	int y=sqrt(x) + 2;
	for(int i=2; i<= min(x - 1, y); i++)if(x%i==0)return i;
	return -1;
}
void up(int p) {
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum,chk(t[p].sum);
}
void down(int p) {
	if(t[p].lazy) {
		t[p<<1].sum+=1ll*t[p].lazy*t[p<<1].si()%P,chk(t[p<<1].sum);
		t[p<<1|1].sum+=1ll*t[p].lazy*t[p<<1|1].si()%P,chk(t[p<<1|1].sum);
		t[p<<1].lazy+=t[p].lazy,chk(t[p<<1].lazy);
		t[p<<1|1].lazy+=t[p].lazy,chk(t[p<<1|1].lazy);
		t[p].lazy=0;
	}
}
void build(int l,int r,int p) {
//	printf("%d %d\n",l,r);
	t[p].l=l,t[p].r=r;
	if(l==r) {
		if(l>=L+1&&l<=R+1)t[p].sum=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,p<<1),build(mid+1,r,p<<1|1);
	up(p);
}
void add(int l,int r,int p,int x) {
	if(t[p].l==l&&t[p].r==r) {
		t[p].sum+=1ll*x*(r-l+1)%P,chk(t[p].sum);
		t[p].lazy+=x,chk(t[p].lazy);
		return;
	}
	down(p);
	int mid=t[p<<1].r;
	if(mid<l)add(l,r,p<<1|1,x);
	else if(mid>=r)add(l,r,p<<1,x);
	else add(l,mid,p<<1,x),add(mid+1,r,p<<1|1,x);
	up(p);
}
int que(int l,int r,int p) {
	if(t[p].l==l&&t[p].r==r)return t[p].sum;
	down(p);
	int mid=t[p<<1].r;
	if(mid<l)return que(l,r,p<<1|1);
	else if(mid>=r)return que(l,r,p<<1);
	else {
		int res=que(l,mid,p<<1)+que(mid+1,r,p<<1|1);
		chk(res);
		return res;
	}
}
signed main() {
	freopen("jumping.in","r",stdin);
	freopen("jumping.out","w",stdout);
	scanf("%lld%lld",&a,&b),L=d(a);
	if(L==-1) {
		printf("0\n");
		return 0;
	}
	R=a/L,build(1,b-a+1,1);
	for(i=a+1; i<=b; i++) {
		L=d(i),res=0;
		if(L==-1)continue;
		R=i/L;
		if(i-L-a+1>=1)res=que(max(1ll,i-R-a+1),i-L-a+1,1);
		else res=0;
		if(i+L-a+1<=b-a+1)add(i+L-a+1,min(b-a+1,i+R-a+1),1,res);
//		printf("%d %d %d %d\n",i,L,R,res);
	}
	res+=que(b-a+1,b-a+1,1),chk(res);
	printf("%lld\n",res);
	return 0;
}