#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
class Time
{
	private:
		int hour;
		int min;
	public:
		void setTime(int h,int m);
		Time(int h,int m);
		Time(int h);
		int getHour(){	return hour;	}
		int getMin(){	return min;	}
		int Compare(Time t);
		string ToGiveInfo(int h,int m);
		void print();
		
};
Time::Time(int h,int m)
{
	setTime(h,m);
}
Time::Time(int h)
{
	if(h<0 || h>23)
	abort();
	hour=h;
	min=0;
}
void Time::setTime(int h,int m)
{
	if(h<0 || h>23 || m<0 || m>59 )
	abort();
	hour=h;
	min=m;
}

int Time::Compare(Time t)
{
	if(hour<t.hour)
		return -1;
	else if(hour == t.hour && min<t.min)
		return -1;
	else if (hour == t.hour && min == t.min)
		return 0;
	else 
		return 1;
}

string Time::ToGiveInfo(int h,int m)
{
	string str;
	if(h>=0 && m>=0 && h<=11 && m<=59)
	{	
		str="Morninng";
		return str;
	}
	else if(h==12 && m==0)
	{
		str="Noon";
		return str;
	}
	else if(h>=12 & m>=1 && h<=16 && m<=59 )
	{
		str="AfterNoon";
		return str;
	}
	else if(h>=17 && m>=0 && h<=19 && m<=59)
	{
		str="Evening";
		return str;
	}
	else
	{
		str="Night";
		return str;
	}
}

void Time::print()
{
	cout<<hour<<":"<<min<<endl;
}
int main() 
{
	int h=20,m=0;
	Time t(h,m);
	t.print();
	cout<<t.ToGiveInfo(h,m);
	return 0;
}
