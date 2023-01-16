#include<bits/stdc++.h>
using namespace std;
#define M 2000005
int L,R,mid,ans,i,n,t,A[M],B[M],h[M],zh[M], nx[M<<1],tot,r[M<<1],now[M],si;//,deg[M],que[M],ll,rr;
struct node {
	int a,b;
	bool operator<(const node&_)const {
		return _.a>a;
	}
} w[M];
void add(int x,int y) {
	r[++tot]=y,nx[tot]=h[x],h[x]=tot;
}
void adds(int x,int y) {
	add(x,y),add(y,x);
}
bool chk(int n) {
	vector<int> mk(n + 1);
	for(int i = 1; i <= n; ++i) {
		if(zh[i]) mk[i] = 1;
	}
	for(int u = n + 1; u <= si; ++u) {
		for(int i = h[u]; i; i = nx[i]) {
			int v = r[i];
			if(v <= n) {
//				cerr << "v = " << v << "\n";
				mk[v] = 1;
			}
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; ++i) if(mk[i]) q.push(i);
//	cerr << "qqq=" << q.size() << "\n";
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = h[u]; i; i = nx[i]) {
			int v = r[i];
			if(v <= n && !mk[v]) q.push(v), mk[v] = 1;
		}
	}
	vector<int> d(n + 1);
	for(int u = 1; u <= n; ++u) {
		if(mk[u]) continue;
		for(int i = h[u]; i; i = nx[i]) {
			int v = r[i];
			if(v <= n && !mk[v]) d[u]++;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(!d[i]) {
			if(!mk[i]) return false;
			continue;
		}
		if(d[i] == 1) q.push(i);
	}
	while(q.size()) {
		int u = q.front(); q.pop();
//		cerr << "u = " << u << "\n";
		mk[u] = 1;
		for(int i = h[u]; i; i = nx[i]) {
			int v = r[i];
			if(mk[v]) continue;
			d[v]--;
			if(!d[v]) return false;
			if(d[v] == 1) q.push(v);
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>t;
	for(i=1; i<=t; i++) {
		cin>>A[i]>>B[i];
		if(A[i]>B[i])swap(A[i],B[i]);
		now[++si]=A[i],now[++si]=B[i];
	}
	sort(now+1,now+si+1),si=1;
	for(i=2; i<=2*t; i++)if(now[i]!=now[i-1])now[++si]=now[i];
	for(i=1; i<=si; i++)
		if(now[i]!=i) {
			R=i-1;
			break;
		}
	if(i>si)R=now[si];
	for(i=1; i<=t; i++) {
		w[i].a=lower_bound(now+1,now+si+1,A[i])-now,w[i].b=lower_bound(now+1,now+si+1,B[i])-now;
		adds(w[i].a, w[i].b);
		if(w[i].a == w[i].b) zh[w[i].a] = 1;
//		cout << "!! "<< w[i].a << " " << w[i].b << "\n";
	}
//	sort(w+1,w+t+1);
//	cerr << L << " " << R << "\n";
	while(L<=R) {
		mid=L+R>>1;
		if(chk(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
//	cerr << chk(4) << "\n";
	cout << ans + 1 << "\n";
	return 0;
}