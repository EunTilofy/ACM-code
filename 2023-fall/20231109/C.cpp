#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;
vector<string> a[N];
vector<int> lim[N];
int cnt[N];
pair<int, int> tar[N];
int res[N];
vector<int> que;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    string tt;
    getline(cin, tt);
    for (int i = 1; i <= n; i++)
        res[i] = -1;
    int id = 0;
    for (int i = 1; i <= m; ++i)
    {
        string s;
        ++id;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s)
            a[i].push_back(s);
        int inv = 1, y = -1;
        int fl = 0;
        vector<int> f;
        for (auto x : a[i])
        {
            if (x[0] == '-')
            {
                fl = 1;
            }
            else
            {
                inv = 1;
                if (x[0] == '!')
                {
                    inv = 0;
                    x = x.substr(1, x.size() - 1);
                }
                y = stoi(x);
                //       cout<<"get "<<y<<endl;
                if (!fl)
                {
                    f.push_back(y);
                }
                else
                {
                    //           cout<<"addlim "<<id<<"  ";for(auto v:f)cout<<v<<' ';cout<<endl;
                    for (auto v : f)
                        lim[v].push_back(id);
                    tar[id] = {y, inv};
                    cnt[id] = f.size();
                }
            }
        }
        if (!fl)
        {
            if(res[y]>=0&&res[y]!=inv){
                cout << "conflict";
                return 0;
            }
            res[y] = inv;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (res[i] == 1)
        {
            que.push_back(i);
        }
    }
    while (!que.empty())
    {
        int x = que.back();
        //    cout<<"set1 "<<x<<endl;
        que.pop_back();
        for (auto v : lim[x])
        {
            cnt[v]--;
           //       cout<<"dec "<<v<<' '<<cnt[v]<<endl;
            if (cnt[v] == 0)
            {
                if(res[tar[v].first] >= 0){
                    if(res[tar[v].first] != tar[v].second){
                        cout << "conflict";
                        return 0;
                    }
                }
                else{                
                    res[tar[v].first] = tar[v].second;
                    if (tar[v].second == 1)
                    {
                        que.push_back(tar[v].first);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (res[i] <= 0)
            cout << "F";
        else
            cout << "T";
    }
    // stoi(s)
    return 0;
}