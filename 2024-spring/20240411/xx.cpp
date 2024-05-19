#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l = 4e8;
    int cnt = 1;
    for(int i = l; ; ++i) {
        int flg = 1;
        for(int j = 2; j * j <= i; ++j) if(i % j == 0) {flg = 0; break;}
        if(flg&&cnt<=2) cout << i << "\n";
        cnt += flg;
        if(cnt > 2) break;
    }

    return 0;
}