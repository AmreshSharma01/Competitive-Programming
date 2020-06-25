#include<iostream>
using namespace std;
int main(){
    int n,count=0;
    cin>>n;
    for(int i=0;i<=n;i++)
        if((n+i)==(n^i))
            count+=1;
    cout<<count;
    return 0;
}