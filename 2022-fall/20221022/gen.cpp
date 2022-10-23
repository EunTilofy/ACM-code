#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	int len = rand() % 100 + 1;
	int a = rand() % 10 + 1;
	cout << a << " " << a + len << endl;
	return 0;
}