#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

struct node				//linked list data structure
{
	long data;
	struct node * link;
};

struct node * HEAD;

void append(long d)			//function to append the list of prime numbers
{
	struct node * temp=(struct node *)malloc (sizeof(struct node));
	temp->data=d;
	temp->link=HEAD;
	HEAD=temp;
}

void display()		//displays the linked list
{
	long len=0;
	struct node * temp;
	temp=HEAD;
	while(temp!=NULL)
	{
		len++;
		cout<<temp->data<<endl;
		temp=temp->link;
	}
	cout<<"length is "<<len;
}


bool isprime(long a)			//ISprime Number
{
	long flag=0;
	for(unsigned int i=2;i<(unsigned int )sqrt(a)+1;i++)
	{
		if(a%i==0)
		{
			return false;
		}
	}
	
	return true;
}


long nextprime(long a)		//gives the next prime number
{
	a++;
	if(isprime(a))
	{
		return a;
	}
	else
	{
		return nextprime(a);
	}
}

void followNotprime(long a)			//follow if the number from main is not prime
{
	long t=a;
	long temp=2;
	for(temp=2;temp<(a/2);temp=nextprime(temp))
	{
		while(a%temp==0)
		{
			append(temp);
			a=a/temp;
		}
		a=t;
	}
	display();
}

void followprime(long a)			//function to prlong pythagorean triplets of the number
{
	long z[3];
	z[0]=a;
	z[1]=((a*a)+1)/2;
	z[2]=((a*a)-1)/2;
	cout<<"The ordered triplet is ["<<z[0]<<","<<z[1]<<","<<z[2]<<"]";
//	return 0;
}


int main()
{
	HEAD=NULL;
	long n;
	cin>>n;
	switch(isprime(n))
	{		
		case 0:
			followNotprime(n);
			break;
		case 1:
			cout<<"Only 1 triplet is found\n";
			followprime(n);
			break;
		
	}
			
}
