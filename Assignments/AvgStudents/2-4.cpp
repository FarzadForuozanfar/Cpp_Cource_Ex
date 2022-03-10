#include <iostream>
#include <vector>
#include <algorithm>
int counter=0;
using namespace std;
struct student
{
	int id;
	string name;
	int numberOfUnit;
	float grade;
	int credit;
	float avrage;
	
}tempId,mainTemp;

bool f(student a,student b)
{
	if(a.avrage>b.avrage)
	return true;
}

void InitStructStudent(int id,vector<student> &list)
{
	float sum;
	int tempCredit; 
	mainTemp.id=id;
	list[counter].id.push_back(mainTemp.id);
	getline(cin,mainTemp.name);
	list[counter].name=mainTemp.name;
	cin>>mainTemp.numberOfUnit;
	list[counter].numberOfUnit=mainTemp.numberOfUnit;
	int avg=0;
	for(int i=0;i<mainTemp.numberOfUnit;i++)
	{
		cin>>mainTemp.grade>>mainTemp.credit;
		sum+=(mainTemp.grade * mainTemp.credit);
		tempCredit+=mainTemp.credit;
	}
	list[counter].avrage=(sum/tempCredit);
	counter++;
}
int main() 
{
	int avgA,mashroot;
	vector<student> List;
	tempId.id=1;
	while (cin>>tempId.id && tempId.id!=0)
	{
		InitStructStudent(tempId.id,List);
	}
	sort(List.begin(),List.end(),f);
	for(int i=0;i<List.size();i++)
	{
		if(List[i].avrage>=17)
		{
			cout<<List[i].name<<" "<<List[i].avrage<<endl;
			avgA++;
		}
		if(List[i].avrage<12)
		mashroot++;
	}
	cout<<avgA<<endl<<mashroot;
	return 0;
}
