#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct node				//linked list data structure
{
	int data;
	struct node * link;
};

struct node * HEAD;

void append(int d)			//function to append the list of prime numbers
{
	struct node * temp=(struct node *)malloc (sizeof(struct node));
	temp->data=d;
	temp->link=HEAD;
	HEAD=temp;
}

void display()		//displays the linked list
{
	struct node * temp;
	temp=HEAD;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->link;
	}
}


bool isprime(int a)			//ISprime Number
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


int nextprime(int a)		//gives the next prime number
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

void followNotprime(int a)			//follow if the number from main is not prime
{
	int t=a;
	int temp=2;
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

void followprime(int a)			//function to print pythagorean triplets of the number
{
	int z[3];
	z[0]=a;
	z[1]=((a*a)+1)/2;
	z[2]=((a*a)-1)/2;
	cout<<"The ordered triplet is ["<<z[0]<<","<<z[1]<<","<<z[2]<<"]";
//	return 0;
}


int main()
{
	HEAD=NULL;
	int n;
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
