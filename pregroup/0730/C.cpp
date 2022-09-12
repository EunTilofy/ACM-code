#include<bits/stdc++.h>
using namespace std;
char s[5005], t[5005];
int f[5005], g[5005];
const int P = 1e9 + 7;
int Add(int x, int y) {return (x + y) % P;}
int main() {
    g[0] = 1;
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for(int i = 1; i <= n; ++i) { 
        for(int j = 1; j <= m; ++j) f[j] = 0;
        for(int j = 1; j <= m; ++j) if(s[i] == t[j]) f[j] = g[j - 1];
        for(int j = 1; j <= m; ++j) g[j] = Add(g[j], f[j]); 
    }
    printf("%d\n", g[m]);
    return 0;
}