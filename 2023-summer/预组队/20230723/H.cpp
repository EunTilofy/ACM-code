#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
struct node {
    int id, val;
    int c[4];
} a[4], b[4];
string S[4] = {"Russia","Sweden","Finland","NA"};

int G[4][4], V[4][4];

int flg1 = 1, flg2 = 0;
bool pd() {
    // for (int i = 0; i < 4; ++i) {
    //     cerr << S[i] << " " << b[i].val << " ";
    //     for (int j = 0; j < 4; ++j)
    //         cerr << b[i].c[j] << " ";
    //     cerr << "\n";
    // }
    vector<pair<int, int> > q(4);
    for (int i = 0; i < 4; ++i) {
        q[i] = {b[i].val,i};
    }
    sort(all(q)), reverse(all(q));
    vector<node> p;
    int cnt = 0;
    for (int i = 0; i < 2; ++i) {
        int j = i;
        for (; j + 1 < 4 && q[j + 1].first == q[j].first; ++j);
        if (i == j) {
            if (q[i].second == 0) return true;
            ++cnt;
        }
        else {
            for (int k = i; k <= j; ++k) {
                p.push_back(b[q[k].second]);
            }
        }
        i = j;
    }
    int t = -1;
    for (auto x : p) if (!x.id) t = 0;
    if (t == -1) return false;
    if (p.size() == 2) {
        int iw = V[p[0].id][p[1].id] ? p[0].id : p[1].id;
        int il = V[p[0].id][p[1].id] ? p[1].id : p[0].id;
        if (!iw) return true;
        if (!il && cnt + 2 <= 2) return true;
        return false;
    }
    else {
        // cerr << "!!!\n";
        for (int o = 0; o < 4; ++o) {
            vector<pair<int, int>> Q;
            for (auto x : p) Q.push_back({x.c[o],x.id});
            sort(all(Q)), reverse(all(Q));
            int sz = 2 - cnt;
            for (int i = 0; i < min(sz, (int)Q.size()); ++i) {
                int j = i;
                for (; j + 1 < Q.size() && Q[i].first == Q[j + 1].first; ++j);
                if (i == j) {
                    ++cnt;
                    if (!Q[i].second && cnt <= 2) return true;
                }
                else if (j - i == 1) {
                    int ix = Q[i].second, iy = Q[i + 1].second;
                    int iw = V[ix][iy] ? ix : iy;
                    int il = V[ix][iy] ? iy : ix;
                    if (!iw && cnt + i + 1 <= 2) return true;
                    if (!il && cnt + i + 2 <= 2) return true;
                    return false;
                }
                else {
                    // cerr << "???\n";
                    vector<node> P;
                    for (int k = i; k <= j; ++k) {
                        P.push_back(b[Q[k].second]);
                    }
                    p = P;
                }
                i = j;
            }
        }
        if (cnt <= 1) {
            for (auto x : p) if (!x.id) {
                flg1 = 0, flg2 = 1;
                return false;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(G, -1, sizeof G);
    for (int i = 0; i < 4; ++i) {
        a[i].id = i;
        a[i].val = 0;
        for (int j = 0; j < 4; ++j) a[i].c[j] = 0;
    }
    for (int o = 1; o <= 6; ++o) {
        string s;
        getline(cin, s);
        int n = s.size();
        vector<string> v;
        for (int i = 0; i < n; ++i) {
            int j = i;
            string t = ""; t += s[i];
            for (; j + 1 < n && s[j + 1] != ' '; ++j) t += s[j + 1];
            v.push_back(t);
            i = j + 1;
        }
        vector<int> q(2), p(2);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 4; ++j) if (v[i] == S[j]) {
                q[i] = j;
            }
        }
        if (o == 6) {
            // for (int i = 0; i < 4; ++i) {
            //     cerr << S[i] << " " << a[i].val << " ";
            //     for (int j = 0; j < 4; ++j)
            //         cerr << a[i].c[j] << " ";
            //     cerr << "\n";
            // }
            // for (int i = 1; i <= 1; ++i) for (int j = 0; j <= 0; ++j) {
            //     for (int e = 0; e < 4; ++e) b[e] = a[e];
            //     for (int e = 0; e < 4; ++e)for (int r = 0; r < 4; ++r) V[e][r] = G[e][r];

            //     p[0] = i, p[1] = j;
            //     for (int i : {0, 1}) b[q[i]].c[3] += p[i], b[q[i]].c[2] += p[i] - p[i ^ 1];
            //     int idw = p[0] > p[1] ? 0 : 1;
            //     b[q[idw]].c[0]++, b[q[idw]].c[1]++, b[q[idw]].val += 2;
            //     V[q[idw]][q[idw ^ 1]] = 1, V[q[idw ^ 1]][q[idw]] = 0;
            //     if (pd()) flg2 = 1;
            //     else flg1 = 0;
            // }
            // if (flg1) cout << "Already in playoff!\n";
            // else if (flg2) cout << "Believe in playoff!\n";
            // else cout << "No chance\n";
            // return 0;
            for (int i = 0; i <= 100; ++i) for (int j = 0; j <= 100; ++j) {
                for (int e = 0; e < 4; ++e) b[e] = a[e];
                for (int e = 0; e < 4; ++e)for (int r = 0; r < 4; ++r) V[e][r] = G[e][r];

                p[0] = i, p[1] = j;
                for (int i : {0, 1}) b[q[i]].c[3] += p[i], b[q[i]].c[2] += p[i] - p[i ^ 1];
                int idw = p[0] > p[1] ? 0 : 1;
                b[q[idw]].c[0]++, b[q[idw]].c[1]++, b[q[idw]].val += 2;
                V[q[idw]][q[idw ^ 1]] = 1, V[q[idw ^ 1]][q[idw]] = 0;
                if (pd()) flg2 = 1;
                else flg1 = 0;
            }
            for (int i = 0; i <= 100; ++i) for (int j : {-1, 1}) if (i + j >= 0) {
                for (int e = 0; e < 4; ++e) b[e] = a[e];
                for (int e = 0; e < 4; ++e)for (int r = 0; r < 4; ++r) V[e][r] = G[e][r];

                p[0] = i, p[1] = i + j;
                for (int i : {0, 1}) b[q[i]].c[3] += p[i], b[q[i]].c[2] += p[i] - p[i ^ 1];
                int idw = p[0] > p[1] ? 0 : 1;
                b[q[idw]].c[0]++, b[q[idw]].val += 2, b[q[idw ^ 1]].val += 1;
                V[q[idw]][q[idw ^ 1]] = 1, V[q[idw ^ 1]][q[idw]] = 0;
                if (pd()) flg2 = 1;
                else flg1 = 0;
            }
            if (flg1) cout << "Already in playoff!\n";
            else if (flg2) cout << "Believe in playoff!\n";
            else cout << "No chance\n";
            return 0;
        }
        for (int i = 2; i < 4; ++i) {
            p[i - 2] = stoi(v[i]);
        }
        // cerr<<S[q[0]]<<" "<<S[q[1]]<<" "<<p[0]<<" "<<p[1]<<"\n";
        for (int i : {0, 1}) a[q[i]].c[3] += p[i], a[q[i]].c[2] += p[i] - p[i ^ 1];
        int idw = p[0] > p[1] ? 0 : 1;
        a[q[idw]].c[0]++, a[q[idw]].val += 2;
        if (v.size() < 5) a[q[idw]].c[1]++;
        else a[q[idw ^ 1]].val += 1;
        G[q[idw]][q[idw ^ 1]] = 1, G[q[idw ^ 1]][q[idw]] = 0;
    }
    return 0;
}
