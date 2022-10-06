#include<bits/stdc++.h>
using namespace std;
#define M 200005
int day[13][35],wek[13][35],n,m,t,i,j,h,tot,cnt,cal;
char s[100];
string name;
struct node {
	int y,r,s,f,name,id;
	bool operator<(const node&_)const {
		if(_.s==s&&_.r==r&&_.y==y)return _.f>f;
		if(_.r==r&&_.y==y)return _.s>s;
		if(_.y==y)return _.r>r;
		return _.y>y;
	}
	bool operator!=(const node&_)const {
		return _.y!=y||_.r!=r||_.s!=s||_.f!=f;
	}
} st,ed,now,nxt,z[M],zzz,zzzz,sttt,eddd;
set<node>ss;
set<node>::iterator it,it1;
struct Ti {
	int s,f;
	bool operator<=(const Ti&_)const {
		if(_.s==s)return _.f>=f;
		return _.s>s;
	}
	bool operator<(const Ti&_)const {
		if(_.s==s)return _.f>f;
		return _.s>s;
	}
	void chk() {
		while(f<0)s--,f+=60;
		while(f>=60)s++,f-=60;
	}
} ti[M][60],tim,stt,edd,zz,lim,v,iv,vvv;
map<string,int>id;
bool work(int y,int r) {
	return day[y][r]<6;
}
int r[]= {31,28,31,30,31,30,31,31,30,31,30,31};
void init() {
	int i,j,now=4;
	for(i=1; i<=12; i++)
		for(j=1; j<=r[i-1]; j++) {
			day[i][j]=now,wek[i][j]=cnt;
			now++;
			if(now>7)now=1,cnt++;
		}
}
void chg1(node &x) {
	x.y=(s[5]-'0')*10+s[6]-'0';
	x.r=(s[8]-'0')*10+s[9]-'0';
}
void chg2(node &x) {
	x.s=(s[0]-'0')*10+s[1]-'0';
	x.f=(s[3]-'0')*10+s[4]-'0';
}
void did(node now,node nxt) {
	int j,h;
	for(j=now.y; j<=nxt.y; j++)
		for(h=now.r; h<=nxt.r; h++) {
			if(j==nxt.y&&h==nxt.r)tim.s=nxt.s,tim.f=nxt.f;
			else tim.s=24,tim.f=0;
			edd=tim;
			if(j==now.y&&h==now.r)tim.s-=now.s,tim.f-=now.f,stt=(Ti) {
				now.s,now.f
			};
			else stt.f=stt.s=0;
			if(tim.f<0)tim.f+=60,tim.s--;
			vvv=ti[now.name][wek[j][h]];
			if(work(j,h)) {
				if(edd<=(Ti) {
				9,0
			}||(Ti) {
				18,0
			}<=stt)ti[now.name][wek[j][h]].s+=tim.s,ti[now.name][wek[j][h]].f+=tim.f;
				else {
					if(stt<=(Ti) {
					9,0
				}) {
						zz.s=9-stt.s,zz.f=-stt.f;
						if(zz.f<0)zz.f+=60,zz.s--;
						ti[now.name][wek[j][h]].s+=zz.s,ti[now.name][wek[j][h]].f+=zz.f;
					}
					if((Ti) {
					18,0
				}<=edd) {
						zz.s=edd.s-18,zz.f=edd.f;
						ti[now.name][wek[j][h]].s+=zz.s,ti[now.name][wek[j][h]].f+=zz.f;
					}
				}
			} else ti[now.name][wek[j][h]].s+=tim.s,ti[now.name][wek[j][h]].f+=tim.f;
			ti[now.name][wek[j][h]].chk();
			if(vvv<=lim&&lim<ti[now.name][wek[j][h]])cal++;
		}
}
void did2(node now,node nxt) {
	int j,h;
	for(j=now.y; j<=nxt.y; j++)
		for(h=now.r; h<=nxt.r; h++) {
			if(j==nxt.y&&h==nxt.r)tim.s=nxt.s,tim.f=nxt.f;
			else tim.s=24,tim.f=0;
			edd=tim;
			if(j==now.y&&h==now.r)tim.s-=now.s,tim.f-=now.f,stt=(Ti) {
				now.s,now.f
			};
			else stt.f=stt.s=0;
			if(tim.f<0)tim.f+=60,tim.s--;
			vvv=ti[now.name][wek[j][h]];
			if(work(j,h)) {
				if(edd<=(Ti) {
				9,0
			}||(Ti) {
				18,0
			}<=stt) {
					ti[now.name][wek[j][h]].s-=tim.s,ti[now.name][wek[j][h]].f-=tim.f;
				} else {
					if(stt<=(Ti) {
					9,0
				}) {
						zz.s=9-stt.s,zz.f=-stt.f;
						if(zz.f<0)zz.f+=60,zz.s--;
						ti[now.name][wek[j][h]].s-=zz.s,ti[now.name][wek[j][h]].f-=zz.f;
					}
					if((Ti) {
					18,0
				}<=edd) {
						zz.s=edd.s-18,zz.f=edd.f;
						ti[now.name][wek[j][h]].s-=zz.s,ti[now.name][wek[j][h]].f-=zz.f;
					}
				}
			} else ti[now.name][wek[j][h]].s-=tim.s,ti[now.name][wek[j][h]].f-=tim.f;
			ti[now.name][wek[j][h]].chk();
			if(lim<vvv&&ti[now.name][wek[j][h]]<=lim)cal--;
		}
}
void chk1(node &now) {
	if(now.y<st.y)now.y=st.y;
	if(now.y==st.y&&now.r<st.r)now.r=st.r;
	if(now.y==st.y&&now.r==st.r&&now.s<st.s)now.s=st.s;
	if(now.y==st.y&&now.r==st.r&&now.s==st.s&&now.f<st.f)now.f=st.f;
	if(now.y>ed.y)now.y=ed.y;
	if(now.y==ed.y&&now.r>ed.r)now.r=ed.r;
	if(now.y==ed.y&&now.r==ed.r&&now.s>ed.s)now.s=ed.s;
	if(now.y==ed.y&&now.r==ed.r&&now.s==ed.s&&now.f>ed.f)now.f=ed.f;
}
int main() {
//	freopen("schedule.in", "r", stdin);
//	freopen("schedule.out", "w", stdout);
	init();
	scanf("%d%d%d",&n,&m,&t),lim.s=t;
	scanf("%s",s),chg1(st),scanf("%s",s),chg2(st);
	scanf("%s",s),chg1(ed),scanf("%s",s),chg2(ed);
	for(i=1; i<=n; i++) {
		scanf("%s",s),chg1(now),scanf("%s",s),chg2(now),chk1(now);
		cin>>name;
		if(!id[name])id[name]=++tot;
		now.name=id[name],z[i]=now,ss.insert(now);//printf("%d %d\n",now.s,now.f);
	}
	for(i=1; i<=n; i++) {
		if(i==n)nxt=ed;
		else nxt=z[i+1];
		now=z[i];
		did(now,nxt);
	}
//	printf("%d",cal);
	now=st;
	for(i=1; i<=m; i++) {
		scanf("%s",s),chg1(nxt),scanf("%s",s),chg2(nxt),chk1(nxt);
		chk1(nxt);
		if(now!=nxt) {
			if(cal)iv.s+=nxt.s-now.s,iv.f+=nxt.f-now.f,iv.chk();
			else v.s+=nxt.s-now.s,v.f+=nxt.f-now.f,v.chk();
			now=nxt;
		}
		scanf("%s",s),chg1(sttt),scanf("%s",s),chg2(sttt),chk1(sttt);
		scanf("%s",s),chg1(eddd),scanf("%s",s),chg2(eddd),chk1(eddd);
		cin>>name;
		if(!id[name])id[name]=++tot;
		sttt.name=eddd.name=id[name];
		it=ss.upper_bound(sttt),it--;
		did(sttt,eddd);
		while(1) {
//			printf("%d ",cal);
			zzz=*it;
			it1=it,it1++;
			if(it1==ss.end())zzzz=ed;
			else zzzz=*it1;
			did2(zzz,zzzz);
			if(zzz<sttt)did(zzz,sttt),it=it1;
			else ss.erase(it),it=it1;
//			printf("%d ",cal);
//			printf("!%d %d %d %d %d %d\n",eddd.s,eddd.f,zzzz.s,zzzz.f,ed.s,ed.f);
			if(eddd<zzzz) {
				eddd.name=zzz.name,ss.insert(eddd),did(eddd,zzzz);
				break;
			} else if(!(eddd!=zzzz))break;
		}
		ss.insert(sttt);
//		printf("!");
	}
	nxt=ed;
	if(cal)iv.s+=nxt.s-now.s,iv.f+=nxt.f-now.f,iv.chk();
	else v.s+=nxt.s-now.s,v.f+=nxt.f-now.f,v.chk();
	printf("%.7f\n",(60.0*v.s+v.f)/(60*(v.s+iv.s)+v.f+iv.f));
	return 0;
}
/*
2 1 2
2009-12-07 09:00 2009-12-08 22:00
2009-12-07 08:00 Vasya
2009-12-08 14:00 Vanya
2009-12-07 15:00 2009-12-07 16:00 2009-12-07 20:00 Vasya

2 1 2
2009-12-07 09:00 2009-12-07 22:00
2009-12-07 08:00 Vasya
2009-12-07 14:00 Vanya
2009-12-07 15:00 2009-12-07 20:00 2009-12-07 23:00 Vasya
*/