#include<bits/stdc++.h>
using namespace std;
long long f[3005][3005][2];
int a[3005][15];
int main() {
	int n, k;
	cin>>n>>k;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i][0];
		for(int j = 1; j <= a[i][0]; ++j) cin>>a[i][j];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= k; ++j) {
			for(int o = 0; o < 2; ++o) if(f[i][j][o]>0||(j==0&&o==0)){
				for(int num = 0; num <= min(a[i+1][0], k - j); ++num) {
					if(!num) f[i+1][j][o] = max(f[i+1][j][o], f[i][j][o]);
					else if(num == a[i+1][0]) f[i+1][j+num][o] = max(f[i+1][j+num][o], f[i][j][o] + a[i+1][a[i+1][0]]);
					else if(!o) {
						f[i+1][j+num][1] = max(f[i+1][j+num][1], f[i][j][0] + a[i+1][num]);
					}
				}
			}	
		}
	}
	long long ans = 0;
	for(int i = 0; i <= k; ++i) {
		ans = max(ans, f[n][i][0]);
		if(i == k) ans = max(ans, f[n][i][1]);
	}
	cout<<ans<<endl;
	return 0;
}