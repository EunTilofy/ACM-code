#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
string s;
vector<int> ans;
void print(vector<int> b) {
    reverse(all(b));
    for (int x : b) cout << x; cout << "\n";
}

vector<int> Add(vector<int> A, vector<int> B) {
    if (A.size() < B.size()) swap(A, B);
    int cur = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (i < B.size()) A[i] += B[i];
        if (A[i] >= 10) {
            if (i + 1 >= A.size()) {
                cur = A[i] / 10;
            }
            else A[i + 1] += A[i] / 10;
            A[i] %= 10;
        }
    }
    if (cur) A.push_back(cur);
    return A;
}
int l, r;
bool cmp(vector<int> A, vector<int> B) {
    if (A.size() < B.size()) {
        return 1;
    }
    else if (A.size() > B.size()) return 0;
    int r = A.size() - 1;
    for (int i = r; ~i; --i) {
        if (A[i] < B[i]) return 1;
        if (A[i] > B[i]) return 0;
    }
    return 0;
}
int _[10];
int dig, k;
void dfs(int nowd, int nowk) {
    if (nowd == dig && nowk == k) {
        vector<int> tmp;
        for (int i = 1; i <= k; ++i) {
            vector<int> pos;
            for (int j = _[i - 1] + 1; j <= _[i]; ++j) pos.push_back(s[j] - '0');
            tmp = Add(tmp, pos);
        }
        if (cmp(tmp, ans)) {
            ans = tmp;
        }
        return;
    }
    if (nowd >= dig || nowk >= k) return;
    if (nowd + r * (k - nowk) < dig) return;
    if (nowd + (k - nowk) * l > dig) return;
    
    for (int i = l; i <= r; ++i) {
        if(nowk && abs(i - (_[nowk]-_[nowk-1])) > 1) continue;
        if (nowd + i > dig || (nowd + i == dig && nowk + 1 < k)) break;
        _[nowk + 1] = nowd + i;
        dfs(nowd + i, nowk + 1);
    }
}

void solve() {
    _[0] = -1;
    int n, kk;
    cin >> n >> kk;
    cin >> s;
    r = n / (kk + 1) + 2;
    l = max(1, r - 3);
    // cout << l << " " << r << endl;
    reverse(s.begin(), s.end());
    ans.clear(); for (char ch : s) ans.push_back(ch - '0');
    dig = n - 1; k = kk + 1;
    dfs(-1, 0);
    print(ans);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}