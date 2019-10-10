//find the smallest multiple of given no. that is not less than a specified lower bound.
#include<iostream>
using namespace std;
int main()
{
	int n,d,lb;
	cout<<"enter the divisor and lower bound"<<endl;
	cin>>d>>lb;
	if(d==0)
	return lb;
	else
	{
		for(int i=1;i<=(lb/d)+1;i++)
		{
		  n=d*i;
		}
	}
	cout<<"the value of smallest multiple is"<<n;
	return 0;
}
