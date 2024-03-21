#include<bits/stdc++.h>
using namespace std;

int main() {
    system("g++ DD.cpp -o DD --std=c++20");
    system("g++ D.cpp -o D --std=c++20");
    for(int i = 1; i <= 20; ++i) {
        ofstream in("in.txt");
        in<<i; in.close();
        system("DD.exe < in.txt > out2.txt");
        system("D.exe < in.txt > out.txt");
        if(system("fc out.txt out2.txt")) {
            return 0;
        } 
        cout << "PASS : " << i << "\n";
    }
    return 0;
}