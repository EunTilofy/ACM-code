#include<bits/stdc++.h>
using namespace std;
int read(void) {
    int ch = getchar(), res = 0, flg = 0;
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        flg = 1, ch = getchar();
    for (; isdigit(ch); ch = getchar())
        res = (res << 1) + (res << 3) + (ch - '0');
    return flg ? -res : res;
}
int main() {
    
}