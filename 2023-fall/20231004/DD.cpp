#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    bool fl = 1;
    for(int i = 1; i < n; ++i) {
        cin >> a[i];
        b[i] = i;
        if(a[i] %2 == 1) fl = 0;
        a[i] /= 2;
    }b[n] = n;
    if(!fl) {
        cout << "No\n";
        return 0;
    }
    // cout << "!";
    vector<int> st;
    a[0] = a[n] = 0;
    for(int i = 1; i <= n; ++i) {
        // cout << a[i] << " ";
        if(a[i]>a[i-1]) {
            if(a[i] > a[i-1] + 1) {
                cout << "No\n";
                return 0;
            }
            st.push_back(i);
        }
        if(a[i]<a[i-1]) {
            if(a[i] < a[i-1] - 1) {
                cout << "No\n";
                return 0;
            }
            swap(b[st.back()], b[i]);
            st.pop_back();
        }
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; ++i) {
        cout << b[i] << " ";
    }
    return 0;
}