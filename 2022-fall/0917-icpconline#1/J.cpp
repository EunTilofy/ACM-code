#include <bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x <<"="<<" "
#define dbg2(x) cerr<<#x <<"="<< " "
using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void print(int x, int y) {
	int pos = gcd(x, y);
	printf("%d %d\n", x / pos, y / pos);
}

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	int pos = 2 + x - 2 * y;
	if(pos > 0) {
		print(pos, x);
		for(int i = x - 1; i >= 1; --i)
			print(1, i);
	} else {
		int J = x * (x - 1) / 2, k = x - y;
		for(int i = 1; i <= x - 1; ++i)
			print(k, J - (i - 1) * k);
		print(1, 1);
	}
	return 0;
}

/*
2 15
2 13
2 11
2 9
2 7
1 1
*/