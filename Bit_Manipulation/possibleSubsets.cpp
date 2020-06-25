 #include<bits/stdc++.h>
using namespace std;

 void possibleSubsets(char A[], int N)
    {
        for(int i = 0;i < (1 << N); ++i)
        {
            for(int j = 0;j < N;++j)
                if(i & (1 << j))
                    cout << A[j] << " ";
            cout << endl;
    }
    }
    int main(){
        char A[2]={'a','b'};
        int n=2;
        possibleSubsets(A, n);
        return 0;


    }