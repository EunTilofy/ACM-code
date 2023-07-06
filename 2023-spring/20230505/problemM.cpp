#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

const int N=10003;
int n;
struct pnt{
	ll x,y;
	pnt(){}
	pnt(ll x,ll y):x(x),y(y){}
	pnt operator-(const pnt& p)const{
		return pnt(x-p.x,y-p.y);
	}
}a[N];
inline ll dis(int i,int j){
	return (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
}
inline ll crs(pnt a,pnt b){
	return a.x*b.y-a.y*b.x;
}
int o[N];
ll f[N],g[N];
inline ll qryl(int l,int d,int i){
	int p=o[i];
	if(l<=p&&p<=l+d||l<=p+n&&p+n<=l+d)return dis(i,p);
	return max(dis(i,(l+d)%n),dis(i,l));
}
inline ll qryr(int r,int d,int i){
	int p=o[i];
	if(r-d<=p&&p<=r||r-d+n<=p&&p<=r+n)return dis(i,p);
	return max(dis(i,r),dis(i,(r-d+n)%n));
}
void solve(){
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i].x>>a[i].y,a[i+n]=a[i];
	for(int i=0;i<n;++i){
		o[i]=i;
		for(int j=1;j<n;++j)
			if(dis(i,(i+j)%n)>dis(i,o[i]))o[i]=(i+j)%n;
		o[i]%=n;
	}
	ll ans=4e18;
	for(int i=0;i<n;++i){
		f[0]=0;
		for(int j=1;j<n;++j)
			f[j]=max(f[j-1],qryl(i,j-1,(i+j)%n));
		g[0]=0;
		for(int j=1;j<n;++j)
			g[j]=max(g[j-1],qryr(i,j-1,(i-j+n)%n));
		int l=2,r=n-2;
		while(crs(a[i+l]-a[i],a[i+1]-a[i])==0)++l;
		while(crs(a[i+r]-a[i],a[i+n-1]-a[i])==0)--r;
		for(int j=l;j<=r;++j)ans=min(ans,f[j]+g[n-j]);
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}