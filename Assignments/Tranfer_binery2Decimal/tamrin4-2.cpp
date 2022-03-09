#include <iostream>
using namespace std;
int TransferMabna(int number,int mabna1,int mabna2)
{
	int result=0;
	for(int i=1;number>0;i*=mabna1)
	{
		result=result+((number%mabna2)*i);
		number/=mabna2;
	}
	return result;	
}
int Palindrom(int number)
{
 int copyNumber,result=0;
 copyNumber=number;
 while(number>0)
 {
  result=result*10+number%10;
  number/=10;
 }
 if(copyNumber==result)
 return 1;
 else 
 return 0;
}
int main() 
{
	int number1,mabna1,mabna2;
	cin>>number1;
	cin>>mabna1;
	cin>>mabna2;
	int number2=number1;
	int result1=TransferMabna(number1,mabna1,10);
	int result2=TransferMabna(result1,10,mabna2);
	if(Palindrom(result2))
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
