//continue statement: This statement skips the rest of the loop statement and
//starts the next iteration of the loop to take place.

// break statement: This statement terminates the smallest enclosing loop
//(i.e., while, do-while, for loop, or switch statement).
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // using continue to print the odd numbers only
    for (int i = 1; i < 10; i++)
    {

        if (i % 2 == 0)
        {
            continue;
        }
        cout << i << " ";
        //  note: "continue" will not go to below statement,
        // it directly go to the iterator vlaue.i.e "i"
    }
    cout << endl;
    // printing the values till it get number=6
    // i.e output will be 1,2,3,4,5
    for (int i = 1; i < 10; i++)
    {
        if (i == 6)
        {
            break;
        }

        //break will get out of the loop on matching the given if condition

        cout << i << " ";
    }
    return 0;
}