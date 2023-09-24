#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << 15000 << "\n";
    srand(time(0));
    for(int i = 1; i <= 15000; ++i) {
        int x = rand() % 10;
        if(x == 0) cout << "x" << " ";
        else cout << x << " ";
    }
    cout << "\n";
    cout << "9\n";
    for(int i = 1; i <= 9; ++i) {
        cout << i << " " << abs(rand()) << "\n";
    }
}