
// Simple CPP program to find MSB number 
// for given n and largest power of 2. 
#include <iostream> 

using namespace std; 

  

int setBitNumber_position(int n) 
{ 

    if (n == 0) 

        return 0; 

  

    int msb = 0; 

    while (n != 0) { 

        n = n / 2; 

        msb++; 

    } 

  

   // return (1<<(msb-1)); //for largest power of two 
     return (msb);  //for most significant set bit position
} 

  
// Driver code 

int main() 
{ 

    int n = 8; 

    cout << setBitNumber_position(n); 

    return 0; 
} 

//Next Approach


// CPP program to find MSB 
// number for given n. 
// #include <bits/stdc++.h> 

// using namespace std; 

  

// int setBitNumber(int n) 
// { 

  

//     // To find the position 

//     // of the most significant 

//     // set bit 

//     int k = (int)(log2(n)); 

  

//     // To return the the value 

//     // of the number with set 

//     // bit at k-th position 

//     // return (int)(pow(2, k)); 
//     return k;
// } 

  
// // Driver code 

// int main() 
// { 

//     int n = 10; 

//     cout << setBitNumber(n); 

//     return 0; 
// } 