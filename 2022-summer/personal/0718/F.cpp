#include<bits/stdc++.h>
using namespace std;
const int MN = 1e7 + 1;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
int f[MN];
int pr[MN], tot, mi[MN];
bool mk[MN];
void init()
{
	int i, j;
	for(i = 2; i < MN; ++i)
	{
		if(!mk[i]) {
            pr[++tot] = i;
            mi[i] = i;
        }
		for(j = 1; j <= tot && pr[j] * i <= MN; ++j)
		{
			mi[pr[j] * i] = pr[j];
            mk[pr[j] * i] = 1;
			if(i % pr[j] == 0) break;
		}
	}
}
int main() {
    init();
    f[1] = 1;
    for(int i = 2; i < MN; ++i) {
        if(!mk[i]) f[i] = i;
        else f[i] = f[i / mi[i]] + mi[i];
    }
    int n = read();
    int x, y;
    while(n--) {
        scanf("%d%d", &x, &y);
        while(y--) {
            if(f[x] == x) break;
            x = f[x];
        }
        printf("%d\n", x);
    }
    return 0;
}