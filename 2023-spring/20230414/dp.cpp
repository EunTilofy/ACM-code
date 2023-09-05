#include<bits/stdc++.h>
using namespace std;
int main() {
    system("g++ data.cpp -o data --std=c++20");
    system("g++ Cbl.cpp -o cbl");
    system("g++ C.cpp -o C --std=c++20");
    while(1) {
        system("data > data.txt");
        system("C < data.txt > C.txt");
        system("cbl < data.txt > cbl.txt");
        if(system("fc C.txt cbl.txt")) break;
    }
}