#include<bits/stdc++.h>
using namespace std;
int main(){
    char A[]="Amresh    Sharma";
    //int k=5;
    //int m=1<<5==32
    cout<<"Upper to lower only"<<endl;
    for(int i=0;i<(sizeof(A)/sizeof(A[0]));i++){
        cout<<(char)(A[i] |32);
    }
     cout<<endl<<"lower to upper only"<<endl;
    for(int i=0;i<(sizeof(A)/sizeof(A[0]));i++){
        cout<<(char)(A[i] & (~32));
    }
    //Actual toggle program
     cout<<endl<<"Upper to lower and lower to upper"<<endl;
    for(int i=0;A[i]!='\0';i++){
        cout<<(char)(A[i] ^ 32);
    }
    return 0;
}

/*
// C program to get toggle case of a string 
#include <stdio.h> 

  
// tOGGLE cASE = swaps CAPS to lower 
// case and lower case to CAPS 

char *toggleCase(char *a) 
{ 
    
    for (int i=0; a[i]!='\0'; i++) { 

  

        // Bitwise EXOR with 32 

        a[i] ^= 32; 

    } 

  

    return a; 
} 

  
// Driver Code 

int main() 
{ 
  
    char str[] = "CheRrY"; 
    char *p= toggleCase(str);
    printf("Toggle case: %s\n",p); 

    printf("Original string: %s", toggleCase(str)); 

    return 0; 
} 
*/