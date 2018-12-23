#include<iostream>
#include<math.h>
using namespace std;

bool isprime(int a)
{
	int flag=0;
	for(int i=2;i<(int )sqrt(a)+1;i++)
	{
		if(a%i==0)
		{
			return false;
		}
	}
	
	return true;
}

bool isodd(int a)
{
	if(a%2==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void followprime(int a)
{
	int z[3];
	z[0]=a;
	z[1]=((a*a)+1)/2;
	z[2]=((a*a)-1)/2;
	cout<<"The ordered triplet is ["<<z[0]<<","<<z[1]<<","<<z[2]<<"]";
//	return 0;
}

void followNotprime(int a)
{
//	return 0
}

int main()
{
	int n;
	cin>>n;
	switch(isprime(n))
	{		
		case 0:
			followNotprime(n);
		case 1:
			cout<<"Only 1 triplet is found\n";
			followprime(n);
		
	}
			
}
