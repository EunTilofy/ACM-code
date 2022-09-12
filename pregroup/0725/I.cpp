#include<bits/stdc++.h>
using namespace std;
inline long long read() {
    long long x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1e5;
int pr[MN + 5], tot, mi[MN + 5];
bool mk[MN + 5];
void init()
{
	int i, j;
	for(i = 2; i <= MN; ++i)
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
    int n = read(); init();
    for(int i = 1; 1ll * pr[i] * pr[i] <= n; ++i) 
        if(n % pr[i] == 0) {
            while(n % pr[i] == 0) n /= pr[i];
            if(n == 1) return 0 * puts("yes");
            else return 0 * puts("no");
        }
    if(n == 1) return 0 * puts("no");
    else return 0 * puts("yes");
}