//imp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
struct Compare
{
    bool operator()(pi const & a, pi const & b)
    {
         if(a.second < b.second)
         {
            return true;
         }
         else if(a.second > b.second)
         {
             return false;
         }
         else
         {
             if(a.first > b.first)
             {
                 return true;
             }
             return false;
         }
    }
};

int main()
{
    priority_queue<pi , vector<pi>, Compare>q;
    q.push({1, 5});
    q.push({5, 15});
    q.push({7, 15});
    q.push({10, 2});
    q.push({1, 10});
    cout<<q.top().first<<" "<<q.top().second<<endl;
    return 0;
}