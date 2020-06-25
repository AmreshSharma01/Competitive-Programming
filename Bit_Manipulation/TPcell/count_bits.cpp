//method 1 :using log2(n)+1 in time log(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=10;
    int l=log2(n)+1;
    cout<<l;
    return 0;
}

//method 2
// int countBits(int n){
//     int count=0;
//     while(n){
//         count++;
//         n>>=1;
//     }
//     return count;
// }
// int main(){
//     int n=20;
//     cout<<countBits(n);
// }