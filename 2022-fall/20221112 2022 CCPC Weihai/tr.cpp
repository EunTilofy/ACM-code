#include <bits/stdc++.h>
using namespace std;

int main () {
	multiset<int> s = {1, 1, 1, 2, 2};
	s.erase(s.find(1));
	cout << s.size() << "\n";
	return 0;
}

/*
1 2 3
4 5 6
5 6 7
8 9 10
9 10 11
10 11 12
13 14 15
14 15 16
17 18 19
1 4 8
2 5 9
5 9 13
3 6 10
6 10 14
10 14 17
7 11 15
11 15 18
12 16 19
3 7 12
2 6 11
6 11 16
1 5 10
5 10 15
10 15 19
4 9 14
9 14 18
8 13 17
*/