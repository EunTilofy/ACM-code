#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define N 1000010
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
int rd() {
	int res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
	return res*f;
}
int n,a[N],f[N]; 
int main() {
	n=rd();
	if(n<=2) printf("1");
	else printf("%d",n-2); 
	return 0;
}