#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),i##z=(b);i<=i##z;i++)
#define ROF(i,a,b) for(int i=(a),i##z=(b);i>=i##z;i--)
#define temT template<typename T>
#define temT12 template<typename T1,typename T2>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=10,L=int(1e6)+10;

int n; int a[N],s[N],b[N],x=-1,y=-1; int f[L],g[L];

int F(int x[N]){
	int res=0;
	FOR(i,0,n-1) res+=(x[i]-1)*s[i];
	return res+1;
}

void dfs0(int c[N],int p,int t){
	if(p==n){
		if(t&1){
			FOR(i,1,a[y]) FOR(j,1,a[x]){
				c[y]=i,c[x]=j; int p=F(c);
				if(i==1){
					if(j==1) f[p]=y,g[p]=1;
					else f[p]=x,g[p]=-1;
				}else if(i==2 && a[y]>2){
					if(j==1) f[p]=y,g[p]=1;
					else if(j==a[x]) f[p]=y,g[p]=-1;
					else f[p]=j&1?y:x,g[p]=1;
				}else if(i<a[y] && a[y]>3){
					f[p]=y,g[p]=j&1?1:-1;
				}else{
					f[p]=j&1?x:y,g[p]=j&1?1:-1;
				}
			}
		}else{
			FOR(i,1,a[y]) FOR(j,1,a[x]){
				c[y]=i,c[x]=j; int p=F(c);
				if(i==1){
					if(j<a[x]) f[p]=x,g[p]=1;
					else f[p]=y,g[p]=1;
				}else if(i==2 && a[y]>2){
					if(j==1) f[p]=y,g[p]=-1;
					else if(j==a[x]) f[p]=y,g[p]=1;
					else f[p]=j&1?x:y,g[p]=j&1?-1:1;
				}else if(i<a[y] && a[y]>3){
					f[p]=y,g[p]=j&1?-1:1;
				}else{
					f[p]=j&1?y:x,g[p]=-1;
				}
			}
		}
		return ;
	}
	if(p==x || p==y)
		dfs0(c,p+1,t);
	else
		FOR(i,1,a[p])
			c[p]=i,dfs0(c,p+1,t+i);
}
void connect(){
	int c[N],c1[N]; FOR(i,0,n-1) c[i]=1;
	FOR(i,0,n-1) if(i!=x && i!=y) FOR(j,1,a[i]-1){
		int p=F(c),p1;
		FOR(i,0,n-1) c1[i]=c[i]; c1[i]=c[i]+1,c1[f[p]]+=g[p],p1=F(c1);
		f[p]=i,g[p]=1; f[p1]=i,g[p1]=-1;
//		if(i&1) c[f[p]]+=g[p],c[i]++;
//		else{ c[i]++; p=F(c); c[f[p]]+=g[p]; }
		c[f[p]]+=g[p],c[i]++;
	}
}
void dfs(int c[N]){
	static int p1=-1;
	int p=F(c); if(p==p1) return ; if(p1==-1) p1=F(b);
	cout<<f[p]+1<<" "<<(g[p]>0?'+':'-')<<"\n";
	c[f[p]]+=g[p]; dfs(c);
}

int main(){
	cin>>n; FOR(i,0,n-1) cin>>a[i]; FOR(i,0,n-1) cin>>b[i];
	s[n-1]=1; ROF(i,n-2,0) s[i]=s[i+1]*a[i+1];
	FOR(i,0,n-1) if(a[i]%2==0) x=(x==-1 || a[i]>a[x])?i:x;
	if(x==-1){ cout<<"No"; return 0; } cout<<"Yes\n";
	FOR(i,0,n-1) if(i!=x) y=(y==-1 || a[i]>a[y])?i:y;
	
	int c[N];
	FOR(i,0,n-1) c[i]=1; dfs0(c,0,0);
	connect(); dfs(b);
	return 0;
}