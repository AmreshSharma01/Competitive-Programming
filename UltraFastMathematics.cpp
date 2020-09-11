#include<bits/stdc++.h>
using namespace std;

int main(){
int T;
cin>>T;
while(T--){
    string s1,s2;
    cin>>s1>>s2;
    char final_key[s1.size()];
    for(int i = 0; i<s1.size(); i++)
    {
        final_key[i] = (s1[i] ^ s2[i])+'0';
        cout<<final_key[i];
    }
    cout<<endl;
}

    return 0;
}
/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.length(); ++i)
        {
            if (s1[i] == s2[i])
            {
                s1[i] = '0';
            }
            else
            {
                s1[i] = '1';
            }
        }
        cout << s1 << endl;
    }
    return 0;
}
*/