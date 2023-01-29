#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    for(int i = s.size()-1; ~i; --i) {
        if(s[i]!='?'){
            if(s[i]=='D') cout << "DRX" << endl;
            else cout << "T1" << endl;
            return 0;
        }
    }
    return 0;
}