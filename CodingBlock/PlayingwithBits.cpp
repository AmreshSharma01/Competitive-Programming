#include<bits/stdc++.h>
using namespace std;
int CountSetBits(int n){
    int count=0;
    while(n){
    n=n&(n-1);
    count++;
    }
    return count;
}

int main(){
    int T,a,b;
    cin>>T;
    while(T--){
        int sum=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++){
            sum+=CountSetBits(i);
        }
        cout<<sum<<endl;
    }


    return 0;
}