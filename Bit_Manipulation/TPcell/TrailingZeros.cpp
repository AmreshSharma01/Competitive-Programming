#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=15;
    int count=0,res;
    while(n!=0){
        res=n%2;
        if(res==0)
             count++;
        if(res==1)
            break;
        n=n/2;
    }
    cout<<count;
}