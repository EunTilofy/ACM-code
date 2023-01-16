#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int mx = 10;
	int n = rand() % mx + 1;
	int m = rand() % mx + 1;
	int p = rand() % m + 1;
	int q = rand() % m + 1;
	cout << n << " " << m << " " << p << " " << q << "\n";
	return 0;
}