#include<bits/stdc++.h>
#define ll long long
#define lll __int128
using namespace std;

int f[10] = {1, 9, 41, 109, 205, 325};

void print(lll x) {
	if(!x) return ;
	print(x / 10);
	cout << (int)(x % 10);
} 

void solve(int o) {
	ll nn;
	cin >> nn;
	cout << "Case #"<<o<<": ";
	lll n = nn;
	lll ans = n * n * 14 - n * 6 + 5;
	if(n <= 5) cout << f[nn] << "\n"; 
	else {
		print(ans);cout << "\n";
	}
}
int main() {
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
		
		solve(o); 
	}
    return 0;
}
