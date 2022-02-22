#include <iostream>
#include <cstdlib>
using namespace std;
class rational
{
	private:
		double num1;
		double num2;
		double num3;
	public:
		rational(double number1,double number2,double number3)
		{
			num1=number1;
			num2=number2;
			num3=number3;
		}
		double sum()
		{
			return (num1+num2)/num3;
		}
		double mines()
		{
			return (num1-num2)/num3;
		}
		double multi()
		{
			return (num1*num2)/num3;	
		} 
		double dive()
		{
			return (num1/num2)/num3;
		}
		
};
int main()
{

	double a,b,c;
	cout<<"Enter two number for sorat and one number for makhraj :";
	cin>>a>>b>>c;
	rational obj(a,b,c);
	cout<<"sum :"<<obj.sum()<<"\nmines : "<<obj.mines()<<"\nmulti : "<<obj.multi()<<"\ndive : "<<obj.dive();
	return 0;
}
