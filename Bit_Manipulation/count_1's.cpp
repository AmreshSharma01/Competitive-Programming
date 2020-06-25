//Naive solution for counting number of 1's in a binary representation of a number
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,rem,count=0;
//     cin>>n;
//     while(n>0){
//         rem=n%2;
//         n/=2;
//         if(rem==1){
//             count++;
//         }
//     }
//     cout<<"No. of ones ="<<count;
// }
// optimized solution

#include<bits/stdc++.h>
using namespace std;

int count_one (int n)
        {   
            int count=0;
            while( n )
            {
            n = n&(n-1);
               count++;
            }
            return count;
    }
int main(){
    int n;
    cin>>n;
    cout<<count_one(n);
}