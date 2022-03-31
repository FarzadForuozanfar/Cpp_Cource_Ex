#include <iostream>
#include <string>
using namespace std;
int main() 
{
	char text1[21],text2[21],text3[21],text4[21],text5[21],flag=0;
	cin.get(text1,20);
	cin.ignore();
	cin.get(text2,20);
	cin.ignore();
	cin.get(text3,20);
	cin.ignore();
	cin.get(text4,20);
	cin.ignore();
	cin.get(text5,20);
	cin.ignore();
	for(int i=0;i<20;i++)
	{
		if(text1[i]=='H' && text1[i+1]=='A' && text1[i+2]=='F' && text1[i+3]=='E' && text1[i+4]=='Z')
		{
			cout<<1<<" ";
			flag=1;
		}
		else if(text1[i]=='M' && text1[i+1]=='O' && text1[i+2]=='L' && text1[i+3]=='A' && text1[i+4]=='N' && text1[i+5]=='A')
		{
			cout<<1<<" ";
			flag=1;
		}
	}
	for(int i=0;i<20;i++)
	{
		if(text2[i]=='H' && text2[i+1]=='A' && text2[i+2]=='F' && text2[i+3]=='E' && text2[i+4]=='Z')
		{
			cout<<2<<" ";
			flag=1;
		}
		else if(text2[i]=='M' && text2[i+1]=='O' && text2[i+2]=='L' && text2[i+3]=='A' && text2[i+4]=='N' && text2[i+5]=='A')
		{
			cout<<2<<" ";
			flag=1;
		}	
	}
	for(int i=0;i<20;i++)
	{
		if(text3[i]=='H' && text3[i+1]=='A' && text3[i+2]=='F' && text3[i+3]=='E' && text3[i+4]=='Z')
		{
			cout<<3<<" ";
			flag=1;
		}
		else if(text3[i]=='M' && text3[i+1]=='O' && text3[i+2]=='L' && text3[i+3]=='A' && text3[i+4]=='N' && text3[i+5]=='A')
		{
			cout<<3<<" ";
			flag=1;
		}	
	}
	for(int i=0;i<20;i++)
	{
		if(text4[i]=='H' && text4[i+1]=='A' && text4[i+2]=='F' && text4[i+3]=='E' && text4[i+4]=='Z')
		{
			cout<<4<<" ";
			flag=1;
		}
		else if(text4[i]=='M' && text4[i+1]=='O' && text4[i+2]=='L' && text4[i+3]=='A' && text4[i+4]=='N' && text4[i+5]=='A')
		{
			cout<<4<<" ";
			flag=1;
		}
	}
	for(int i=0;i<20;i++)
	{
		if(text5[i]=='H' && text5[i+1]=='A' && text5[i+2]=='F' && text5[i+3]=='E' && text5[i+4]=='Z')
		{
			cout<<5;
			flag=1;
		}
		else if(text5[i]=='M' && text5[i+1]=='O' && text5[i+2]=='L' && text5[i+3]=='A' && text5[i+4]=='N' && text5[i+5]=='A')
		{
			cout<<5;
			flag=1;
		}
	}
	if(flag==0)
	cout<<"NOT FOUND!";
	return 0;
}

