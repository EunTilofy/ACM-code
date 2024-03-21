#include<bits/stdc++.h>
using namespace std;

bool solve() {
    int n, k;
    cin >> n >> k;
    int x = n / k, m = n % k;
    int num = n / 2;

    int a = num / x, b = num % x;
    if(a > k) b += (a - k) * x, a = k;
    if(b > m) return false;
    if(a < b) return false;
    int pos = (m - b) / x, tmp = (a - b) / (x + 1);
    pos = min(pos, tmp);
    a -= pos, b += pos * x;
    return a - b <= k - m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        cout << (solve() ? "Yes\n" : "No\n");
    }
}