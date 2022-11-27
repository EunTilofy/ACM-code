#include<bits/std++.h>
using namespace std;
#define MN 100005
int q,n;
int a[MN], b[MN];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; ++i) cin>>a[i], b[i] = a[i]^b[i-1];
	while(q--) {
		int opt, l, r;
		cin>>opt>>l>>r;
		if(opt==1) {
			int x;
			cin>>x;
		}
		else {
			
		}
	}
	return 0;
}