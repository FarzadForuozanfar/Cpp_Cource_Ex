#include <iostream>
#include <cmath>
using namespace std;
int globalArray[10][10],help[10][10];
const int SIZE=10;
unsigned long long Solution(int i=0,int j=0)
{
	if(i == SIZE ||j == SIZE)	
	return 0;
	int right = Solution(i,j+1);
	int butoom = Solution(i+1,j);
	return globalArray[i][j]+max(right,butoom);
}
int main()

{
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			cin>>globalArray[i][j];
	cout<<Solution();
    return 0;
}


