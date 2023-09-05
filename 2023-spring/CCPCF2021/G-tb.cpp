#include<bits/stdc++.h>
using namespace std;
int sg[1005][1005];

int main() {
    freopen("tb1.txt", "w" ,stdout);
    int p = 4;
    for(int len = 1; len <= 1000; ++len)
    for(int i = 1; i + len - 1<= 1000; ++i)
    {
        int l = i, r = i + len - 1;
        vector<int> s;
        for(int k = l; k <= r; ++k) {
            if(k * p >= r) {
                s.push_back(sg[l][k-1]);
            }
        }
        // cerr << len << " " << i << endl;
        sort(s.begin(), s.end());
        int mex = 0;
        for(int j = 0; j < s.size(); ++j) {
            if(mex == s[j]) ++mex;
            if(mex < s[j]) break;
        }
        sg[l][r] = mex;
    }
    for(int i = 1; i <= 3; ++i)
        for(int j = i; j <= 1000; ++j) {
            cout << "sg[" << i << "][" << j << "] = " << sg[i][j] << endl;
        }
    return 0;
}