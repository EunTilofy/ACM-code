#include<bits/stdc++.h>
using namespace std;
#define M 100005
int m,n,i,j,k,c,r[M<<1],h[M<<1],id[M<<1],tot,nx[M<<1],mark[M],x,now[5],mk[M],ti,hh;
bool ms[M],fl,f;
void add(int x,int y,int i) {
	r[++tot]=y,nx[tot]=h[x],h[x]=tot,id[tot]=i;
}
void adds(int x,int y,int i) {
	add(x,y,i),add(y,x,i);
}
struct node {
	int x,y;
} a[M];
void dfs(int x) {
	if(fl)return;
	mk[x]=ti;
	if(x==a[now[j]].y) {
		fl=1;
		return;
	}
	for(int i=h[x]; i; i=nx[i])if(mark[id[i]]!=hh&&mk[r[i]]!=ti)dfs(r[i]);
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
int main() {
//	freopen("disconnected.in", "r", stdin);
//	freopen("disconnected.out", "w", stdout);
	n=read(),m=read();
	for(i=1; i<=m; i++)a[i].x=read(),a[i].y=read(),adds(a[i].x,a[i].y,i);
	k=read();
	for(i=1; i<=k; i++) {
		c=read(),f=1,hh=i;
		for(j=1; j<=c; j++) {
			x=read(),mark[x]=i,now[j]=x;
			if(ms[x])f=0;
		}
		for(j=1; j<=c&&f; j++) {
			ti++,fl=0,dfs(a[now[j]].x);
			if(mk[a[now[j]].y]!=ti)f=0;
		}
		if(c==1&&!f)ms[now[1]]=1;
		if(f)printf("Connected\n");
		else printf("Disconnected\n");
	}
	return 0;
}