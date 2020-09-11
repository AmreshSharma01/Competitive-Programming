#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b;
cin>>a; // suppose a=16 = 10000
cin>>b; // suppose b=20 = 10100
int n=a^b;  // n= 00100
    //the following process returns all set bits , i.e 111 in the example case
    //which is answer for us 
    //i.e the maximum xor  given by the input pairs
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    cout<<n;
    return 0;
}
/*
#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{
    int x,y;
    cin>>x>>y;
    int num = x^y;
    int msb=0;
    while(num!=0) {
        num=num>>1;
        msb++;
    }
    int result = 1;
    while(msb--) {
        result=result<<1;
    }
    cout<<result-1;

    return 0;
}
*/