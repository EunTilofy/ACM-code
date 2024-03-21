#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int ok[N],wrong[N][N];
char pos[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        string s,t;
        cin>>s>>t;
        for(int j=0;j<m;j++){
            if(t[j]=='G'){
                pos[j]=s[j];
                ok[s[j]-'a']=2;
            }
            else if(t[j]=='Y'){
                ok[s[j]-'a']=max(ok[s[j]-'a'],1);
                wrong[s[j]-'a'][j]=1;
            }
            else ok[s[j]-'a']=-1;
        }
    }
    vector<int>cur;
    for(int i=0;i<26;i++){
        if(ok[i]==1)cur.push_back(i),ok[i]=2;
    }
    for(int i=0;i<m;i++){
        if(!pos[i]&&!cur.empty()){
            pos[i]=cur.back()+'a';
            cur.pop_back();
        }
    }
    
    for(int i=0;i<26;i++){
        if(ok[i]==0)cur.push_back(i);
    }
    for(int i=0;i<m;i++){
        if(!pos[i]&&!cur.empty()){
            pos[i]=cur.back()+'a';
            cur.pop_back();
        }
    }
    
    for(int i=0;i<m;i++){
        if(!pos[i]){
            for(int j=0;j<26;j++){
                if(ok[j]==2&&!wrong[j][i]){
                    pos[i]=j+'a';
                }
            }
        }
    }
    
    for(int i=0;i<m;i++)cout<<pos[i];
}