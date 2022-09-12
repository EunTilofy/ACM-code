#include<bits/stdc++.h>
using namespace std;
const int MN = 300005;
inline int read() {
	int x=0,f=1;
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
int a[MN], b[MN], k, n, m;
int main()
{
    k = read(), n = read(), m = read();
    if(k > n) return 0 * puts("-1");
    for(int i = a[0] = 1; i <= k; ++i) {
        a[i] = read();
        if(a[i] == -1) a[i] = a[i - 1];
        if(a[i] < a[i - 1]) return 0 * puts("-1");
    }
    int now = 0;
    for(int i = 1; i <= k; ++i)
    {
        for(int j = 1; j <= m - a[i]; ++j)
        {
            if(now == n - k) break;
            b[i + now++] = m - j + 1;
        }
        b[i + now]=a[i];
    }
    if(now != n - k) return 0 * puts("-1");
    for(int i = 1; i <= n; ++i) printf("%d ", b[i]);
    return 0;
}