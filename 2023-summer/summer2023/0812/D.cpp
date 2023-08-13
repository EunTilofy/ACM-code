#include<bits/stdc++.h>
using namespace std;

int f[100005][10];
// -4 ~ 4 (+5)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    string t;
    cin >> n >> s;
    getline(cin, t);
    if(s == "G") {
        cout << "OK";
    }
    if(s == "PG") {
        if(n < 13) cout << "OK IF ACCOMPANIED";
        else cout << "OK";
    }
    if(s == "R-13") {
        if(n < 13) cout << "ACCESS DENIED";
        else cout << "OK";
    }
    if(s == "R-16") {
        if(n < 16) cout << "ACCESS DENIED";
        else cout << "OK";
    }
    if(s == "R-18") {
        if(n < 18) cout << "ACCESS DENIED";
        else cout << "OK";
    }
}

/*
"G" - no need for age-verification
"PG" - anyone below 13 years old should be accompanied by a responsible adult
"R-13" - none below 13 years old
"R-16" - none below 16 years old
"R-18" - none below 18 years old

"OK" if you can give the person access,
"OK IF ACCOMPANIED" if you can give the person access if accompanied by a responsible adult, or
"ACCESS DENIED" otherwise.
*/