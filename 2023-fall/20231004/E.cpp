#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, inf = 2e9;
int n;
int res = 0, ys[N], val[N], st[N], ed[N];
vector<int> G[N];
void dfs(int x) {
    st[x] = ++res, ys[res] = x;
    for(int y : G[x]) {
        dfs(y);
    }
    ed[x] = res;
}

#define ls x << 1
#define rs x << 1 | 1
pair<int, int> tr[N << 2];

pair<int, int> merge(pair<int, int> A, pair<int, int> B) {
    return (A.first < B.first ? A : B);
}

void build(int x, int l, int r) {
    if(l == r) {
        tr[x] = {val[ys[l]], ys[l]};
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    tr[x] = merge(tr[ls], tr[rs]);  
}

void upd(int x, int l, int r, int L) {
    if(l == r) {
        tr[x] = {inf, ys[l]};
        return ;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) upd(ls, l, mid, L);
    else upd(rs, mid + 1, r, L);
    tr[x] = merge(tr[ls], tr[rs]);
}

pair<int, int> get(int x, int l, int r, int L, int R) {
    if(L > R) return {inf, -1};
    if(L <= l && r <= R) {
        return tr[x];
    }
    int mid = (l + r) >> 1;
    if(R <= mid) return get(ls, l, mid, L, R);
    else if(L > mid) return get(rs, mid + 1, r, L, R);
    else return merge(get(ls, l, mid, L, R), get(rs, mid + 1, r, L, R));
}

void work(int l, int r) {
    // cerr << l << " " << r << "\n";
    for(; ;) { 
        pair<int, int> pos = get(1, 1, n, l + 1, r);
        if(pos.first < inf) {
            work(st[pos.second], ed[pos.second]);
        } else break;
    }
    cout << ys[l] << " ";
    upd(1, 1, n, l);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 2, x; i <= n; ++i) {
        cin >> x;
        G[x].push_back(i);
    }
    for(int i = 1; i <= n; ++i) cin >> val[i];
    dfs(1);
    build(1, 1, n);
    // cout << get(1, 1, n, 2, n).first << " " << get(1, 1, n, 2, n).second << "\n";
    // return 0;
    work(1, n);
    return 0;
}