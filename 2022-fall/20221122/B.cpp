#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n;
	double sum = 0.0;
	for(int i = 1; i <= n; ++i) {
		int x; cin >> x;
		sum += x;
	}
	for(int i = 1; i <= n; ++i) {
		int num = 1;
		if(i==1) ++num;
		cout<<fixed<<setprecision(10)<<(sum*num)/(double)(n+1.0)<<" ";
	}
	return 0;
}