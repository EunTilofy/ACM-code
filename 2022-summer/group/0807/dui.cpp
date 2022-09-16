#include<bits/stdc++.h>
using namespace std;
int main(){
    system("g++ -g BB.cpp -o BB");
    system("g++ -g bl.cpp -o bl");
    system("BB.exe>1.txt");
    system("bl.exe>2.txt");
    system("fc 1.txt 2.txt");
    return 0;
}