
// CPP program to toggle bits except msb  
#include<bits/stdc++.h> 

using namespace std; 

int setAllBitsAfterMSB(int n) 
{    

    n |= n>>1; 

    n |= n>>2;    

    n |= n>>4;   

    n |= n>>8; 

    n |= n>>16; 

    return n>>1;  //for returning num 111 for 1010
  //return n;   //for returning 1111 for 1010->to give the toggling  
} 

//  void toggle(int &n) {
//      n=n^setAllBitsAfterMSB(n);
//  }
//     OR
int toggle(int n) 
{ 
 n= n ^ setAllBitsAfterMSB(n); 
 return n;
} 

int main() 
{ 

    int n = 5; 

    // toggle(n); 
    // cout << n; 
    //   // OR Directly
    cout<<toggle(n);


    return 0; 
} 