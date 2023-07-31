#include<bits/stdc++.h>
using namespace std;

void write(__int128 C) {
    if(C < 0) {
        cout << "-";
        C = -C;
        write(C);
        return;
    }
    if(C < 10) cout << (long long)C;
    else {
        write(C/10);
        cout << (long long)(C%10);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long A, B;
    cin >> A >> B;
    __int128 C = A;
    C += B;
    write(C);
    return 0;
}