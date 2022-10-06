#include <bits/stdc++.h>
using namespace std;

string s = "";
int main() {
	int n; scanf("%d", &n);
	for(int o = 1; n; ++o) {
//		printf("%d\n", n);
		if(n < o) {
			for(int i = 1; i <= n; ++i) printf("(");
			cout << s;
			for(int i = 1; i <= n; ++i) printf(")");
			return 0;
//			pos = n * 2 + s.size();
//			printf("%d %d\n", now, pos);
//			if(pos > 100000) {puts("????"); printf("%d\n", now); return 0;}
//			f = 1; break;
		}
		n -= o;
		int len;
		for(len = 1; 1ll * len * (len + 1) / 2 <= n; ++len) ;
		--len;
//		printf("len = %d\n", len);
		n -= 1ll * len * (len + 1) / 2;
		s += '(';
		for(int i = 1; i <= len; ++i) s += '(', s += ')';
		s += ')';
	}
//	puts("??");
	cout << s << endl;
//	if(f) continue;
//	pos = s.size();
//	printf("%d %d\n", now, pos);
//	if(pos > 100000) {puts("????");printf("%d\n", now); return 0;}
	return 0;
}