#include<bits/stdc++.h>
using namespace std;

const int MN = 2505;

set<pair<int,int>> __edges;
int __cnt;
void add(int x, int y) {
    if(x == y) return;
    if(y < x) swap(x, y);
    if(__edges.count({x, y}) == 0) ++__cnt;
    __edges.insert({x, y});
}
void print_answer() {
    cout << "! ";
    for(auto [x, y] : __edges) cout << x << " " << y << " ";
    cout << std::endl;
    fflush(stdout);
}
bool check_correct() {
    string s;
    cin >> s;
    if(s != "Correct") return 0;
    return 1;
}

std::map<pair<int,int>, int> info;
int fa[MN], id_to_fa[MN];
int cur[MN]; // current edge
int D[MN]; // use straightly !!!

int last_id; int now;
void move(int id) {
    // cerr << "move from " << now << " use edge_id : " << id << "\n";
    cout << "> " << id << std::endl;
    fflush(stdout);
    int x, d;
    cin >> x >> d;
    D[x] = d;
    if(now != 0) {
        add(now, x);
        info[{now, x}] = id;
    }
    now = x;
}

int get_pos() {
    return now;
}

bool vis[MN];
void ON_clear() {
    __cnt = 0; now = 0; last_id = 0;
    __edges.clear();
    for(int i = 0; i <= 2500; ++i) {
        D[i] = 0;
        fa[i] = 0;
        id_to_fa[i] = 0;
        cur[i] = 0;
        vis[i] = 0;
    }
    info.clear();
}

// 1, move(id) (> id)
// 2, get_pos() -> int // cin >> pos
int root;
void dfs(int x) {
    vis[x] = 1;
    // cerr << "step in " << x << " with cur_cnt : " << cur[x] << "\n";
    while(cur[x] < D[x]) {
        ++cur[x];
        move(cur[x]);
        int y = get_pos();
        if(!vis[y]) {
            fa[y] = x;
            dfs(y);
            return;
        } else {
            if(y == fa[x]) {
                id_to_fa[x] = cur[x];
                move(info[{y, x}]); // come back
            } else {
                dfs(y);
                return;
            }
        }
    }
    if(x == root) return;
    else {
        move(id_to_fa[x]);
        dfs(fa[x]);
    }
}

void solve() {
    ON_clear();
    cin >> root; cin >> D[now = root];
    dfs(root);
    print_answer();
    assert(check_correct());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}