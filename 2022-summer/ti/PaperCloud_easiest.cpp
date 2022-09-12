#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN=1e5+5;
int n,m,a[MN];
int b[MN],c[MN][20],d[MN],tp;
int ins(int j)
{
	while(a[j]>a[d[tp]]&&tp>0)tp--;
	d[tp+1]=j;return d[tp++];
}
int cal1(int l,int r)
{
	if(l==1)return 0;
	int i,x=l-1,ans=0;
	for(i=19;~i;--i)if(c[x][i]>0&&c[x][i]<=r)
		ans+=(1<<i),x=c[x][i];
	return ans;
}
ll ans[MN];
int main()
{
	n=read(),m=read();
	reg int i,j;a[0]=a[n+1]=n+1;
	for(i=1;i<=n;++i)a[i]=read();
	for(d[tp=1]=0,i=1;i<=n;++i)b[i]=ins(i);
	for(d[tp=1]=n+1,i=n;i;--i)c[i][0]=ins(i);
	for(i=1;i<20;++i)for(j=1;j<=n;++j)
		c[j][i]=c[c[j][i-1]][i-1];
	int l1,r1,l2,r2;
	for(i=1;i<=m;++i)
	{
		l1=read(),r1=read(),l2=read(),r2=read();
		ans[i]=r1-l1-r2+l2-cal1(r2+1,r1);
	}
	for(i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}
