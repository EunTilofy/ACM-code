#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    while(1) {
        ofstream o("1.in");
        int n = 100000;
        o << n << "\n";
        for(int i = 1; i <= n; ++i) o << rand() % 100 << " ";
        o.close();
        system("./J.bin < 1.in > 1.out");
        // system("./JJ.bin < 1.in > 2.out");
        // if(system("diff 1.out 2.out")) {
        //     cerr << "NO\n";
        //     break;
        // }
        cerr << "PASS\n";
    }

    return 0;
}