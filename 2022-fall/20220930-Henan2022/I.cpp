#include<bits/stdc++.h>
using namespace std;
int n,m,q,h,k,i,j,ti,fl,cnt,jin[55],chu[55],now[55];
struct node {
	int id,ty,x,y,z;
} e[300];
struct ed {
	int x,y,z;
} ed[55];
struct st {
	int t,ty,x,y,z;
} st[55];
//bool cmp(st x,st y) {
//	if(x.t<y.t)return 1;
//	if(x.id<y.id)return 1;
//	return 0;
//}
void solve() {
	ti++;
	for(i=1; i<=k; i++)
		for(j=1; j<=q; j++)
			if(now[j]&&st[j].t==ti&&st[j].ty==e[i].ty&&st[j].x==e[i].x&&st[j].y==e[i].y&&st[j].z==e[i].z) {
				if(st[j].ty==0&&st[j].x==ed[j].x||st[j].ty==1&&st[j].y==ed[j].y||st[j].ty==2&&st[j].z==ed[j].z)
					chu[j]=i,now[j]=0;
			}
	for(i=1; i<=k; i++)
		for(j=1; j<=q; j++)
			if(!now[j]&&!chu[j]&&st[j].t==ti&&st[j].ty==e[i].ty&&st[j].x==e[i].x&&st[j].y==e[i].y&&st[j].z==e[i].z) {
				jin[j]=now[j]=i;
			}
//	printf("!%d\n",ti);
//	for(i=1; i<=q; i++)printf("!%d %d %d %d %d %d %d %d %d\n",i,jin[i],chu[i],now[i],st[i].x,st[i].y,st[i].z,st[i].t,st[i].ty);
//	printf("!!\n");
//	for(i=1; i<=k; i++)printf("!%d %d %d %d %d\n",i,e[i].x,e[i].y,e[i].z,e[i].ty);
//	printf("\n");
	for(j=1; j<=k; j++) {
		for(i=1; i<=q; i++) {
			if(chu[i]==j) {
				printf("[%ds] Person %d OUT Elevator %d at (%d, %d, %d)\n",ti,i,j,st[i].x,st[i].y,st[i].z);
				if(st[i].ty==0) {
					st[i].ty++;
					if(st[i].y==ed[i].y)st[i].ty++;
					if(st[i].y==ed[i].y&&st[i].z==ed[i].z)cnt++,st[i].t=-1;
				} else if(st[i].ty==1) {
					st[i].ty++;
					if(st[i].z==ed[i].z)st[i].t=-1,cnt++;
				} else {
					st[i].t=-1,cnt++;
				}
				chu[i]=0;
			}
		}
		for(i=1; i<=q; i++) {
			if(jin[i]==j) {
				printf("[%ds] Person %d IN Elevator %d at (%d, %d, %d)\n",ti,i,j,st[i].x,st[i].y,st[i].z);
				jin[i]=0;
			}
			if(now[i]==j) {
				if(st[i].ty==0) {
					st[i].x=st[i].x%n+1;
				} else if(st[i].ty==1) {
					st[i].y=st[i].y%m+1;
				} else {
					st[i].z=st[i].z%h+1;
				}
			}
		}
	}
	for(i=1; i<=q; i++)if(st[i].t==ti)st[i].t++;
	for(i=1; i<=k; i++) {
		if(e[i].ty==0)e[i].x=e[i].x%n+1;
		if(e[i].ty==1)e[i].y=e[i].y%m+1;
		if(e[i].ty==2)e[i].z=e[i].z%h+1;
	}
}
int main() {
	scanf("%d%d%d%d",&n,&m,&h,&k);
	for(i=1; i<=k; i++)scanf("%d%d%d%d",&e[i].ty,&e[i].x,&e[i].y,&e[i].z),e[i].id=i;
	scanf("%d",&q);
	for(i=1; i<=q; i++) {
		scanf("%d%d%d%d%d%d%d",&st[i].t,&st[i].x,&st[i].y,&st[i].z,&ed[i].x,&ed[i].y,&ed[i].z);
		if(st[i].x!=ed[i].x)st[i].ty=0;
		else if(st[i].y!=ed[i].y)st[i].ty=1;
		else if(st[i].z!=ed[i].z)st[i].ty=2;
		else cnt++,st[i].t=-1;
	}
	ti=-1;
	while(cnt<q) {
		solve();
//		if(ti==30)break;
	}
	return 0;
}
/*
2 2 2
12
0 1 1 1
0 1 1 2
0 1 2 1
0 1 2 2
1 1 1 1
1 1 1 2
1 2 1 1
1 2 1 2
2 1 1 1
2 1 2 1
2 2 1 1
2 2 2 1
3
1 2 2 2 1 1 1
3 1 1 2 2 2 1
50 2 1 2 1 2 1
*/