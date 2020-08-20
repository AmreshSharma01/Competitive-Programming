
#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
    list <string>li{"aks","pks","hi","daju"};
    li.push_back("nsk");

    for(string s:li){
        cout<<s<<"-->";
    }
    cout<<endl;
    li.reverse();
     for(string s:li){
        cout<<s<<"-->";
    }
    cout<<endl;
    auto it =li.begin();
    it++;
    it++;
    li.erase(it);

//inserting at asked position
    it=li.begin();
    int pos;
    cin>>pos;
    while(pos!=0){
        it++;
        pos--;
    }
     li.insert(it,"previousInserted");
     li.insert(it,"jfdskjlds");
     li.insert(it,"nextInserted");
     for(string s:li){
        cout<<s<<"-->";
    }
   
    return 0;
}
