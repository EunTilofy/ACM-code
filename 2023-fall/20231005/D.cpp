#include<bits/stdc++.h>
using namespace std;

vector<pair<int, double>> G[700*700*8];
double d[700*700*8];
int h, w;
void dij() {
    for(int i = 1; i <= h*(3*w+2)+2*w+1; ++i) d[i] = 700*700*10;
    d[1]=0;
    priority_queue<pair<double, int>> q;
    q.push({0, 1});
    while(!q.empty()) {
        auto [dis, x] = q.top();q.pop();
        if(-dis > d[x]) continue;
        for(auto [y, w] : G[x]) if(d[y] > d[x] + w) {
            d[y] = d[x] + w;
            q.push({-d[y], y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    for(int i = 0; i <= h; ++i) {
        int now = i*(2*w+1+w+1);
        for(int j = 1; j <= 2*w+1; ++j) {
            if(j < 2*w+1) {
                G[now+j].push_back({now+j+1, 5});
                G[now+j+1].push_back({now+j, 5});
            }
            if(j%2==1) {
                if(i!=h) {
                    G[now+j].push_back({now+2*w+1+(j+1)/2, 5});
                    G[now+2*w+1+(j+1)/2].push_back({now+j, 5});
                } if(i!=0) {
                    G[now+j].push_back({now-w-1+(j+1)/2, 5});
                    G[now-w-1+(j+1)/2].push_back({now+j, 5});
                }
            }
        }
    }
    double len = acos(-1)*2.50;
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) if(s[i][j] == 'O') {
        int _1 = i*(w*3+2)+2*j+2;
        int _2 = i*(w*3+2)+(2*w+1)+j+2;
        int _3 = (i+1)*(w*3+2)+2*j+2;
        int _4 = i*(w*3+2)+(2*w+1)+j+1;

        G[_1].push_back({_2, len});
        G[_2].push_back({_1, len});

        G[_3].push_back({_2, len});
        G[_2].push_back({_3, len});

        G[_1].push_back({_4, len});
        G[_4].push_back({_1, len});

        G[_3].push_back({_4, len});
        G[_4].push_back({_3, len});
    }

    dij();
    cout << fixed << setprecision(10) << d[h*(3*w+2)+2*w+1] << "\n";
    return 0;
}