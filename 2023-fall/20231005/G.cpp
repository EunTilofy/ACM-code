#include<bits/stdc++.h>
using namespace std;
int x;

int move_left(){
    cout<<"? left"<<endl;
    cin>>x;
    return x;
}
int move_right(){
    cout<<"? right"<<endl;
    cin>>x;
    return x;
}
int set_bit(int p){
    if(x!=p){
        cout<<"? flip"<<endl;
        cin>>x;
        return 1;
    }
    return 0;
}

/*
int p=0,C=50;
int a[100];
int move_left(){
  //  cout<<"left"<<endl;
    p=(p-1+C)%C;
    x=a[p];
    return a[p];
}
int move_right(){
    
 //   cout<<"right"<<endl;
    p=(p+1+C)%C;
    x=a[p];
    return a[p];
}
int set_bit(int po){
    if(x!=po){
        
  //  cout<<"flip"<<endl;
        a[p]^=1;
        x=a[p];
        return 1;
    }
    return 0;
}
*/

int check(int mid){
    for(int i=1;i<=mid;i++){
        set_bit(0);
        move_right();
    }
    int ans=(x==0);
    for(int i=1;i<=mid;i++){
        move_left();
        set_bit(1);
    }
    return ans;
}

int main(){
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>x;
    for(int i=1;i<=25;i++){
        set_bit(1);
        move_left();
    }
    int l=3,r=25,mid=-1,res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))res=mid,r=mid-1;
        else l=mid+1;
    }
    if(res!=-1){
        cout<<"! "<<res<<endl;
        return 0;
    }
    int mod=0;
    for(int i=0;i<25;i++){
        int cur=rand()%2;
        mod<<=1;
        if(cur)mod|=1;
        set_bit(cur);
        move_right();
    }
    int my=0,cnt=0;
    while(1){
        my<<=1;
        my|=x;
        my&=((1<<25)-1);
        cnt++;
        if(cnt>=16000)assert(0);
        move_right();
        if(my==mod){
            cout<<"! "<<cnt<<endl;
            return 0;
        }
    }
}