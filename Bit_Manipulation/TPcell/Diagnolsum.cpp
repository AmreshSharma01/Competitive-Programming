 #include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3][3],i,j,sum1=0,sum2=0,finalSum;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin>>a[i][j];
        }
        
    }
        for(i=0;i<3;i++){  
        for(j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for (i = 0; i <3; ++i)   //For displaying the sum of major and minor diagonal elements
    {
            sum1 = sum1 + a[i][i];
            sum2 = sum2 + a[i][3 - i - 1];
            finalSum=sum1+sum2;
    }
            
                            
      cout<<finalSum;
}