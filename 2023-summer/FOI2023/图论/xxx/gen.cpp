#include<bits/stdc++.h>
using namespace std;

int fa[1000000];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
std::random_device rd;
std::mt19937 g(rd());

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n, m1, m2, d;
    cin >> s >> n >> m1 >> m2 >> d;

    ofstream out;
    out.open(s+".in");
    
    out << n << " " << m1 << " " << m2 << " " << d << "\n";
    vector<int> a;
    for(int i = 1; i <= n; ++i) a.push_back(i);
    shuffle(a.begin(), a.end(), g);
    for(int i = 0; i < m1; ++i) out << a[i] << " ";out << "\n";
    shuffle(a.begin(), a.end(), g);
    for(int i = 0; i < m2; ++i) out << a[i] << " ";out << "\n";

    for(int i=1;i<=n;i++) fa[i]=i;int cnt=0;
    while(cnt<n-1){
        unsigned int x=g(),y=g();
        x=x%n+1;
        y=y%n+1;
        int x1=find(x),y1=find(y);
        if(x1!=y1) {
            fa[x1]=y1,cnt++,out<<x<<" "<<y<<"\n";
        }
    }

    out.close();
    system(("./run < " + s+".in > " + s + ".out").c_str());


    return 0;
}