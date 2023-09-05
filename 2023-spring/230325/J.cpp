#include<bits/stdc++.h>
using namespace std;
int n,x,y,i,s,t,re,l,r,tot,now,tot1;
double ans,res;
struct node {
	int l,r;
	bool operator<(const node&_)const {
		if(_.l==l)return _.r<r;
		return _.l>l;
	}
} q[2005],q1[2005],q2[2005];
void chk() {
	if(res==190)return;
	sort(q+1,q+tot+1);
	if(q[1].l==-180) {
		l=now=-180,r=q[1].r;
		int i;
		for(i=1; i<=tot; i++)
			if(now!=q[i].l) {
				if(r<q[i].l) {
					ans=r+0.5;
					break;
				}
				r=max(q[i].r,r),now=q[i].l;
			}
		if(i==tot+1&&r!=180)ans=179.5;
	} else ans=-180;//printf("!%.1f %d %d ",ans,l,r);
	if(l==-180&r==180)res=190;
	else res=ans;
}
void dfs(int x) {
	if(res==190)return;
	if(x==tot1+1) {
		for(int i=1; i<=tot; i++)q2[i]=q[i];
		chk();
		for(int i=1; i<=tot; i++)q[i]=q2[i];
		return;
	}
	int s=q1[x].l,t=q1[x].r;
	q[++tot]=(node) {
		s,t
	};
	dfs(x+1);
	tot--;
	q[++tot]=(node) {-180,s},q[++tot]=(node) {
		t,180
	};
	dfs(x+1);
	tot-=2;
}
int main() {
	scanf("%d",&n),res=-190;
	scanf("%d%d",&x,&y),s=re=y;
	for(i=1; i<=n; i++) {
		if(i<n)scanf("%d%d",&x,&y),t=y;
		else t=re;
		if(t<s)swap(s,t);
		if(t-s==s+180+180-t)q1[++tot1]=(node) {
			s,t
		};
		else if(t-s>s+180+180-t)q[++tot]=(node) {-180,s},q[++tot]=(node) {
			t,180
		};
		else q[++tot]=(node) {
			s,t
		};
		s=y;
	}
	if(tot1==3)res=190;
	else dfs(1);
	if(res==190)printf("yes\n");
	else printf("no %.1f\n",res);
	return 0;
}