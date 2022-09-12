#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 500000 + 5;
const int P = 1e9 + 7;
int n, a[MN], id;
int Mul(int x, int y) {return 1ll * x * y % P;}
int Add(int x, int y) {return (x + y) % P;}
std::vector<int> b;
int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    id = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] > a[id]) {
            id = i;
            b.push_back(i);
        }
    }
    int f = 1;
    int sum = 0;
    for(int i = 1; i < b.size(); ++i) {
        sum = Add(sum, Mul(f, b[i] - b[i - 1]));
        f = Add(sum, 1);
    }
    printf("%d\n", f);
}