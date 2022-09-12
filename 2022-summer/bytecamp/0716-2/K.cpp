#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

bool a[1005];
int ans = 0;

int main() {
	int n;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
    if(n & 1) {
        cout<<"! -1"<<endl;
        return 0;
    }
    for(int i = 1; i < n; i += 2) {
        cout<<"? L "<<i<<" "<<i + 1<<endl;
        fflush(stdout);
        int _;cin>>_;
    }
    cout<<"! "<<n / 2<<endl;
	return 0;
}