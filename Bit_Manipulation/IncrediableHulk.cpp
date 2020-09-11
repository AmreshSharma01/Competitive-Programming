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
    int T,no;
    cin>>T;
    while(T--){
        cin>>no;
        // int ans=CountSetBits(no);
        // cout<<ans<<endl;
        cout<<CountSetBits(no)<<endl;
    }


    return 0;
}
