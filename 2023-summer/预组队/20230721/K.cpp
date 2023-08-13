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
    int ans = (int)n/exp(1)+0.5;
    cout << ans;
}