#include<bits/stdc++.h>
using namespace std;

int M,K;
const int mod = 1e9 + 9;
int Add(int x, int y) {return (x + y) % mod;}
int Mul(int x, int y) {return 1ll * x * y % mod;}

int inv(int x) {
    x = x % mod;
    int y = mod - 2, r = 1;
    for(; y; y >>= 1, x = Mul(x, x)) if(y & 1) r = Mul(r, x);
    return r;
}

const int MN = 1e7 + 5;
int E[MN], N[MN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> K;
    
    int sum = 0;
    N[0] = 1;
    E[0] = 0;
    for(int i = 1; i <= K; ++i) {
        N[i] = Add(N[i-1], M - 1);
        sum = Add(sum, E[i-1]);
        E[i] = Mul(Add(1 + Mul(N[i-1], E[i-1]), Mul(E[i-1]+1, M-1)), inv(N[i]));
        // std::cerr << N[i] << " " << E[i] << " " << sum << "\n";
    }

    cout << Add(sum, Mul(N[K], E[K])) << "\n";
    return 0;
}