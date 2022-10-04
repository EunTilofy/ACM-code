#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if(n == 2 || n == 4) puts("-1");
	else if(n & 1) {
		printf("%d\n", n / 2 + 1);
		for(int i = 1; i <= n / 2 + 1; ++i)
			printf("%d ", i);
		puts("");
	} else {
		printf("%d\n", n / 2);
		for(int i = 1; i <= n / 2 + 1; ++i) {
			if(i != 2) printf("%d ", i);
		}	
		puts("");
	}
	return 0;
}