#include<bits/stdc++.h>
using namespace std;
int n,m,q,h,k,i,j,ti,fl,ss[55][3],mark[3][10][10][10],cnt,now[55],mk[55];
struct node {
	int id,ty,x,y,z;
} e[300];
struct ed {
	int x,y,z;
} ed[55];
struct st {
	int t,x,y,z;
} st[55];
//bool cmp(st x,st y) {
//	if(x.t<y.t)return 1;
//	if(x.id<y.id)return 1;
//	return 0;
//}
void solve() {
	ti++;
	for(j=1; j<=k; j++) {
		for(i=1; i<=q; i++) {
//			if(i==2&&ti==4)printf("!");
//			if(i==2&&ti==12)printf("%d %d\n",j,st[i].t);
			if(st[i].t==ti) {
				if(now[i]==j) {
					if(st[i].x==ed[i].x&&ss[i][0]) {
						mk[i]=ti;
						continue;
					}
					if(st[i].y==ed[i].y&&ss[i][1]) {
						mk[i]=ti;
						continue;
					}
					if(st[i].z==ed[i].z&&ss[i][2]) {
						mk[i]=ti;
						continue;
					}
				}
			}
		}
	}
	for(j=1; j<=k; j++) {
		mark[e[j].ty][e[j].x][e[j].y][e[j].z]=ti;
		for(i=1; i<=q; i++) {
//			if(i==2&&ti==4)printf("!");
//			if(i==2&&ti==12)printf("%d %d\n",j,st[i].t);
			if(st[i].t==ti) {
				if(now[i]==j) {
					if(st[i].x==ed[i].x&&ss[i][0]) {
						printf("[%ds] Person %d OUT Elevator %d at (%d, %d, %d)\n",ti,i,j,st[i].x,st[i].y,st[i].z);
						ss[i][0]=0;
						st[i].t++;
						if(st[i].y==ed[i].y&&st[i].z==ed[i].z)cnt++,st[i].t=-1;
						continue;
					}
					if(st[i].y==ed[i].y&&ss[i][1]) {
						printf("[%ds] Person %d OUT Elevator %d at (%d, %d, %d)\n",ti,i,j,st[i].x,st[i].y,st[i].z);
						ss[i][1]=0;
						st[i].t++;
						if(st[i].z==ed[i].z)st[i].t=-1,cnt++;
						continue;
					}
					if(st[i].z==ed[i].z&&ss[i][2]) {
						printf("[%ds] Person %d OUT Elevator %d at (%d, %d, %d)\n",ti,i,j,st[i].x,st[i].y,st[i].z);
						ss[i][2]=0;
						st[i].t=-1,cnt++;
						continue;
					}
				}
				if(mk[i]!=ti) {
					fl=0;
					if(st[i].x!=ed[i].x) {
//					printf("!%d\n",i);
						if(mark[0][st[i].x][st[i].y][st[i].z]==ti) {
//					printf("!!%d\n",i);
							if(!ss[i][0])printf("[%ds] Person %d IN Elevator %d at (%d, %d, %d)\n",ti,i,j,st[i].x,st[i].y,st[i].z);
							st[i].x=st[i].x%n+1,fl=1,ss[i][0]++,now[i]=j;
						}
					} else if(st[i].y!=ed[i].y) {
						if(mark[1][st[i].x][st[i].y][st[i].z]==ti) {
							if(!ss[i][1])printf("[%ds] Person %d IN Elevator %d at (%d, %d, %d)\n",ti,i,j,st[i].x,st[i].y,st[i].z);
							st[i].y=st[i].y%m+1,fl=1,ss[i][1]++,now[i]=j;
						}
					} else {
						if(mark[2][st[i].x][st[i].y][st[i].z]==ti) {
							if(!ss[i][2])printf("[%ds] Person %d IN Elevator %d at (%d, %d, %d)\n",ti,i,j,st[i].x,st[i].y,st[i].z);
							st[i].z=st[i].z%h+1,fl=1,ss[i][2]++,now[i]=j;
						}
					}
					if(fl)st[i].t++;
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
//		printf("%d %d %d %d %d\n",ti+1,i,e[i].x,e[i].y,e[i].z);
}
int main() {
	scanf("%d%d%d%d",&n,&m,&h,&k);
	for(i=1; i<=k; i++)scanf("%d%d%d%d",&e[i].ty,&e[i].x,&e[i].y,&e[i].z),e[i].id=i;
	scanf("%d",&q);
	for(i=1; i<=q; i++) {
		scanf("%d%d%d%d%d%d%d",&st[i].t,&st[i].x,&st[i].y,&st[i].z,&ed[i].x,&ed[i].y,&ed[i].z);
		if(st[i].x!=ed[i].x);
		else if(st[i].y!=ed[i].y);
		else if(st[i].z!=ed[i].z);
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
4
1 2 2 2 1 1 1
3 1 1 2 2 2 1
50 2 1 2 1 2 1
1 2 2 2 2 2 2
*/