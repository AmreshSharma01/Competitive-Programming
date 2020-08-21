//advance() for iterating list,vector,etc
#include <iostream>
#include <iterator> //for advance(it,n)
#include <list>
#include <vector>
using namespace std;
 
int main() 
{
    list<int> l{ 3, 1, 4,6,4,3,24,4222 };
    vector<int> v{ 3, 1, 4,6,4,3,24,4222 };
 
    auto it  = l.begin();
    auto it2  = v.begin();
    int n;
    //enter the position to find its iteartion
    cin>>n;
 
    advance(it, n); //time complexity:O(n) for list as it allows non-contiguous memory allocation
    advance(it2, n); //time complexity:O(1) for vetor as it allows contiguous memory allocation

    cout <<"list iteration:"<< *it << '\n';
    cout << "vector iteration:"<<*it2 << '\n';
    
}