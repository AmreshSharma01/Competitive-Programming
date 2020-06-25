
// CPP code to Toggle all even 
// bit of a number 
#include <iostream> 

using namespace std; 

  
// Returns a number which has all even 
// bits of n toggled. 

int evenbittogglenumber(int n) 
{ 

    // Genarate number form of 101010 

    // ..till of same order as n 

    int res = 0, count = 0; 
    // Note for toggling 1 will give 0 as binary of 1 is 1 only.so the following assumption is mistake
    // //for n==1
    // if(n==1){
    //     return 2;
    // }

    for (int temp = n; temp > 0; temp >>= 1) { 

  

        // if bit is even then generate 

        // number and or with res 

        if (count % 2 == 1) 

            res |= (1 << count);       

  

        count++; 

    } 

    cout<<count<<endl;

    // return toggled number 

    //return n ^ res; 
    return res;
} 

  
// Driver code 

int main() 
{ 

    int n = 21; 

    cout << evenbittogglenumber(n); 

    return 0; 
} 