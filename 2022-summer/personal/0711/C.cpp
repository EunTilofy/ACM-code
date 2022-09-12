#include<bits/stdc++.h>
using namespace std;
int n, q;
#define MN 60005
char s[MN];
int a[MN];
struct que{
    int l, r;
}q[MN];
int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    int BL = (int)sqrt(n) + 1;
    a[0] = 0;
    for(int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] ^ (1 << (s[i] - 'a'));
    }
    
}