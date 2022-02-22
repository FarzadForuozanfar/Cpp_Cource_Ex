#include <iostream>
#include <string>
using namespace std;

template <class t>
t sum(t a,t b)
{
	return a+b;
}

	//
template <class t>
t sub(t a,t b)
{

	return a-b;
}

//
template <class mul>
mul multi(mul a,mul b)
{
	return a*b;
}

//
template <class d>
d div(d a,d b)
{
	return a/b;
}

int main() 
{
	double x,y;
	int num;
	cout<<"1-sum\n"<<"2-mines\n"<<"3-multi\n"<<"4-dive\n"<<"enter number :"<<endl;
	cin>>num;
	switch(num)
	{
		case 1:
			{
			system("cls");
			
			cout<<"enter two number = ";
			cin>>x>>y;
			int s=sum<int>(x,y);
			long int s2=sum<long int>(x,y);
			float s3=sum<float>(x,y);
			double s4=sum<double>(x,y);
			cout<<"int sum : "<<s<<"\nlong int sum : "<<s2<<"\nfloat sum : "<<s3<<"\ndouble sum : "<<s4;
			break;
			}
			
		case 2:
			{
			system("cls");	
			cout<<"enter two number = ";
			cin>>x>>y;
			int s=sub<int>(x,y);
			long int s2=sub<long int>(x,y);
			float s3=sub<float>(x,y);
			double s4=sub<double>(x,y);
			cout<<"int sub : "<<s<<"\nlong int sub : "<<s2<<"\nfloat sub : "<<s3<<"\ndouble sub : "<<s4;
			break;
		}
		case 3:
			{
			system("cls");
			
			cout<<"enter two number = ";
			cin>>x>>y;
			int s=multi<int>(x,y);
			long int s2=multi<long int>(x,y);
			float s3=multi<float>(x,y);
			double s4=multi<double>(x,y);
			cout<<"int multi : "<<s<<"\nlong int multi : "<<s2<<"\nfloat multi : "<<s3<<"\ndouble multi : "<<s4;
			break;
		}
		case 4:
			{
			
			system("cls");
			
			cout<<"enter two number = ";
			cin>>x>>y;
			int s=div<int>(x,y);
			long int s2=div<long int>(x,y);
			float s3=div<float>(x,y);
			double s4=div<double>(x,y);
			cout<<"int div : "<<s<<"\nlong int div : "<<s2<<"\nfloat div : "<<s3<<"\ndouble div : "<<s4;
			break;
		}
	}
	return 0;
}
