#include <iostream>
using namespace std;
int main()
 {
	int number,sum=0;
	cin>>number;
	for(int divisor=1;divisor<number;divisor++)
	{
		if(number % divisor== 0)
		{
			sum += divisor;
		}
	}
	if(sum==number)
	{
		cout<<"YES";
	}
	else 
	{
		cout<<"NO";
	}
	return 0;
}
