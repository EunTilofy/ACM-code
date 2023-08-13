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
int n,a[N],b[N],c[N],tot;
unordered_map<int,int>mp;
vector<int>G[N];int cnt[N];
int main() {
	n=rd();
	rep(i,1,n) a[i]=rd(),b[i]=a[i];
	sort(b+1,b+n+1);
	rep(i,1,n) if(b[i]!=b[i-1]) mp[b[i]]=++tot;
	rep(i,1,n) c[i]=mp[a[i]];
	int nn=n;n=0;rep(i,1,nn) if(c[i]!=c[i-1]) a[++n]=c[i];
	rep(i,1,n) if(a[i]+1==a[i+1]) G[a[i]].push_back(i);
	rep(i,1,n) cnt[a[i]]++;
	
//	rep(i,1,n) cerr<<a[i]<<" ";
	
	int res=0,pre=-1;
	rep(i,1,tot) {
		vector<int>tmp;
		for(auto x:G[i]) if(x!=pre+1||cnt[i]==1) tmp.push_back(x);
		if(tmp.empty()) {pre=-1;continue;}
		if(tmp.size()==1) {res++;pre=tmp[0];continue;}
		res++,pre=-1;
//		cerr<<i<<" "<<res<<endl;
	}
	printf("%d",n-1-res);
	return 0;
}