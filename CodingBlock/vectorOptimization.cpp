#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v{1,2,3,4,5};
    vector<int> v1;
    //for optimization of memory 
            v.reserve(100);
            v1.reserve(500);
            
    v.push_back(7);
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        v1.push_back(no);
        cout<<"capacity is changing as :"<<v1.capacity()<<endl;
    }
    //to destroy the unused memory ,we use shrinnk_to_fit()
    v.shrink_to_fit();
    v1.shrink_to_fit();

    cout<<v.size()<<" "<<v.capacity()<<endl;
    cout<<v1.size()<<" "<<v1.capacity()<<endl;
    v.resize(9);
    v.push_back(87);
    v.push_back(87);
    v.push_back(87);
    v.push_back(87);
    v.push_back(87);
    v.push_back(87);
    v.push_back(87);
    cout<<v.size()<<" "<<v.capacity();
   
    return 0;
}
