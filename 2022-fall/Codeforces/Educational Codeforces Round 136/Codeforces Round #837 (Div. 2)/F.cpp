#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

ull seed=time(0);
inline ull rd(){
	seed^=seed<<17,seed^=seed>>5,seed^=seed<<23;
	return seed;
}

const int N=2e5+3,V=N*30;
int n,m,q,l,r,a[N],buc[N],ans;
inline int find(int x){return lower_bound(buc+1,buc+m+1,x)-buc;}
ull v[N];

int rt[N],lc[V],rc[V],pos,tot,L,R;
ull s[V],val;
void upd(int& x,int y,int l,int r){
	x=++tot,s[x]=s[y]^val;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos<=mid)upd(lc[x],lc[y],l,mid),rc[x]=rc[y];
	else upd(rc[x],rc[y],mid+1,r),lc[x]=lc[y];
}
ull qry(int x,int l,int r){
	if(!x||l>R||r<L)return 0;
	if(l>=L&&r<=R)return s[x];
	int mid=(l+r)>>1;
	return qry(lc[x],l,mid)^qry(rc[x],mid+1,r);
}

vector<int> pp[N];
inline ull chk(int x){
	return qry(rt[x],1,n);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],buc[i]=a[i];
	sort(buc+1,buc+n+1),m=unique(buc+1,buc+n+1)-buc-1;
	for(int i=1;i<=n;++i)a[i]=find(a[i]),pp[a[i]].push_back(i);
	for(int i=1;i<=m;++i){
		val=v[i]=rd(),rt[i]=rt[i-1];
		for(int x:pp[i])pos=x,upd(rt[i],rt[i],1,n);
	}
	cin>>q;
	while(q--){
		cin>>L>>R,L^=ans,R^=ans;
		//cout<<L<<' '<<R<<'\n';
		int u=1,d=m,mid;
		ans=0;
		while(u<=d){
			mid=(u+d)>>1;
			//cout<<"chk: "<<mid<<' '<<L<<' '<<R<<' '<<chk(mid)<<'\n';
			if(chk(mid))ans=mid,d=mid-1;
			else u=mid+1;
		}
		ans=buc[ans];
		cout<<ans<<'\n';
	}
}