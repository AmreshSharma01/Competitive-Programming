// The .find() method returns string::npos if it did not find the target string within the searched string. 
// It is an integer whose value cannot represent a "found" index value, usually -1.
//  A valid index value is an integer >= 0 which represents the index at which the target string was found.
#include <iostream>
using namespace std;

int main() {
  
  string str2 = "app";
  string str = "an apple";
  // cout<<string::npos<<endl;
  
  int found=str.find(str2);

//   if (!(found == string::npos)){
//     cout << "first 'app' found at: " << int(found) << endl;
//   }
// }
cout<<found<<endl;
  if (found!= string::npos){
    cout << "first 'app' found at: " << int(found) << endl;
  }
}