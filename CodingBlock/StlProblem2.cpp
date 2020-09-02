#include<bits/stdc++.h>
using namespace std;

int main(){
  int n1;
  int no1,no2;
  cin>>n1;
  vector<int>v1(n1),v2(n1);
  v1.reserve(n1);
  v2.reserve(n1);
  //taking input
   for(auto &x:v1){
    cin>>x;
  }  
    for(auto &y:v2){
    cin>>y;
  }  
//   v1.shrink_to_fit();
//   v2.shrink_to_fit();
  //merging two vectors
v1.insert(v1.end(),v2.begin(), v2.end());
//v1.shrink_to_fit();
sort(v1.begin(),v1.end());
// for(int x:v1){
//   cout<<x<<" ";
// }
// cout<<endl;
//finding median
double median=ceil((v1.size())/2.0);
//cout<<median<<endl;  //included in <cmath> header file
cout<<v1[median-1];
return 0;

}