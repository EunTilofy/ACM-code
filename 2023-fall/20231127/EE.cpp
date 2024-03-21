#include<bits/stdc++.h>
using namespace std;

// first or not, A, B, c
bool f[2][2][101][101][202], v[2][2][101][101][202];

bool sol(bool fi, int A, int B, int C, bool ta) {
    if(v[fi][ta][A][B][C]) return f[fi][ta][A][B][C];
    if(A == 0) {
        v[fi][ta][A][B][C] = 1;
        f[fi][ta][A][B][C] = ta == 0;
        return f[fi][ta][A][B][C];
    }
    if(C == 0) {
        v[fi][ta][A][B][C] = 1;
        f[fi][ta][A][B][C] = ta == 0;
        return f[fi][ta][A][B][C];
    }
    if(C == A + B) {
        v[fi][ta][A][B][C] = 1;
        f[fi][ta][A][B][C] = (A%2)==ta;
        return f[fi][ta][A][B][C];
    }
    bool ans = 0;
    if(fi) {
        ans |= sol(0, A - 1, B, C - 1, ta^1);
        if(B) ans |= sol(0, A, B - 1, C - 1, ta);
    } else {
        ans = 1;
        ans &= sol(1, A - 1, B, C, ta);
        if(B) ans &= sol(1, A, B - 1, C, ta);
    }
    v[fi][ta][A][B][C] = 1;
    f[fi][ta][A][B][C] = ans;
    return ans;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    for(int n = 2; n <= 100; n += 2)
        for(int m = 1; m <= 100; ++m) {
            cout << "A = " << n << " B = " << m << " " << n + m << " : ";
            int cnt = 0;
            for(int c = 1; c <= n + m; ++c) 
            {   
                int x; 
                cout << (x = sol(1, n, m, c, 1)) << " ";
                cnt += x;
            }    cout << " :: tmp = " << cnt << "\n";
        }
    
    for(int n = 2; n <= 100; n += 2)
        for(int m = 1; m <= 100; ++m) {
            cout << "A = " << n << " B = " << m << " " << n + m << " : ";
            int cnt = 0;
            for(int c = 1; c <= n + m; ++c) 
            {   
                int x; 
                cout << (x = sol(0, n, m, c, 1)) << " ";
                cnt += x;
            }    cout << " :: tmp = " << cnt << "\n";
        }
                
    // for(int n = 2; n <= 8; n += 2)
    //     for(int m = n; m <= 16; ++m) {
    //         cout << "A = " << n << " B = " << m << " : ";
    //         for(int c = 1; c <= n + m; ++c) 
    //             cout << sol(0, n, m, c, 1) << " ";
    //         cout << "\n";
    //     }
    return 0;
}