#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int arr[]={1,4,4,4,6,8,10};
    int n=sizeof(arr)/sizeof(int);
    bool present=binary_search(arr,arr+n,4);
    if(present){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    int* lb=lower_bound(arr,arr+n,4);
    int* ub=upper_bound(arr,arr+n,4);
    cout<<endl<<*lb<<endl<<*ub;
    int index=lb-arr;
    int index1=ub-arr;
    int fre=ub-lb;
    cout<<endl<<index<<endl<<index1<<endl<<fre<<endl;
    auto it=find(arr,arr+n,44);
  // cout<<it-arr;
    return 0;
}
