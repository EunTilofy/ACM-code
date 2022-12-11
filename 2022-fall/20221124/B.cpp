#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	int A,B,K;
	cin>>A>>B>>K;
	if(A == B) {
		cout << "1."<<string(K,'0');
		cout << "\n";
		return 0;
	}
	vector<int> a(K);
	cout << "0.";
	A *= 10;
	for(int i = 0; i < K; ++i) {
		a[i] = A / B;
		A = A % B;
		A *= 10;
	}
	if(A / B >= 5) a[K - 1]++;
	for(int x : a) cout << x;
	cout << "\n";
	return 0;
}