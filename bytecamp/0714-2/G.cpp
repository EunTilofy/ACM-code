#include<bits/stdc++.h>
using namespace std;
#define M 300005
int n,a,i,id,q,op,x,y,l,r,ans,mx;
struct node {
	int l,r,mx,lazy;
} t[M<<2];
void up(int p) {
	t[p].mx=max(t[p<<1].mx,t[p<<1|1].mx);
}
void build(int l,int r,int p) {
	t[p].l=l,t[p].r=r;
	if(l==r) {
		if(l==id)t[p].mx=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,p<<1),build(mid+1,r,p<<1|1),up(p);
}
void down(int p) {
	if(!t[p].lazy)return;
	t[p<<1].lazy=max(t[p].lazy,t[p<<1].lazy),t[p<<1].mx=max(t[p].lazy,t[p<<1].mx);
	t[p<<1|1].lazy=max(t[p].lazy,t[p<<1|1].lazy),t[p<<1|1].mx=max(t[p].lazy,t[p<<1|1].mx);
	t[p].lazy=0;
}
void add(int l,int r,int p,int d) {
//	printf("%d %d %d %d\n",l,r,p,d);
	if(t[p].l==l&&t[p].r==r) {
		t[p].lazy=max(t[p].lazy,d),t[p].mx=max(t[p].mx,d);
		return;
	}
	down(p);
	int mid=t[p<<1].r;
	if(r<=mid)add(l,r,p<<1,d);
	else if(l>mid)add(l,r,p<<1|1,d);
	else add(l,mid,p<<1,d),add(mid+1,r,p<<1|1,d);
	up(p);
}
int query(int l,int r,int p) {
	if(t[p].l==l&&t[p].r==r)return t[p].mx;
	down(p);
	int mid=t[p<<1].r;
	if(mid>=r)return query(l,r,p<<1);
	else if(mid<l)return query(l,r,p<<1|1);
	else return max(query(l,mid,p<<1),query(mid+1,r,p<<1|1));
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&a);
		if(a==1)id=i;
	}
	scanf("%d",&q),build(1,n,1);mx = 1;
	for(i=1; i<=q; i++) {
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) {
			ans=query(x,y,1);
			if(ans)add(x,y,1,ans);
		} else {
			ans=query(x,x,1)+1,add(x,x,1,ans),mx=max(ans,mx);
		}
	}
	printf("%d\n",mx-1);
	return 0;
}
