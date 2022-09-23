#include<bits/stdc++.h>
using namespace std;
int x[3], y[3];
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x<<1) + (x<<3) + ch - '0'; ch = getchar();}
	return x * f;
}
int n[3], d[3][1000005];
int tot;
struct P{
	double x, y;
}p[10];
#define db double
db len(int _1, int _2) {
	#define sqr(x) ((db)(x) * (db)(x))
	return sqrt(sqr(x[_1] - x[_2]) + sqr(y[_1] - y[_2]));
}
P get(int _1, int _2, int D) {
	double X, Y;
	X = (db)x[_1] + (db)(x[_2] - x[_1]) * (db)D / (db)len(_1, _2);
	Y = (db)y[_1] + (db)(y[_2] - y[_1]) * (db)D / (db)len(_1, _2);
	return (P){X, Y};
}
db get_(P x, P y, P z) {
	P yx = (P){y.x - x.x, y.y - x.y};
	P zx = (P){z.x - x.x, z.y - x.y};
	return 0.5000 * fabs(yx.y * zx.x - yx.x * zx.y);
}
int main() {
	for(int i = 0; i < 3; ++i) x[i] = read(), y[i] = read();
	for(int i = 0; i < 3; ++i) {
		n[i] = read();
		for(int j = 1; j <= n[i]; ++j) d[i][j] = read();
		std::sort(d[i] + 1, d[i] + n[i] + 1);
		if(n[i]) ++tot, p[tot] = get(i, (i + 1) % 3, d[i][1]);
		if(n[i] > 1) ++tot, p[tot] = get(i, (i + 1) % 3, d[i][n[i]]);
	}
	double ans = 0;
	for(int i = 1; i <= tot; ++i) for(int j = 1; j <= tot; ++j) for(int k = 1; k <= tot; ++k)
		if(i != j && i != k && j != k) ans = max(ans, get_(p[i], p[j], p[k]));
	return 0 * printf("%.10lf\n", ans);
}