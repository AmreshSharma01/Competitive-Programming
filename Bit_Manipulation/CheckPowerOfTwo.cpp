// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     while(n%2==0){
//             n=n/2;
//             }
//     if(n==1){
//             cout<<"is power of 2";
//             }
//     else
//         {
//             cout<<"not";
        
//         }
        
    

//     return 0;
// }
// optimized solution using bit manipulation
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int x)
    {
        // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
        return (x && !(x & (x - 1)));
    }
int main(){
    int x;
    cin>>x;
    cout<<boolalpha<<isPowerOfTwo(x);
    return 0;
}

//Naive solution 
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    while(n%2==0){
            n=n/2;
            }
    if(n==1){
            cout<<"is power of 2";
            }
    else
        {
            cout<<"not";
        
        }
        
    

    return 0;
}
*/
