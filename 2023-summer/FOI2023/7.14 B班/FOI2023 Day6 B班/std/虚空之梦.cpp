#include<bits/stdc++.h>
using namespace std;
typedef unsigned int u32;

const int N=2e5+10;
int n,m,K;
u32 c[11][11],a[N],s[N],ss[N][11],pre[N][11],ans=0;
inline int id(int i,int j){
	if(!i||!j)return 0;
	return (i-1)*m+j;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>K;
	if(n<m){
		for(int i=1;i<=n*m;++i)cin>>a[i];
	}else{
		swap(n,m);
		for(int j=1;j<=m;++j)
			for(int i=1;i<=n;++i)
				cin>>a[id(i,j)];
	}
	for(int i=0;i<=K;++i){
		c[i][0]=1;
		for(int j=1;j<=i;++j)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s[id(i,j)]=s[id(i-1,j)]+a[id(i,j)];
	for(int l=1;l<=n;++l)
		for(int r=l;r<=n;++r){
			pre[0][0]=1;
			for(int i=1;i<=m;++i){
				ss[i][0]=1;
				ss[i][1]=ss[i-1][1]+s[id(r,i)]-s[id(l-1,i)];
				for(int k=2;k<=K;++k)ss[i][k]=ss[i][k-1]*ss[i][1];
				for(int k=0;k<=K;++k)pre[i][k]=pre[i-1][k]+ss[i][k];
			}
			for(int k=0;k<=K;++k){
				u32 tmp=0;
				for(int i=1;i<=m;++i)
					tmp+=pre[i-1][k]*ss[i][K-k];
				ans+=tmp*(k&1?-c[K][k]:c[K][k]);
			}
		}
	cout<<ans<<endl;
}