// Implementation of remove_if() function 
// to remove all the even for list1
// and prime numbers for list2
#include <iostream> 
#include <list> 
using namespace std; 

// Predicate implemented as a function 
bool even(int& value) {
     return (value &1)==0;
     // or use: return (value%2==0)?true:false;
     } 
bool prime(const int & value){
    if(value<=1){
        return false;
    } 
    for(int i=2;i<=value/2;i++){
        if(value%i==0){
            return false;
        }
    }
    return true;

}
void showlist(list<int> &l){
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << ' ' << *it; 
    }
}

// Main function 
int main() 
{ 
	list<int> mylist{ 1, 2, 2, 2, 5, 6, 7 }; 
	list<int> mylist2{ 1, 2, 3, 5,4, 6, 7,8,9,11 }; 
	mylist.remove_if(even); 
	mylist2.remove_if(prime); 
	showlist(mylist);
    cout<<endl;
	showlist(mylist2);
    return 0;
}
