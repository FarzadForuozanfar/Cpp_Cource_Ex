#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
int row =0 ,col =0,coll =0,roww =0;
void power1(double p,int t){
	unsigned long long result=1;
	for(int i=0;i<t;i++){
		result*=p;
	}
	cout<<p<<" ^ "<<t<<" = "<<result;
}
unsigned long long fact(int n){
	if(n==1)
	return 1;
	else
	return n*fact(n-1);
}
double factorial(int num){
        double fact = 1;
        for(int i = 1; i <= num; i++){
               fact = fact * i;
        }
        return fact;
}
double taylorCosine(double num, double precision ){
        double value = 0;
        for(int n = 0; n < precision; n++){
                value += pow(-1.0, n) * pow(num, 2*n)/factorial(2*n);
        }
        return value;
}

double taylorSine(double num, double precision )
{
        double value = 0;
        for(int n = 0; n < precision; n++){
               value += pow(-1.0, n) * pow(num, 2*n+1) / factorial(2*n + 1);
        }
        return value;
}
void readm(float a[][10])
{
	int i,j,n=0;
	cout<<"Enter n for row and col: ";
	cin>>n;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	cout<<"a["<<i<<","<<j<<"]"<<" : ";
	cin>>a[i][j];}
}
}
void read(float a[][10])
{
	int i,j;
	
	cout <<"row a = ";
	cin>>row;
	cout<<"column a = ";
	cin >>col;
	cout<<endl;
	for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	cout<<"a["<<i<<","<<j<<"]"<<" : ";
	cin>>a[i][j];}
}
}
void readd(float a[][10])
{
	int i,j;
	cout <<"row b= ";
	cin>>roww;
	cout<<"column b= ";
	cin >>coll;
	cout<<endl;
	for(i=0;i<roww;i++){
	for(j=0;j<coll;j++){
	cout<<"b["<<i<<","<<j<<"]"<<" : ";
	cin>>a[i][j];}
}
}
void add(float a[][10],float b[][10],float c[][10]){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
		c[i][j]=a[i][j]+b[i][j];
		cout<<"c["<<i<<","<<j<<"] = "<<c[i][j]<<endl;}
	}
}
void mines(float a[][10],float b[][10],float c[][10]){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
		c[i][j]=a[i][j]-b[i][j];
		cout<<"c["<<i<<","<<j<<"] = "<<c[i][j]<<endl;}
	}
}
void multi(float a[][10],float b[][10],float c[][10],int m,int n,int p){
	for (int i=0;i<m;i++)
	{
		for(int j=0;j<p;j++)
		{
			c[i][j]=0;
			for(int k=0;k<n;k++)
			c[i][j]+=a[i][k]*b[k][j];
			cout<<"multi["<<i<<","<<j<<"] = "<<c[i][j]<<endl;
		}
	}
}
void tran(float a[][10],int r,int c){
	for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
	cout<<"tranhad["<<i<<","<<j<<"] = "<<a[j][i]<<endl;
				
			}
		}
	}
