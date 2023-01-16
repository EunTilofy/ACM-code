#include<bits/stdc++.h>
using namespace std;
int main() {
	while(1) {
		system("data.exe>data.txt");
		system("B.exe<data.txt>1.txt");
		if(system("fc 1.txt data.txt"))break;
	}
	return 0;
}