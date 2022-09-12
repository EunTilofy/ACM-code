#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
#define Fabs(x) ((x)>0?(x):(-(x)))
const int MN = 1e5 + 5;
struct Point{
    __float128 x, y;
}p[MN];
__float128 k[MN], o[MN], oo[MN];
const __float128 eps = 1e-12;
int main() {
    int n = read();
    for(int i = 1; i <= n + 1; ++i) p[i].x = read(), p[i].y = read();
    for(int i = 1; i <= n; ++i) k[i] = (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x);
    for(int i = 1; i < n; ++i) o[i] = (k[i + 1] - k[i]) / 2.00000;
    oo[n] = 0.00000;
    for(int i = n - 1; i; --i) oo[i] = oo[i + 1] + o[i];
    __float128 now = 0.000000;
    for(int i = 1; i < n; ++i) now += o[i] * (p[i + 1].x - p[1].x);
    if(Fabs(now - p[1].y) > eps) return 0 * puts("No");
    for(int i = 2; i <= n + 1; ++i) {
        now -= oo[i - 1] * (p[i].x - p[i - 1].x);
        now += (oo[1] - oo[i - 1]) * (p[i].x - p[i - 1].x);
        if(Fabs(now - p[i].y) > eps) return 0 * puts("No");
    } 
    return 0 * puts("Yes");
}
/*
2
-1 2
1 0
2 1

3
-3 -1
-1 -1
1 1
4 1

3
-3 1
-2 0
0 1
1 1
*/