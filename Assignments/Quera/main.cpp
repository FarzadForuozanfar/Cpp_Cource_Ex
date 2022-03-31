#include <iostream>
#include <conio.h>
using namespace std;
int main()
 {
int d=0,n;
string str;
	
while(1)
 	{
 		int inv=0;
 		cout<<"enter num = "<<endl;
 		cin>>n;
 		cout<<endl;
		do{
	
 		d=n % 10;
 		inv=inv *10 +d;
 		n/=10;
 	
		}while (n!=0);
		cout <<"inv = "<<inv<<endl;
		cout <<"do u want contiue ?";
		cin>>str;
		if(str=="no" || str == "No" || str == "NO")
		break;
		else if(str == "yes" || str == "Yes" || str == "YES")
		continue:
	 }
	
}



