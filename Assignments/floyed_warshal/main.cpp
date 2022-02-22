#include <iostream>
#include <fstream>

using namespace std;
int p=0,p1=0;

void Changes(int Array[][10],int ArrayInput[10],int ArrayOutput[10],const int SIZE)
{
		for(int i=p;i<SIZE;i++)
		{
			if(ArrayInput[i] != -1)
			{
			for(int j=p;j<SIZE;j++)
			{
				if(ArrayOutput[j] != -1)
					Array[ArrayInput[i]][ArrayOutput[j]]=1;
			}
			}
		}
	}
void Floyed_warshal(int Array[][10],const int SIZE)
{
	int input[SIZE];
	int output[SIZE];
	for(int j=p1;j<SIZE;j++)
	{
		for(int i=p1;i<SIZE;i++)
		{
			if(Array[i][j] == 1)
				input[i]=i;
			else
				input[i]=-1;
			if(Array[j][i] == 1)
				output[i]=i;
			else
				output[i]=-1;
		}
		
		Changes(Array,input,output,SIZE);
	}
	
}
void Input(int Array[][10],const int SIZE)
{
	int temp;
	for(int i=0;i<SIZE;i++)
	{
	for(int j=0;j<SIZE;j++)
	{
		cout<<"Array["<<i+1<<"]["<<j+1<<"] =";
		cin>>temp;
		switch(temp)
		{
			case 1:
				Array[i][j]=temp;
				break;
			case 0:
				Array[i][j]=temp;
				break;
			default:
				Array[i][j]=0;
				break;
		}
	}
	}
}
void Print(int Array[][10],const int SIZE)
{
	cout << "  ";
	for(int i=0;i<SIZE;i++)
	{
		cout << i+1 << " ";
	}

	cout << endl;
	for(int j=0;j<SIZE;j++)
	{
		cout << j+1 << "|";
		for(int i=0;i<SIZE;i++)
		{
		cout<<Array[j][i]<<"|";
		}
		cout<<endl;
	}
}
int main() 
{
	int temp;
	cout<<"Enter Size Of Array = ";
	cin>>temp;
	const int SIZE=temp;
	int array[SIZE][10];
	Input(array,SIZE);
	bool m=false;
	system("cls");
	cout<<"Before Change :"<<endl;
	Print(array,SIZE);
	m=true;
	Floyed_warshal(array,SIZE);
	if(m)
	{
		cout<<endl<<"After Change :"<<endl;
		Print(array,SIZE);
	}
	ofstream out("s.txt",ios::app);
out.close();
out.open("s.txt",ios::out);
	return 0;
}

