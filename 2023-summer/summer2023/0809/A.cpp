#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(x % 3== 0) {
            cout << (1ll*(x/3)*(x/3)*(x/3)) << "\n";
        }
        else if(x % 4 == 0) {
            cout << (1ll*(x/4)*(x/4)*(x/2)) << "\n";
        } else {
            cout << "-1\n";
        }
    }
}