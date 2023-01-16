#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in.txt", "w", stdout);
    int n = 200;
    int k = 6;
    cout << n << " " << k << endl;
    srand(time(NULL));
    for(int i = 1; i <= n; ++i) cout << 1 + (rand() % 9);
    return 0;
}