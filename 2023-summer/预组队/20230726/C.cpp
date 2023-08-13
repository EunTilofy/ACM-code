#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define N 32
#define inf 0x3f3f3f3f3f3f3f3f
#define LL long long
#define int LL
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
int rd() {
	int res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
	return res*f;
}
int a[5][5],pos[17][2];
int dp[17][N*2+1][N*2+1];
int prod(int x,int y,int xx,int yy) {
	return x*yy-xx*y;
}
int gets(int x,int y,int A,int B,int xx,int yy,int C,int D) {
	int delx=xx-x,dely=yy-y;
	if(prod(A,B,C,D)==0) {
		if(prod(x,y,A,B)!=prod(xx,yy,A,B)) return 2;
		bool tmp1=delx?delx*A>0:dely*B>0;
		bool tmp2=delx?delx*C>0:dely*D>0;
		return (!tmp1)+(!tmp2);
	}
	double X,Y;
	if(A!=0) {
		X=((yy-y)*A*C-A*D*xx+B*C*x)*1.0/(B*C-A*D);
		Y=1.0*B/A*(X-x)+y;
	}
	if(B!=0) {
		Y=((xx-x)*B*D-B*C*yy+A*D*y)*1.0/(A*D-B*C);
		X=1.0*A/B*(Y-y)+x;
	}
	if((X-x)*A<0||(Y-y)*B<0) return 2;
	if((xx-X)*C<0||(yy-Y)*D<0) return 2;
	return 1;
}
signed main() {
//	cerr<<"gets "<<gets(1,1,-1,-1,1,2,0,-1)<<endl;return 0;
//	rep(x,1,2) rep(y,1,2) rep(A,-1,1) rep(B,-1,1) if(A||B) rep(xx,1,2) rep(yy,1,2) if(xx!=x||yy!=y) rep(C,-1,1) rep(D,-1,1) if(C||D) 
//		cerr<<"FUCK "<<gets(x,y,A,B,xx,yy,C,D)<<endl;return 0;
		
	rep(i,1,4) rep(j,1,4) a[i][j]=rd(),pos[a[i][j]][0]=i,pos[a[i][j]][1]=j;
	rep(num,1,16) rep(i,0,2*N) rep(j,0,2*N) dp[num][i][j]=inf;
	rep(i,-N,N) rep(j,-N,N) if(i||j) dp[1][i+N][j+N]=1;
	
	rep(i,1,15) rep(A,0,2*N) rep(B,0,2*N) if((A!=N||B!=N)&&dp[i][A][B]!=inf) {
		rep(C,0,2*N) rep(D,0,2*N) if(C!=N||D!=N) {
			dp[i+1][C][D]=min(dp[i+1][C][D],dp[i][A][B]+gets(pos[i][0],pos[i][1],A-N,B-N,pos[i+1][0],pos[i+1][1],C-N,D-N));
		}
	}
	int ans=inf;
	rep(A,0,2*N) rep(B,0,2*N) ans=min(ans,dp[16][A][B]);
	printf("%d",ans);
	return 0;
}