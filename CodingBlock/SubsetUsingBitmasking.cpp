#include<bits/stdc++.h>
using namespace std;
  

int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
     for(int x=0;x<(1<<n);x++){
      //for filtering the subsets
          int i=0,j=x;
          while(j>0){
              
              if(j&1){                  
                  cout<<arr[i];                           
              }
              i++;
              j=j>>1;
          }
          cout<<endl;
      }
    return 0;

}