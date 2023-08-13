#include<bits/stdc++.h>
using namespace std;

const int MN = 2005;
bool Line[MN][MN<<2]; int pL[MN];
bool Row[MN][MN<<2]; int pR[MN];
bool Dia[MN*2][MN<<2]; int pD[MN];
pair<int,int> a[14];
int f[MN][MN];

void init() {
    for(int i = 1; i <= 2000; ++i) for(int j = 1; j <= 2000; ++j) {
        int _dia = i - j + 2000;
        int mex = max(pD[_dia], max(pL[i], pR[j]));
        while(Line[i][mex] || Row[j][mex] || Dia[_dia][mex] 
            || (i>1&&j>2&&f[i-1][j-2]==mex) || (i>2&&j>1&&f[i-2][j-1]==mex)) ++mex;
        f[i][j] = mex;
        Line[i][mex] = 1;
        Row[j][mex] = 1;
        Dia[_dia][mex] = 1;
        while(Line[i][pL[i]] == 1) ++pL[i];
        while(Row[j][pR[j]] == 1) ++pR[j];
        while(Dia[_dia][pD[_dia]] == 1) ++pD[_dia];
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    int T;
    cin >> T;
    while(T--) {
        int k;
        cin >> k;
        for(int i = 1; i <= k; ++i) cin >> a[i].first >> a[i].second;
        int all = 0;
        for(int i = 1; i <= k; ++i) all ^= f[a[i].first][a[i].second];
        if(all == 0) {
            cout << "-1 -1 -1\n";
        } else {
            pair<int,pair<int,int>> ans = {k, {2000, 2000}};
            for(int id = 1; id <= k; ++id) {
                int x = a[id].first;
                int y = a[id].second;
                for(int i = 1; i < x; ++i) if((all^f[x][y]^f[i][y]) == 0) ans = min(ans, {id, {i, y}});
                for(int j = 1; j < y; ++j) if((all^f[x][y]^f[x][j]) == 0) ans = min(ans, {id, {x, j}});
                for(int i = 1; i < x && i < y; ++i) if((all^f[x][y]^f[x-i][y-i]) == 0) ans = min(ans, {id, {x-i, y-i}});
                if(x>2&&y>1&&(all^f[x][y]^f[x-2][y-1])==0) ans=min(ans, {id, {x-2, y-1}});
                if(x>1&&y>2&&(all^f[x][y]^f[x-1][y-2])==0) ans=min(ans, {id, {x-1, y-2}});
            }
            // std::cout << ans.get_first() << " " << ans.get_second << " " << ans.get_third << "\n";
            // tuple<int,int,int> [aa,bb,c] = ans;
            cout << ans.first << " " << ans.second.first << " " << ans.second.second << "\n";
            // std::cout << (int)aa << " " << (int)bb << " " << (int)c << "\n";
        }
    }
    return 0;
}