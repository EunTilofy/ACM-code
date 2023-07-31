#include<bits/stdc++.h>
using namespace std;

void read(__int128& x) {
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch >'9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = x*10ll + ch - '0', ch = getchar();
}
void print(__int128 x) {
	if(x < 10) cout << (int)x;
	else {
		print(x/10);
		cout << (int)x%10;
	}
}

__int128 M = 606745820232LL;

const int a[] = {8, 27, 53*53, 1000003};

__int128 solve(__int128 U) {
	for(int i = 0; i <= a[3]; ++i) {
		
	}
}

int main() {
	__int128 l, r;
	read(l), read(r);

	__int128 ans = solve(r/M) - solve((l-1)/M);

	print(ans);
	return 0;
}