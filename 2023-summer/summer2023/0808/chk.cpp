#include<bits/stdc++.h>
using namespace std;

int main() {
    system("g++ K.cpp -o K --std=c++20");
    system("g++ J.cpp -o J --std=c++20");
    // while(1) {
        for(int n = 2; n <= 300; ++n) {
            for(int m = 0; m <= 50; ++m) {
                for(int k = 1; k <= 100; ++k) {
                    ofstream o("in");
                    o << n << " " << m << " " << k;
                    o.close();

                    system("./K < in > out");
                    // system("./J < out > out1");

                    ifstream i("out");
                    int N;
                    i>>N;
                    if(N == 0) {
                        cout << n << " " << m << " " << k << "\n";
                    }
                    else {
                        assert(N == n);
                        for(int I = 1; I <= N; ++I) {
                            string s;
                            i>>s;
                            assert(s.size() == k);
                        }
                    }

                    // ifstream i("out1");
                    // int ans; i>>ans;
                    // if(ans != m) {
                        // return 0;
                    // }

                    // if(system("diff out1 out2")) {
                    //     return 0;
                    // }
                    // cout << "~!\n";
                }
            }
        }
        // system("./K < in && ./J < in");

        // system("diff ");
    // }
}