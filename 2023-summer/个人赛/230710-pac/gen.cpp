#include<bits/stdc++.h>
using namespace std;
int main() {
	srand(time(NULL));
	cout << 1 << endl << 20 << endl;
	vector<int> a(20);
	for(int i = 1; i <= 20; ++i) a[i-1] = i;
	random_shuffle(a.begin(), a.end());
	for(auto x : a) cout << x << " ";
}