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

void followprime()
{
//	return 0;
}

void followNotprime()
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
			followNotprime();
		case 1:
			followprime();
		
	}
			
}
