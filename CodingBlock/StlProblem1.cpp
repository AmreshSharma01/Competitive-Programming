#include<bits/stdc++.h>
#include<cstring>
using namespace std;

bool Compare(string &str1,string &str2){
  //if 1st string is substring of 2nd one 
  if((str1.size()<=str2.size()) && (str2.substr(0,str1.size()) ==str1)){
    // return str2>str1;
    return false;
  }
  //if 2nd string is substring of 1st one 
  else if((str2.size()<=str1.size()) && (str1.substr(0,str2.size()) ==str2)){
    // return str2>str1;
      return true;
  }
  else{
  return str1<str2;
}
}
// bool Compare(string &str1,string &str2){
//   if(str1.find(str2)!=string::npos){
//     return str1.length()>str2.length();
//      //return true;
//   }
//   return str1<str2;
// }
int main(){
  int N;
  cin>>N;
  vector<string> v(N);
  for(auto &Everystr:v){
    cin>>Everystr;
  }
  sort(v.begin(),v.end(),Compare);
  cout<<endl;
  for(auto Everystr:v){
    cout<<Everystr<<endl;
  }
  return 0;

}