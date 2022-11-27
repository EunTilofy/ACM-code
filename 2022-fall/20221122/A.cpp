#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	long long sum = 0;
	unsigned long long ans = -1;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin>>x;
		sum += x;
	}
	long long pos = (sum * 2) / n;
	for(long long i = pos - 3; i <= pos + 3; ++i) {
		if(n%2==1 && i%2==1) continue;
		// cout<<i<<endl;?
		ans = min(ans, (unsigned long long)abs((sum*2-i*n)/2ll));
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}