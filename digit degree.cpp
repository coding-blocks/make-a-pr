//WAP that defines digit degree of some positive int as the no. of times we need to replace this number with the sum of its digit until we get to a one or zero.
#include<iostream>
using namespace std;
int main()
{
	int n,c;
	cout<<"enter the digit"<<endl;
	cin>>n;
	while(n/10!=0)
	{
		int sum=0;
		while(n!=0)
		{
			sum=sum+n%10;
			n/=10;
		}
		n=sum;
		c++;
	}
	cout<<"the degree of the digit is"<<c;
	return 0;
}
