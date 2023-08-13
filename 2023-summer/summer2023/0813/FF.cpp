#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int sz = 7;
struct node {
    int a[7][7];
};

int add(int x, int y) {
    return (x + y) % mod;
}
void Add(int &x, int y) {
    x = add(x, y);
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
    x = mul(x, y);
}

node jz(node A, node B) {
    node res; 
    memset(res.a, 0, sizeof res.a);
    for(int i = 0; i < sz; ++i) for(int j = 0; j < sz; ++j) for(int k = 0; k < sz; ++k) {
        Add(res.a[i][j], mul(A.a[i][k], B.a[k][j]));
    }
    return res;
}

node q_jz(node A, int n) {
    // cerr << n << "\n";
    node res;
    for(int i = 0; i < sz; ++i) for(int j = 0; j < sz; ++j) res.a[i][j] = (i == j);
    for(; n; n >>= 1) {
        if(n & 1) res = jz(res, A);
        A = jz(A, A);
    }
    return res;
}

void solve(int n) {
    node A;
    memset(A.a, 0, sizeof A.a);
    A.a[0][1] = 1, A.a[0][2] = 1, A.a[0][6] = 1; // g
    A.a[1][1] = 1, A.a[1][4] = 1, A.a[1][5] = 2; // R
    A.a[2][2] = 1, A.a[2][3] = 1; // E
    A.a[3][1] = 1, A.a[3][2] = 2, A.a[3][3] = 1; // T
    A.a[4][1] = 1, A.a[4][2] = 1, A.a[4][4] = 2, A.a[4][6] = 1; // G2
    A.a[5][3] = 1, A.a[5][5] = 2; // E2
    A.a[6][6] = 1;
    A = q_jz(A, n);
    cout << add(add(A.a[0][0], A.a[0][4]), A.a[0][6]) << "\n";
}
/*
1
2
5
14
42
131
417
1341
4334
14041
45542
147798
479779
*/
int main() {
    freopen("figure.in", "r", stdin);
    freopen("figure.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        int n; cin >> n;
        if(!n) break;
        solve(n);
    }
    return 0;
}