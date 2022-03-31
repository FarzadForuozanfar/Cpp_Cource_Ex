#include <iostream>
using namespace std;
int main() 
{
	int number1,number2,flag=0;
	cin>>number1;
	cin>>number2;
	if(number1>number2)
	{
		int temp;
		temp=number1;
		number1=number2;
		number2=temp;
	}
	for(int primeNumber=number1;primeNumber<=number2;primeNumber++)
	{
		if(primeNumber==1)
		primeNumber++;
		flag=0;
		for(int counter=2;counter<primeNumber;counter++)
		{
			if(primeNumber%counter==0)
			flag=1;
		}
		if(flag==0)
		cout<<primeNumber<<endl;
	}
	return 0;
}
