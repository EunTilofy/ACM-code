#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 30;
    srand(time(0));
    while(1) {
    ofstream out("in");
    out <<"1\n";
    out << n << endl;
    for(int i = 1; i <= n; ++i) {
        out << rand()%3+1 << " ";
    }
    out.close();
    cout << "ok~!\n";
    system("E < in > out2");
    system("EE < in > out1");
    if(system("fc out1 out2")) {
        cout << "NO\n";
        return 0;
    }
    cout << "Pass!\n";
    }
}