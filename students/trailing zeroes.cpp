//WAP to find the no. of trailing zeroes in decimal representation of n!
#include<iostream>
using namespace std;
int main()
{
	int n,ans;
	cout<<"enter a no."<<endl;
	cin>>n;
	while(n!=0)
	{
		ans+=n/5;
		n/=5;
	}
	cout<<"the trailing zeroes are"<<ans;
	return 0;
}
