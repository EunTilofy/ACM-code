#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p=998244353;
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=(ll)res*a%p;
		a=(ll)a*a%p;
		b>>=1;
	}
	return res;
}
int C(int a,int b)
{
	if(a<b||b<0) return 0;
	int res=1;
	for(int i=1,j=a;i<=b;i++,j--)
	{
		res=(ll)res*j%p;
		res=(ll)res*ksm(i,p-2)%p;
	}
	return res;
}
int lucas(ll a,ll b)
{
	if(a<p && b<p) return C(a,b);
	return (ll)C(a%p,b%p)*lucas(a/p,b/p)%p;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,a,b,c,x,y;
	cin>>n>>m>>a>>b>>c>>x>>y;
	int res=0;
	for(int i=0;i<=a;i++)
		res=res+lucas(a,i)*lucas(c,x-i)*lucas(b+c-x+i,y)*lucas(n-x-y,m-x-y);
	cout<<res%p<<"\n";	
	return 0;
}

int 