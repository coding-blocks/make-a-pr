//WAP that return the century from year
#include<iostream>
using namespace std;
int main()
{
	int year,c;
	cout<<"enter the year"<<endl;
	cin>>year;
	if(year>0)
	{
		if(year%100==0)
		c= year/100;
		else if(year<100)
		c=1;
		else 
		c=year/100+1;
		
	}
	cout<<"The century is"<<c;
	return 0;
	
}

