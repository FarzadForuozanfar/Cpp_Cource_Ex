#include <iostream>
using namespace std;
template <class e>
e Avg(e array[],int size)
{
	double sum;
	for(int i=0;i<size;i++)
	{
		sum=array[i];
	}
	cout<<"Avrage is :"<<sum/size<<endl;
	return 1;
}
int main()
{
	const int doubleSize=4,intSize=3;
	double array1[doubleSize]={18.5,17.55,20.1,10.87};
	int array2[intSize]={17,21,45};
	Avg(array1,doubleSize);
	Avg(array2,intSize);
	return 0;
}
