#include<bits/stdc++.h>
using namespace std;

string t = "You are right, but ";

int main() {
    string s;
    getline(cin, s);
    if(s.substr(0, 19) == t) cout << "AI";
    else cout << "Human";
}