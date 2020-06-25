   #include<bits/stdc++.h>
using namespace std;
int main(){
	int arrA[] = {4,2,3,3,1},size=5;
   int maxCount=0;
        int maxIndex=0;
        for (int i = 0; i <size ; i++) {
            //get the index to be updated
            int index = arrA[i]% size;
            arrA[index] = arrA[index] + size;
            cout<<(arrA[index])<<" ";
        }
        for (int i = 0; i <size ; i++) {
            if(arrA[i]/size>maxCount){
                maxCount=arrA[i]/size;
                maxIndex=i;
            }
        }
		cout<<endl<<maxIndex;
}