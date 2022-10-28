#include<bits/stdc++.h>
using namespace std;
int main() {
	long long N;
	cin>>N;
	long long ans = 1ll * N * (N - 1) / 2ll;
	long long res = (N / 3) * 2 + N % 3;
	res = res * (res - 1ll) / 2;
	cout<<ans - res;
	return 0;
}