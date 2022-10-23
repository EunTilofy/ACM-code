#include <bits/stdc++.h>
using namespace std;

int main() {
	system("g++ gen.cpp -o gen.exe");
	system("g++ E.cpp -o E.exe");
	system("g++ bl.cpp -o bl.exe");
	for(int o = 1; ; ++o) {
		system("gen.exe > in");
		system("E.exe < in > oo");
		system("bl.exe < in > uu");
		if(system("fc oo uu")) {
			puts("NO!!!");
			return 0;
		}
		printf("cas %d: ok!\n", o);
	}
	return 0;
}