#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int ind[N];
pair<int,int>tag[N];
vector<pair<int,int>>e[N];
int all = 0;
set<pair<int, tuple<int,int,int>>> Ring;
pair<int, tuple<int,int,int>> ring[N*3];
vector<int> res[N];
int ord(int x,int v){
    return (ind[x]>ind[v]||(ind[x]==ind[v]&&x>v));
}
map<pair<int,int>, int> MP;
set<pair<int, tuple<int,int,int>>> rings[N];
void report(int x,int y,int z,int val){
    if(x > y) swap(x, y);
    if(x > z) swap(x, z);
    if(y > z) swap(y, z);
    int mpxy = MP[{x, y}], mpyz = MP[{y, z}], mpxz = MP[{x, z}];
    rings[mpxy].insert({-val, {x, y, z}});
    if(rings[mpxy].size() > 3) {
        rings[mpxy].erase(*rings[mpxy].rbegin());
    }
    rings[mpyz].insert({-val, {x, y, z}});
    if(rings[mpyz].size() > 3) {
        rings[mpyz].erase(*rings[mpyz].rbegin());
    }
    rings[mpxz].insert({-val, {x, y, z}});
    if(rings[mpxz].size() > 3) {
        rings[mpxz].erase(*rings[mpxz].rbegin());
    }
}
void dfs2(int x){
    for(auto [v,val]:e[x]){
        if(!ord(x,v))continue;
        tag[v]={x,val};
    }
    for(auto [v,val]:e[x]){
        if(!ord(x,v))continue;
        for(auto [v2,val2]:e[v]){
            if(!ord(v,v2))continue;
            if(tag[v2].first==x){
                report(x,v,v2,tag[v2].second+val+val2);
            }
        }
    }
}
int cnt[N];
int solve(int x) {
    vector<tuple<int,int,int>> ri;
    int now=0;
    for(auto &id : res[x]) {
        auto [xx, yy, zz] = ring[id].second;
        if(yy == x) swap(xx, yy);
        if(zz == x) swap(zz, xx);
        if(cnt[yy] < 3 || cnt[zz] < 3) {
            ++cnt[yy];
            ++cnt[zz];
            ri.push_back({yy, zz, -ring[id].first});
            ++now;
        }
        if(now >= 6) break;
    }
    int ans = -1;
    for(int i = 0; i < ri.size(); ++i) {
        for(int j = i+1; j < ri.size(); ++j) {
            auto [xi, yi, vali] = ri[i];
            auto [xj, yj, valj] = ri[j];
            if(xi!=xj&&yi!=xj&&xi!=yj&&yi!=yj)
                ans=max(ans, vali+valj);
        }
    }
    for(auto [xx, yy, val] : ri) --cnt[xx], --cnt[yy];
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        e[x].push_back({y,z});
        e[y].push_back({x,z});
        MP[{min(x, y), max(x, y)}] = i;
        ind[x]++;
        ind[y]++;
    }
    for(int i=1;i<=n;i++){
        dfs2(i);
    }
    for(int i = 1; i <= m; ++i)
        for(auto x : rings[i]) Ring.insert(x);
    for(auto x : Ring) {
        ring[++all] = x;
    }
    Ring.clear();
    for(int i = 1; i <= all; ++i) {
        auto [x, y, z] = ring[i].second;
        res[x].push_back(i);
        res[y].push_back(i);
        res[z].push_back(i);
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(i));
    }
    printf("%d\n",ans);

}