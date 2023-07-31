#include<bits/stdc++.h>
using namespace std;
	long long sum = 0;
	bool fl = 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		fl &= (x == 1);
		sum += x;
	}
	if((sum & 1) || (fl == 0)) cout << "Putata";
	else cout << "Budada"; 
}