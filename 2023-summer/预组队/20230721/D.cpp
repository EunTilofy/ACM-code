#include<bits/stdc++.h>
using namespace std;

const int P = 1000000007;
const int inv2 = (P+1)/2, inv3 = (P+1)/3;

int Mul(int x, int y) {return (long long)x*y%P;}
int Add(int x, int y) {return (x+y)%P;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long ans = Add(Mul(Mul(n,n), Mul(Add(Mul(n,n), P-1), inv2)), P-Mul(inv3, Mul(n-1, Mul(n, (2ll*n-1ll)%P))));

    ans = (ans%P+P)%P;
    cout << ans;
}