#include<bits/stdc++.h>
using namespace std;
vector<int> largestPermutation(vector<int> &v,int n,int k){
    if(k>=n){
        sort(v.begin(),v.end(),greater<int>());
        return v;
    }
    int start={}; //int start=0;
        while(k){
            
            int maxElementIndex=max_element(v.begin()+start,v.end()) - v.begin();
            if(start!=maxElementIndex){
                swap(v[start],v[maxElementIndex]);
                k--;
            }
            start++;

        }
        return v;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &x:v){
        cin>>x;
    }
    largestPermutation(v,n,k);
     for(auto &x:v){
        cout<<x<<" ";
    }
    return 0;
}