#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int len = 1;
    for(int i = 1; i <= 20; ++i) {
        for(int j = 1; j <= i; ++j) cout << "x";
        cout << endl;
        cout.flush();
        string s;
        getline(cin, s);
        if(s[7]=='G') return 0;
        if(s[15] == '5' && s[16] == ' ') continue;
        len = i;break;
    }
    string pw = "";
    for(int i = 1; i <= len; ++i) {
        bool fd = 0;
        for(int j = 0; j < 26; ++j) {
            cout << pw << (char)(j + 'a');
            for(int k = 1; k <= len - i; ++k) cout << "x";
            cout << endl;
            cout.flush();

            string s;
            getline(cin, s);
            if(s[7]=='G') return 0;
            int num = (s[15]-'0')*10 + s[16]-'0';
            if(isdigit(s[17])) num = num * 10 + s[17] - '0';
            if(num != 5 + 9 * i) {
                pw += (char)(j+'a');
                fd = 1; break;
            }
        }
        if(!fd) {
        for(int j = 0; j < 26; ++j) {
            cout << pw << (char)(j + 'A');
            for(int k = 1; k <= len - i; ++k) cout << "x";
            cout << endl;
            cout.flush();

            string s;
            getline(cin, s);
            if(s[7]=='G') return 0;
            int num = (s[15]-'0')*10 + s[16]-'0';
            if(isdigit(s[17])) num = num * 10 + s[17] - '0';
            if(num != 5 + 9 * i) {
                pw += (char)(j+'A');
                fd = 1; break;
            }
        }
        }
        if(!fd){
        for(int j = 0; j < 10; ++j) {
            cout << pw << (char)(j + '0');
            for(int k = 1; k <= len - i; ++k) cout << "x";
            cout << endl;
            cout.flush();

            string s;
            getline(cin, s);
            if(s[7]=='G') return 0;
            int num = (s[15]-'0')*10 + s[16]-'0';
            if(isdigit(s[17])) num = num * 10 + s[17] - '0';
            if(num != 5 + 9 * i) {
                pw += (char)(j+'0');
                fd = 1; break;
            }
        }
        }
    }
    return 0;
}