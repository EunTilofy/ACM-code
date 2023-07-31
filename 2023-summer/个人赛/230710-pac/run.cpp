#include<bits/stdc++.h>
using namespace std;
int main() {
	system("g++ gen.cpp -o gen --std=c++20");
	system("g++ dp.cpp -o std --std=c++20");
	system("g++ A.cpp -o A --std=c++20");

	while(1) {
		system("gen.exe > data.txt");
		system("A.exe < data.txt > A.txt");
		system("std.exe < data.txt > std.txt");

		freopen("A.txt", "r", stdin);
		int n, m, a, b;
		cin >> n >> m;
		freopen("std.txt", "r", stdin);
		cin >> a >> b;
		assert(n == a && m == b);
		cout << "go" << endl;
	}
	return 0;
}