#include<bits/stdc++.h>
using namespace std;
#define M 500005
int ls,lt,i,ans,st[M],ed[M],res;
char S[M],T[M];
struct node {
	int l,r,mx,lazy;
} t[M<<2];
void build(int l,int r,int p) {
	t[p].l=l,t[p].r=r;
	if(l==r) {
		return;
	}
	int mid=l+r>>1;
	build(l,mid,p<<1),build(mid+1,r,p<<1|1);
}
void up(int p) {
	t[p].mx=max(t[p<<1].mx,t[p<<1|1].mx);
}
void down(int p) {
	if(t[p].lazy) {
		t[p<<1].mx+=t[p].lazy;
		t[p<<1|1].mx+=t[p].lazy;
		t[p<<1].lazy+=t[p].lazy;
		t[p<<1|1].lazy+=t[p].lazy;
		t[p].lazy=0;
	}
}
void add(int x,int p,int v) {
	if(t[p].l==t[p].r) {
		t[p].mx=max(t[p].mx,v);
		return;
	}
	down(p);
	int mid=t[p<<1].r;
	if(mid>=x)add(x,p<<1,v);
	else add(x,p<<1|1,v);
	up(p);
}
int que(int l,int r,int p) {
	if(t[p].l==l&&t[p].r==r)return t[p].mx;
	down(p);
	int mid=t[p<<1].r;
	if(mid>=r)return que(l,r,p<<1);
	else if(mid<l)return que(l,r,p<<1|1);
	else return max(que(l,mid,p<<1),que(mid+1,r,p<<1|1));
}
void Add() {
	t[1].mx++,t[1].lazy++;
}
int main() {
	scanf("%s%s",S+1,T+1),ls=strlen(S+1),lt=strlen(T+1);
	for(i=1; i<=lt; i++) {
		if(!st[T[i]-'a'])st[T[i]-'a']=i;
		ed[T[i]-'a']=i;
	}
	build(1,lt,1);
	for(i=ls; i>0; i--) {
		if(st[S[i]-'a']) {
			res=que(1,st[S[i]-'a'],1)+1,add(ed[S[i]-'a'],1,res),ans=max(ans,res);
		} else {
			ans=max(ans,que(1,lt,1)+1),Add();
		}
	}
	printf("%d",ans);
	return 0;
}