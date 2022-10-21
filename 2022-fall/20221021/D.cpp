#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int L;
int a[1005], b[1005], id[1005];
long long f[1005][2005];
bool cmp(int x, int y) {return a[x]<a[y];}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin>>T;
	for(int e=1; e<=T; ++e) {
		memset(f, 0, sizeof f);
		cin>>n;
		cin>>L;
		for(int i = 1; i <= n; ++i) id[i]=i, cin>>a[i]>>b[i];
		std::sort(id+1,id+n+1,cmp);
		
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j<=L; ++j) {
				f[i][j] = f[i-1][j];
				if(j>=a[id[i]])
					f[i][j] = max(f[i-1][j-a[id[i]]]+b[id[i]], f[i][j]);
			}
		}
		long long ans = f[n][L];
		
		for(int i = 1; i <= n; ++i) {
			ans = max(ans, b[i]); 
		}
		
//		cout<<f[n][L];
		for(int i = 1; i <= n; ++i) {
			if(L>=(a[id[i]]+1)/2)
				ans=max(ans, f[i-1][L-(a[id[i]]+1)/2]+b[id[i]]);
		}
		for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) {
			if(L >= (a[id[i]]+a[id[j]]+1)/2)
				ans=max(ans,f[i-1][L-(a[id[i]] + a[id[j]]+1)/2]+b[id[i]]+b[id[j]]);
		}
		printf("Case #%d: %lld\n",e, ans);
	}
	return 0;
}