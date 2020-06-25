#include <iostream>
using namespace std;

int clearKthBit(int m,int k)
{
	 m=m&(~(1<<k)); 
	return (m);   
}

//driver program to check the code

int main()
{
	int num,k;

	cout<<"Enter number: ";
	cin>>num;
	cout<<"Enter k: ";
	cin>>k;

	cout<<"original number before clearing: "<<num<<endl;

	int new_number= clearKthBit(num,k);

	cout<<"new number after clearing: "<<new_number<<endl;

	return 0;
}
