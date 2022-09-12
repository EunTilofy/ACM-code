#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC target("fma","avx2")
#pragma GCC target("xop","fma4")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include "bits/stdc++.h"
using namespace std;
typedef unsigned ui;
typedef unsigned long long ull;
#define all(x) (x).begin(),(x).end()
const int N=2e5+5;
const ull b1=2e5+3,b2=2e5+9;
const ui p1=2'034'452'107,p2=2'013'074'419;
ull m1[N],m2[N],s1[N],s2[N],dis[N],d1[N],d2[N],sd1[N][27],sd2[N][27];
int a[N],rk[N][26],kr[N][26],app[N][26],tap[N][26];
int n;
ull gethash(const int &l,const int &r)
{
	int i=upper_bound(tap[l],tap[l]+26,r)-tap[l];
	return (s1[r]+p1+sd1[l][i]-s1[l-1])*m1[N-l]%p1<<32|(s2[r]+p2+sd2[l][i]-s2[l-1])*m2[N-l]%p2;
}
int getv(int l,int r)
{
	return rk[l][a[r]];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int i,j;
	string S;
	cin>>n>>S;
	for (i=1; i<=n; i++) a[i]=S[i-1]-'a';
	vector<int> lst(26);
	for (i=1; i<=n; i++)
	{
		dis[i]=i-lst[a[i]];
		lst[a[i]]=i;
	}
	m1[0]=m2[0]=1;
	for (i=1; i<N; i++) m1[i]=m1[i-1]*b1%p1,m2[i]=m2[i-1]*b2%p2;
	for (i=1; i<=n; i++) s1[i]=(s1[i-1]+dis[i]*m1[i])%p1,s2[i]=(s2[i-1]+dis[i]*m2[i])%p2;
	for (i=1; i<=n; i++) d1[i]=dis[i]*m1[i]%p1,d2[i]=dis[i]*m2[i]%p2;
	fill(all(lst),n+1);
	for (i=n; i; i--)
	{
		lst[a[i]]=i;
		vector<pair<int,int>> v(26);
		for (j=0; j<26; j++) v[j]={lst[j],j};
		sort(all(v));
		for (j=0; j<26; j++) kr[i][j]=v[j].second,rk[i][v[j].second]=j,app[i][j]=lst[j],tap[i][j]=v[j].first;
		// for (j=0; j<26; j++) cerr<<lst[j]<<" \n"[j==25];
	}
	for (i=1; i<=n; i++) for (j=0; j<26; j++)
	{
		sd1[i][j+1]=(sd1[i][j]+p1-d1[app[i][kr[i][j]]])%p1;
		sd2[i][j+1]=(sd2[i][j]+p2-d2[app[i][kr[i][j]]])%p2;
	}
	vector<int> id(n);
	iota(all(id),1);
	sort(all(id),[&](const int &a,const int &b)
		{
			int l=0,r=min(n-a,n-b),mid;
			while (l<r)
			{
				mid=l+r+1>>1;
				if (gethash(a,a+mid)==gethash(b,b+mid)) l=mid; else r=mid-1;
			}
			if (l==min(n-a,n-b)) return a>b;
			return getv(a,a+l+1)<getv(b,b+l+1);
		});
	for (i=0; i<n; i++) cout<<id[i]<<" \n"[i+1==n];
}
