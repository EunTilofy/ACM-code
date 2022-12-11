#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
double a[100005];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	double R;
	double thi;
	cin>>n>>R>>thi;
	thi = min(thi, 2*pi-thi);
	for(int i = 0; i < n; ++i) cin>>a[i];
	// cout<<"ssss"<<endl;
	// cin>>R;
	double ans=thi*R;
	for(int i = 0; i < n; ++i) {
		double r = a[i];
		ans = min(ans, thi*r+2.0*(R-r));
	}
	cout<<fixed<<setprecision(10)<<ans;
	return 0;
}