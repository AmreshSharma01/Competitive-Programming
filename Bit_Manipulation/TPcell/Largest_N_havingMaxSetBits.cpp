//Approach 1:
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=7;
    int l=log2(n)+1;   // l returns no.of total bits in a number
    int ans=(1<<(l-1))-1;
    cout<<ans;
    return 0;
}


//Naive approach

/* 

// CPP implementation to Find the 
// largest number smaller than integer 
// N with maximum number of set bits 
#include <bits/stdc++.h> 

using namespace std; 

  
// Function to return the largest 
// number less than N 

int largestNum(int n) 
{ 

    int num = 0; 

  

    int max_setBits = 0; 

  

    // Iterate through all the numbers 

    for (int i = 0; i <= n; i++) { 

  

        // Find the number of set bits 

        // for the current number 

        int setBits = __builtin_popcount(i); 

  

        // Check if this number has the  

        // highest set bits 

        if (setBits >= max_setBits) { 

            num = i; 

            max_setBits = setBits; 

        } 

    } 

  

    // Return the result 

    return num; 
} 

  
// Driver code 

int main() 
{ 

    int N = 345; 

  

    cout << largestNum(N); 

  

    return 0; 
} 
 
 */