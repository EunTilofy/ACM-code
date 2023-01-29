#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int N = 1e5 + 10, mx = 100000;
int a[N], b[N];

#define ls x << 1
#define rs x << 1 | 1

int nm1[N << 2];
//A:0, B:1, AA:2, BB: 3
ll tr1[N << 2][4], rt1[N << 2][4];
void up1(int x) {
    nm1[x] = nm1[ls] + nm1[rs];
    memset(tr1[x], 0, sizeof tr1[x]);
    memset(rt1[x], 0, sizeof rt1[x]);
    if (!nm1[x]) return;
    if (!nm1[ls]) {
        memcpy(tr1[x], tr1[rs], sizeof tr1[x]);
        memcpy(rt1[x], rt1[rs], sizeof rt1[x]);
        return;
    }
    if (!nm1[rs]) {
        memcpy(tr1[x], tr1[ls], sizeof tr1[x]);
        memcpy(rt1[x], rt1[ls], sizeof rt1[x]);
        return;
    }
    {//A BBAA
        int yu = (nm1[x] - 1) % 4, id;
        if (yu == 0) id = nm1[x] > 1 ? 2 : 0;
        else if (yu == 1) id = 1;
        else if (yu == 2) id = 3;
        else if (yu == 3) id = 0;
        tr1[x][0] = rt1[x][id] = tr1[ls][0] + rt1[rs][id];
    }
    {//B AABBAABB
        int yu = (nm1[x] - 1) % 4, id;
        if (yu == 0) id = nm1[x] > 1 ? 3 : 1;
        else if (yu == 1) id = 0;
        else if (yu == 2) id = 2;
        else if (yu == 3) id = 1;
        tr1[x][1] = rt1[x][id] = tr1[ls][1] + rt1[rs][id];
    }
    {//AABBAABB
        int yu = nm1[x] % 4, id;
        if (yu == 0) id = 3;
        else if (yu == 1) id = 0;
        else if (yu == 2) id = 2;
        else if (yu == 3) id = 1;
        tr1[x][2] = rt1[x][id] = tr1[ls][2] + rt1[rs][id];;
    }
    {//BBAABB
        int yu = nm1[x] % 4, id;
        if (yu == 0) id = 2;
        else if (yu == 1) id = 1;
        else if (yu == 2) id = 3;
        else if (yu == 3) id = 0;
        tr1[x][3] = rt1[x][id] = tr1[ls][3] + rt1[rs][id];
    }
}
void build1(int x, int l, int r) {
    if (l == r) {
        nm1[x] = 0;
        memset(tr1[x], 0, sizeof tr1[x]);
        memset(rt1[x], 0, sizeof rt1[x]);
        return;
    }
    int mid = (l + r) >> 1;
    build1(ls, l, mid), build1(rs, mid + 1, r);
    up1(x);
}
void upd1(int x, int l, int r, int L, int k) {
    if (l == r) {
        nm1[x] += k;
        memset(tr1[x], 0, sizeof tr1[x]);
        memset(rt1[x], 0, sizeof rt1[x]);
        // cerr << l << " ! " << k << " " << nm1[x] << "\n";
        if (!nm1[x]) return;
        {//A BBAA
            int yu = (nm1[x] - 1) % 4, id;
            if (yu == 0) id = nm1[x] > 1 ? 2 : 0;
            else if (yu == 1) id = 1;
            else if (yu == 2) id = 3;
            else if (yu == 3) id = 0;
            ll num = 1 + (nm1[x] - 1) / 4 * 2 + max(0, yu - 2);
            tr1[x][0] = rt1[x][id] = num * L;
        }
        {//B AABBAABB
            int yu = (nm1[x] - 1) % 4, id;
            if (yu == 0) id = nm1[x] > 1 ? 3 : 1;
            else if (yu == 1) id = 0;
            else if (yu == 2) id = 2;
            else if (yu == 3) id = 1;
            ll num = (nm1[x] - 1) / 4 * 2 + yu;
            tr1[x][1] = rt1[x][id] = num * L;
        }
        {//AABBAABB
            int yu = nm1[x] % 4, id;
            if (yu == 0) id = 3;
            else if (yu == 1) id = 0;
            else if (yu == 2) id = 2;
            else if (yu == 3) id = 1;
            ll num = nm1[x] / 4 * 2 + min(2, yu);
            tr1[x][2] = rt1[x][id] = num * L;
        }
        {//BBAABB
            int yu = nm1[x] % 4, id;
            if (yu == 0) id = 2;
            else if (yu == 1) id = 1;
            else if (yu == 2) id = 3;
            else if (yu == 3) id = 0;
            ll num = nm1[x] / 4 * 2 + max(0, yu - 2);
            tr1[x][3] = rt1[x][id] = num * L;
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) upd1(ls, l, mid, L, k);
    else upd1(rs, mid + 1, r, L, k);
    up1(x);
}

int nm2[N << 2];
ll tr2[N << 2][2][2];
void up2(int x) {
    nm2[x] = nm2[ls] + nm2[rs];
    memset(tr2[x], 0, sizeof tr2[x]);
    if (!nm2[x]) return;
    if (!nm2[ls]) {
        memcpy(tr2[x], tr2[rs], sizeof tr2[x]);
        return;
    }
    if (!nm2[rs]) {
        memcpy(tr2[x], tr2[ls], sizeof tr2[x]);
        return;
    }
    int nowx = 1 - (nm2[x] & 1), nowls = 1 - (nm2[ls] & 1), nowrs = 1 - (nm2[rs] & 1);
    for (int i = 0; i < 2; ++i) {
        tr2[x][i][i ^ nowx] = tr2[ls][i][i ^ nowls] + tr2[rs][i ^ nowx ^ nowrs][i ^ nowx];
    }
}
void build2(int x, int l, int r) {
    if (l == r) {
        nm2[x] = 0;
        memset(tr2[x], 0, sizeof tr2[x]);
        return;
    }
    int mid = (l + r) >> 1;
    build2(ls, l, mid), build2(rs, mid + 1, r);
    up2(x);
}
void print(int x, int l, int r) {
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) if (tr2[x][i][j]) cerr << x << " " << l << " " << r << " " << tr2[x][i][j] << "\n";
}
void upd2(int x, int l, int r, int L, int k) {
    // cerr << x << " " << l << " " << r << "\n";
    if (l == r) {
        nm2[x] += k;
        int pos = nm2[x] / 2;
        memset(tr2[x], 0, sizeof tr2[x]);
        if (nm2[x] & 1) {
            tr2[x][0][0] = 1ll * L * pos + L;
            tr2[x][1][1] = 1ll * L * pos;
        }
        else {
            tr2[x][0][1] = tr2[x][1][0] = 1ll * L * pos;
        }
        // print(x, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) upd2(ls, l, mid, L, k);
    else upd2(rs, mid + 1, r, L, k);
    up2(x);
    // print(x, l, r);
}

void upd(int x, int k) {
    // cerr << "upd" << x << " " << k << "\n";
    if (x < 0) upd2(1, 1, mx, -x, k);
    else upd1(1, 0, mx, x, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    build1(1, 0, mx), build2(1, 1, mx);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        a[i] = b[i] - a[i], upd(a[i], 1);
        sum += b[i];
    }
    // cerr << rt1[1][0] << " " << tr2[1][nm2[1] & 1][1] << "\n";
    int cur = 1 - (n & 1);
    cout << sum - rt1[1][0] + tr2[1][(1 - (nm2[1] & 1)) ^ cur][cur] << "\n";
    for (int o = 1, t, x, y; o <= m; ++o) {
        cin >> t >> x >> y;
        upd(a[t], -1), sum -= b[t];
        a[t] = y - x, b[t] = y, upd(a[t], 1), sum += b[t];
        // cerr << rt1[1][0] << " " << tr2[1][(1 - (nm2[1] & 1)) ^ cur][cur] << "\n";
        cout << sum - rt1[1][0] + tr2[1][(1 - (nm2[1] & 1)) ^ cur][cur] << "\n";
    }
    return 0;
}
