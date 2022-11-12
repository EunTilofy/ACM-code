#include<bits/stdc++.h>
using namespace std;

int main() {
	system("g++ -g K.cpp -o K");
	system("g++ -g ck.cpp -o ck");
	system("g++ -g gen.cpp -o gen");
	for(int o = 1; ; ++o) {
		system("gen.exe > in");
		system("K.exe < in > oo");
		system("ck.exe < in > uu");
		if(system("fc oo uu")) {
			cout << "WA!\n";
			return 0;
		}
		cout << "test" << o << ":AC!\n";
	}
	return 0;
}