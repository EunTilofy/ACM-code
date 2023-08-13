#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define N 30
#define LL long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
int rd() {
	int res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
	return res*f;
}
int n,m;
string s[N];
map<string,int>cnt1,cnt2;
map<string,string>tr;
int main() {
	n=rd();
	rep(i,1,n) cin>>s[i];
	string A,B,C;
	m=rd();
	while(m--) {
		cin>>A>>B>>C;
		if(C[0]=='c') cnt1[A]++;else cnt2[A]++;
		tr[A]=B;
	} 
	LL X=1,Y=1;
	rep(i,1,n) X*=cnt1[s[i]]+cnt2[s[i]],Y*=cnt1[s[i]];
	if(X==1) {
		rep(i,1,n) cout<<tr[s[i]]<<" ";
		if(Y) printf("correct");
		else printf("incorrect");
	}
	else {
		printf("%lld correct\n",Y);
		printf("%lld incorrect",X-Y);
	}
	return 0;
}