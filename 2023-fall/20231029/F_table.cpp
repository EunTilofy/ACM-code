#include<bits/stdc++.h>
using namespace std;

const int N = 100;

int f[N+5][N+5];

int main() {
    for(int i = 0; i <= N; ++i) 
    for(int j = 0; j <= N; ++j) {
        vector<int> val;
        for(int k = 1; k <= i; ++k) if(j%k==0) {
            val.push_back(f[i-k][k]);
        }
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        int mex = 0;
        for(int i = 0; i < val.size(); ++i) {
            if(val[i] == mex) ++mex;
            else break;
        }
        f[i][j] = mex;
    }
    ofstream o("table.txt");
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= N; ++j) {
            o << f[i][j] << " ";
        }
        o << "\n";
    }
    return 0;
}