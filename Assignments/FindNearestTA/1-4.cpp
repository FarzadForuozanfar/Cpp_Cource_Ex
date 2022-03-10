#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
struct TA_adress

{
  double x;
  double y;
  //TA Adress
  double ditance;
  string name;
};

double CalculatDistance(double a, double b, double x, double y)
{
  return sqrt(pow((a - x), 2) + pow((b - y), 2));
}
bool f(TA_adress a,TA_adress b)
{
	if(a.ditance<b.ditance)
	return true;
	else if(a.ditance == b.ditance && a.name<b.name)
	return true;
	else
	return false;
}
int main()
{
  int count;
  TA_adress tempX, tempY, distanceTemp, name;
  cin >> count;
  vector<TA_adress> specification(count);
  for (int i = 0; i < specification.size(); i++)
  {
    cin >> tempX.x;
    specification[i].x= tempX.x;
    cin >> tempY.y;
    specification[i].y= tempY.y;
    cin.ignore();
    getline(cin, name.name);
    specification[i].name = name.name;
  }
  TA_adress xFriend, yFriend; //friend adress
  cin >> xFriend.x >> yFriend.y;
  for (int i = 0; i < specification.size(); i++)
  {
    specification[i].ditance = CalculatDistance(xFriend.x, yFriend.y, specification[i].x, specification[i].y);
  }
  sort(specification.begin(),specification.end(),f);
  for(int i=0;i<specification.size();i++)
  {
  	cout<<specification[i].name<<endl;
  }
  return 0;
}
