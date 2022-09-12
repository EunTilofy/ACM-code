#include<bits/stdc++.h>
using namespace std;
int read() {
	int x;
	scanf("%d",&x);
	return x;
}
int main() {
	freopen("easiest20.in", "r", stdin);
	freopen("test4.in","w",stdout);
	int n,m,q = 0;
	n = read(), m = read();
	std::cout<<n<<" "<<m<<endl;
	for(int i = 1; i <= n; ++i) {
		int x = read();
		std::cout<<x;
		if(i < n) std::cout<<" ";
	}
	std::cout<<std::endl;
	for(int i = 1; i <= m; ++i) {
		if(read()==1){
			int l1,l2,r1,r2;
			l1 = read(), r1 = read(), l2 = read(), r2 = read();
			printf("%d %d %d %d\n", l1, r1, l2, r2);
		}
	} 
	return 0;
}