void build(float b[10][10],float a[10][10],int i,int n){
	int j,l;
	int h=0,k=0;
	for(l=1;l<n;l++){
		for(j=0;j<n;j++){
			if(j==1)
			continue;
			b[h][k]=a[l][j];
			k++;
			if(k==n-1)
			{
				h++;
				k=0;
			}
		}
	}
}
int det(float a[10][10],int n){
	int sum=0;
	float b[10][10];
	if(n==2){
		sum+=a[0][0]*a[1][1]-a[1][0]*a[1][0];
		return sum;
	}
	else{
	for(int i=0;i<n;i++){
	build(b,a,i,n);
	sum+=a[0][i]*pow(-1,i)*det(b,(n-1));
	}
}
return sum;
}
int main() 
{
	float a[10][10],b[10][10],c[10][10],mul[10][10],inv[10][10];
	int num,n,mt,sct;
	while(num!=5){
		system ("cls");
		cout<<endl<<"1- Numerical calculations "<<endl<<"2- Matrix operations "<<endl<<"3- Trigonometric operations "<<endl<<"4- about us"<<endl<<"5- Exit "<<endl<<"enter number : "<<endl;
		cin>>num;
		switch(num){
		while (n!=11){
		case 1:{
		system ("cls");
		cout<<endl<<"1-Sum:"<<endl<<"2-mines:"<<endl<<"3-multiplaction:"<<endl<<"4-divide:"<<endl<<"5-sqrt:"<<endl<<"6-power:"<<endl<<"7-factorial:"<<endl<<"8-Show the divisor of the number:"<<endl<<"9-Check the completeness of the number:"<<endl<<"10-check Prime numbers:"<<endl<<"11-return to main menu"<<endl<<"enter number:"<<endl;	
		cin>>n;
		switch(n){
		case 1:{
		system ("cls");
		float a,b;
		cout<<"enter two number a,b :";
		cin>>a>>b;
		cout<<a<< "+"<<b<<"="<<a+b<<endl;
		system ("pause");
		break; 
	}
		case 2:{
			system ("cls");
			float a=0,b=0;
			cout<<"enter two number a,b :";
			cin>>a>>b;
			cout<<a<<"-"<<b<<"="<<a-b<<endl;
			system ("pause");
			break;}
		case 3:{
			system ("cls");
			float a=0,b=0;
			cout<<"enter two number a,b :";
			cin>>a>>b;
			cout<<a<<" * "<<b<<"= "<<a*b<<endl;
			system ("pause");
		break;
		}
		case 4:{
		system ("cls");
		float a=0,b=0;
		cout<<"enter two number a,b :";
		cin>>a>>b;
		cout<<a<<" / "<<b<<" = "<<a/b<<endl;
		system ("pause");
		break;
		}
		case 5:{
		system ("cls");
		long double jazr=1;
		int i,x;
		cout<<"enter number : ";
		cin>>x;
		for(i=0;i<=100;i++)
		jazr=(jazr+(x/jazr))/2;
		cout<<"sqrt["<<x<<"]= "<<jazr<<endl;
		system ("pause");	
		break;
		}
		case 6:{
		system ("cls");
		double n;
		int t;
		cout<<"Enter number for paye = ";
		cin>>n;
		cout<<"Enter number for tavan = ";
		cin>>t;
		power1(n,t);
		cout<<endl;
		system ("pause");
		break;
		}
		case 7:{
			system ("cls");
			int a=1;
			cout<<"Enter number = ";
			cin>>a;
			cout<<a<<"! = "<<fact(a)<<endl;
			system ("pause");
			break;
		}
		case 8:{
			system ("cls");
			int a=0;
			cout<<"Enter number : ";
			cin>>a;
			for(int i=1;i<=a;i++){
				if(a % i== 0){
				cout<<i<<endl;
				}
			}
			system ("pause");
			break;
		}
		case 9:{
		system ("cls");
		int n,sum=0;
		cout<<"Enter number :";
		cin>>n;
		for(int i=1;i<n;i++){
			if(n % i== 0){
				sum += i;
		}
		}
		if(sum==n){
		cout<<endl<<sum<<" "<<"is tom."<<endl;
	}
		else {
		cout<<endl<<n<<" isnt tom."<<endl;
		}
		system ("pause");	
		break;
		}
		case 10:{
			system ("cls");
			int n,flag=0,i;
			cout<<"enter number :";
			cin>>n;
			if(n==0 ||  n<0)
			{
				cout<<n<<" isnt prime ";
				system ("pause");
				break;
			}
			for(i=2;i<n;i++){
				if(n % i==0){
					flag=1;
				}
			}
			if(flag==0){
			cout<<endl<<n<<" Is Prime"<<endl;
			}
			else
			{
			cout<<n<<" Isnt Prime "<<endl;
			}
			system ("pause");
			break;
		}
		case 11:{
			break;
		}
	default :
		system ("cls");
		cout<<"enter correct number "<<endl;
		system ("pause");
		break;
	}
	}
	}
	break;
	while (mt!=7){
	case 2:{
	system ("cls");
	cout<<"1- sum matrixs"<<"\n2- mines matrixs"<<"\n3- milti matrixs"<<"\n4- Matrix transpose "<<"\n5- determinan"<<"\n6- multi a number in matrixs\n7-return to main menu"<<"\nEnter number :";
	cin>>mt;
	switch (mt){
		case 1:{
		system ("cls");
		read(a);
		cout<<endl;
		readd(b);
		cout<<endl;
		add(a,b,c);
		cout<<endl;	
		system ("pause");
		break;}
		case 2:{
			system ("cls");
			read(a);
			cout<<endl;
			readd(b);
			cout<<endl;
			float m[10][10];
			mines(a,b,m);
			cout<<endl;
			system ("pause");
			break;
		}
		case 3:{
			system ("cls");
			read(a);
			cout<<endl;
			readd(b);
			cout<<endl;
			multi(a,b,mul,row,col,coll);
			cout<<endl;
			system ("pause");
			break;
		}
		case 4:{
			system ("cls");
			read(a);
			cout<<endl;
			tran(a,row,col);
			cout<<endl;
			system ("pause");
			break;
		}
		case 5: {
			system ("cls");
			readm(a);
			int dt=det(a,row);
			cout<<endl<<"determinan = "<<dt<<endl;
			system ("pause");
			break;
		}
		case 6:{
			system ("cls");
			int q=0;
			read(a);
			cout<<endl<<"Enter number for multi in matris :";
			cin>>q;
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++)
				{
				a[i][j]=q*a[i][j];
				cout<<"a["<<i<<","<<j<<"]: "<<a[i][j]<<endl;
				}
			}
			system ("pause");
			break;
		}
		case 7:{
			break;
		}
		default :
		system ("cls");
		cout<<"enter correct number "<<endl;
		system ("pause");
		break;
	}
	}
	}
	break;
	while (sct!=5){
		
		case 3:{
			system ("cls");
			cout<<"1-sin(x)\n2-cos(x)\n3-tan(x)\n4-cot(x)\n5-return to main menu\nenter number : ";
			cin>>sct;
			switch(sct){
				case 1:{
					system ("cls");
					double rad,d;
					cout<<"Enter degree : ";
					cin>>d;
					rad=(d*3.14)/180;
					cout<<"sin("<<d<<")= "<<taylorSine(rad,19)<<endl;
					system ("pause");
					break;
				case 2:{
					system ("cls");
					double rad=0,d;
					cout<<"Enter degree : ";
					cin>>d;
					rad=(d*3.14)/180;
					cout<<"cos("<<d<<")= "<<taylorCosine(rad,19)<<endl;
					system ("pause");
					break;
				}
				case 3:{
					system ("cls");
					double rad=0,d;
					cout<<"Enter degree : ";
					cin>>d;
					rad=(d*3.14)/180;
					cout<<"tan("<<d<<")= "<<taylorSine(rad,19)/taylorCosine(rad,19)<<endl;
					system ("pause");
					break;
				}
				case 4:{
						system ("cls");
					double rad=0,d;
					cout<<"Enter degree : ";
					cin>>d;
					rad=(d*3.14)/180;
					cout<<"tan("<<d<<")= "<<taylorCosine(rad,19)/taylorSine(rad,19)<<endl;
					system ("pause");
					break;
				}
				case 5:{
					break;
				}
			}
		default :
		system ("cls");
		cout<<"enter correct number "<<endl;
		system ("pause");
		break;
		}
		}
	}
	break;
	case 4:{
		system ("cls");
		cout<<"PROGRAMMER : Farzad Forouzanfar\n\n\tID : 97440190"<<endl<<endl;
		system ("pause");
		break;
	}
	case 5:
		system ("cls");
		cout<<"press any key to exit"<<endl;
		getch();
		return 0;
		break;
		default :
		system ("cls");
		cout<<"enter correct number "<<endl;
		system ("pause");
		break;
	}
	}
	getch();
	return 0;
	
	
}


