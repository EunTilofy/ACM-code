#include<bits/stdc++.h>
using namespace std;

int f[100005][10];
// -4 ~ 4 (+5)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        string s, t;
        cin >> s >> t;
        int fl = 0;
        int len1 = s.size(), len2 = t.size();
        if(abs(len1 - len2) > 3) {
            cout << "What you entered is too different from the real password.";
            if(n) cout << "\n";
            continue;
        }
        else {
            for(int i = 0; i <= len1; ++i) for(int j = 0; j <= 9; ++j) f[i][j] = 1000000;
            f[0][0 + 5] = 0;
            f[0][1 + 5] = 1;
            f[0][2 + 5] = 2;
            f[0][3 + 5] = 3;
            for(int i = 1; i <= len1; ++i) for(int j = -3; j <= 3; ++j) if(i+j>=0&&i+j<=len2) {
                if(i+j-1>=0) f[i][j+5] = min(f[i][j+5], f[i][j-1+5] + 1);
                if(i+j-1>=0) f[i][j+5] = min(f[i][j+5], f[i-1][j+5]+(s[i-1]!=t[i+j-1]));
                f[i][j+5] = min(f[i][j+5], f[i-1][j+1+5] + 1);
            }
            int ans = f[len1][len2-len1+5];
            if(ans == 0) cout << "You're logged in!";
            if(ans == 1) cout << "You almost got it. You're wrong in just one spot.";
            if(ans == 2) cout << "You almost got it, but you're wrong in two spots.";
            if(ans == 3) cout << "You're wrong in three spots.";
            if(ans > 3) cout << "What you entered is too different from the real password.";
            if(n) cout << "\n";
        }
    }
}

/*
You're logged in!
You almost got it. You're wrong in just one spot.
You almost got it, but you're wrong in two spots.
You're wrong in three spots.
What you entered is too different from the real password.
*/