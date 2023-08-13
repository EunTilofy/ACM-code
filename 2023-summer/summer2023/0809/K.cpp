#include<bits/stdc++.h>
using namespace std;

void print(int x) {
    if(x < 10) cout << "0" << x;
    else cout << x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int len = s.size();
        int xx = 8, f = 1;
        double num = 0;
        for(int i = 3; i < len; ++i) {
            if(s[i]=='-') f=-1;
            if(s[i]<='9'&&s[i]>='0') num=num*10+s[i]-'0'; 
        }
        for(int i = 3; i < len; ++i) if(s[i]=='.') {
            for(int j = i + 1; j < len; ++j) {
                num/=10.0;
            }
            break;
        }
        num *= f;
        num -= 8;
        // cout << num << "\n";
        int _ = (int)num;
        while(_>num) _-=1;
        // cout << _ << "\n";
        int c = (int)((num - _) * 60 + 0.5);

        a += _;
        a %= 24; a = (a+24)%24;
        b += c;
        while(b>=60) a=(a+1)%24, b-=60;
        print(a);
        cout << ":";
        print(b);
        cout << "\n";
    }
}