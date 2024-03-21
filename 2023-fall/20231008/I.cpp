#include<bits/stdc++.h>
using namespace std;
const int N=2000001;
int main(){
    static char s[N];
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        int cur=0,fl=1;
        for(int i=n;i>=1;i--){
            if(s[i]==')')cur++;
            else cur--;
            if(cur<0)fl=0;
        }
        if(!fl){
            puts("impossible");
        }
        else{
            printf("%s\n",s+1);
        }
    }
}
