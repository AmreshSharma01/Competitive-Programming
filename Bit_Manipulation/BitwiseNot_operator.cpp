//Toggle all the bits of a number except k-th bit.
#include<iostream>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;
 int main(){
    int n=5,test=-5;
    int k=1;
     int m=~(n^(1<<k));
    //cout<<bitset<4>{m};
    cout<<m<<endl;
    cout<<"Ans:"<<~m;
    cout<<endl<<~test;
    
    return 0;

 }
