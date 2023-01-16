#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream in("a.out");
    vector<pair<int, string> > a;
    string x;
    int cnt = 0;

    for(int i = 1; i <= 4999; ++i)
        in >> x,
        a.push_back({cnt ++, x});

    ifstream inin("b.out");
    cnt = 0;
    for(int i = 1; i <= 4999; ++i){
        inin >> x;
        if(a[cnt].second != x) {
            cout << cnt << " : " << a[cnt].second << " " << x << endl;
        }
        cnt ++;
    }
    return 0;
}