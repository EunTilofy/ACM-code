#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--) {
        int m;
        cin >> m;
        if(m%2==0) {
            cout << m/2+1 << "\n";
        } else {
            cout << min(m, m/2+2) << "\n";
        }
    }
}