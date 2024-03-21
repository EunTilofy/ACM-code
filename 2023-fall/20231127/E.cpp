#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, c;
    cin >> n >> m >> c;
    if((n == 1 && m == 1) || c == 0 || (n == 2 && m == 2)) {
        cout << "Bie Bie\n";
        return;
    }
    long long A = 1ll * 2*(n-2)+ 1ll * 2*(m-2);
    if(n == 1 || m == 1) A = 2;
    long long B = 1ll * n * m - A;


    if(A % 4 == 2) {
        if(c <= (A + B + 1)/2) cout << "Xiuga ";
        else cout << "Bie ";

        if(c <= (A + B)/2) cout << "Xiuga\n";
        else cout << "Bie\n";
        return;
    }

    
    if(c <= (A + B + 1)/2 - 1) cout << "Xiuga ";
    else cout << "Bie ";

    if(c <= (A + B)/2 - 1) cout << "Xiuga\n";
    else cout << "Bie\n";
}
// Xiuga Xiuga
// Bie Bie
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}