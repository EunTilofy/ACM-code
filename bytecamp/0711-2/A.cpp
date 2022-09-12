#include <bits/stdc++.h>
using namespace std;
const int N = 6e4 + 10;
char s[N], t[N];
int nm[N];
bitset<N> a, b, c;

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s%s", s, t);
	for(int i = 0; i < 2 * n + 1; ++i)
		if(s[i] == '1') b.set(2 * n - i, 1);
	int ans = 0, pos = n;         
	for(int i = 0; i < n; ++i) {       
		if(t[i] == 'L') pos--;
		else if(t[i] == 'R') pos++;
		else {
			nm[pos]++;
			a.set(2 * n - pos, 1);
		}
	}
//	cout << b << endl;
//	printf("%d\n", pos);
	int nw = 0;
	for(int i = 0; i < n; ++i) {
//		puts("-----");
//		cout << a << endl;
//		cout << b << endl;
//		
//		puts("???");
//		cout << c << endl;
		c = a & b;
		ans = max(ans, (int)c.count());
//		if(c.count() == 5) printf("sup!%d\n", i);
		if(t[i] == 'L') a >>= 1, nw++;
		else if(t[i] == 'R') a <<= 1, nw--;
		else {
			nm[n - nw]--;
			if(!nm[n - nw]) a.set(n, 0);
			a.set(2 * n - pos, 1);
			nm[pos - nw]++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*
6
1111111111111
TLTLTT
*/