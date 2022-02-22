#include <bits/stdc++.h>
using namespace std;
bool b;
class Rational
{
private:
	int numerator;
	int denuminator;
public:
	int get1() { return numerator; }
	int get2() { return denuminator; }
	
	Rational(int n, int d) : numerator(n), denuminator(d) {}
	Rational(int n) : numerator(n), denuminator(0) {}
	
	void print() const;
	
	friend ostream& operator<<(ostream& out, const Rational& R);
	int calculate_common_denuminator(const Rational& R)const;
	
	Rational operator+(const Rational& R)const;
	Rational operator+(int n)const;
	Rational& operator+=(const Rational& R);
	
	Rational operator-(const Rational& R)const;
	Rational& operator-=(const Rational& R);
	Rational operator-(int n)const;
	
	Rational& operator*=(const Rational& R);
	Rational operator*(const Rational& R)const;
	Rational operator*(int n)const;
	
	Rational operator/(int n)const;
	Rational operator/(const Rational& R)const;
	Rational& operator/=(const Rational& R);
};
int BMM(int number1,int number2)
{
	int temp=0;
	if(number1>number2)
	{
		temp=number1;
		number1=number2;
		number2=temp;
	}
	temp=0;
	while(!(number2==0))
	{
		temp=number1%number2;
		number1=number2;
		number2=temp;
	}
	return number1;
}
int Rational::calculate_common_denuminator(const Rational& R) const
{
	int j;
	if(b)
	{
		for(j=1;j*denuminator<=R.denuminator;j++)
		{
			if(j*denuminator==R.denuminator)
			{
				return j;
			}
		}
	}
	else if(!b)
	{
		for(j=1;j*R.denuminator<=denuminator;j++)
		{
			if(j*R.denuminator==denuminator)
			{
				return j;
			}
		}
	}
	return 0;
}
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
Rational Rational::operator+(const Rational& R) const
{
	int i;
	if(denuminator == R.denuminator)
		return Rational(numerator + R.numerator, R.denuminator);
	else if(denuminator<R.denuminator)
	{
		b=true;
		int i=(*this).calculate_common_denuminator(R);
		if(i)
		{
			return Rational(i*numerator + R.numerator,R.denuminator);
		}
	}
	else if(denuminator>R.denuminator)
	{
		b=false;
		int i=(*this).calculate_common_denuminator(R);
		if(i)
		{
			return Rational(numerator + i*R.numerator,denuminator);
		}
	}
		return Rational(numerator * R.numerator  + R.numerator * denuminator, denuminator * R.denuminator);
}
Rational Rational::operator+(int n) const
{
	n*=denuminator;
	int denuminatorCopy=denuminator;
	int numeratorCopy=numerator;
	int bmm=BMM(n + numeratorCopy,denuminatorCopy);
	return Rational((n + numerator)/bmm,denuminator/bmm);
}
Rational& Rational::operator+=(const Rational& R)
{
	int i;
	if(denuminator == R.denuminator)
		{
			numerator += R.numerator;
			return *this;
		}
	else if(denuminator<R.denuminator)
	{
		b=true;
		int i=(*this).calculate_common_denuminator(R);
		if(i)
		{
			numerator=i*numerator + R.numerator;
			denuminator=R.denuminator;
			return *this;
		}
	}
	else if(denuminator>R.denuminator)
	{
		b=false;
		int i=(*this).calculate_common_denuminator(R);
		if(i)
		{
			numerator += i*R.numerator;
			return *this;
		}
	}
		numerator=numerator * R.numerator  + R.numerator * denuminator;
		denuminator*=R.denuminator;
		return *this;
}
Rational operator+(int n, Rational& R)
{
	n*=R.get2();
	int denuminatorCopy=R.get2();
	int numeratorCopy=R.get1();
	int bmm=BMM(n + numeratorCopy,denuminatorCopy);
	return Rational((n + R.get1())/bmm,R.get2()/bmm);	
}
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
Rational Rational::operator-(const Rational& R) const
{
	int i;
	if(denuminator == R.denuminator)
		return Rational(numerator - R.numerator, R.denuminator);
	else if(denuminator<R.denuminator)
	{
		b=true;
		int i=(*this).calculate_common_denuminator(R);
		if(i)
		{
			return Rational(i*numerator - R.numerator,R.denuminator);
		}
	}
	else if(denuminator>R.denuminator)
	{
		b=false;
		int i=(*this).calculate_common_denuminator(R);
		if(i)
		{
			return Rational(numerator - i*R.numerator,denuminator);
		}
	}
		return Rational(numerator * R.numerator  - R.numerator * denuminator, denuminator * R.denuminator);
}
Rational Rational::operator-(int n) const
{
	n*=denuminator;
	int denuminatorCopy=denuminator;
	int numeratorCopy=numerator;
	int bmm=BMM(n - numeratorCopy,denuminatorCopy);
	return Rational((n - numerator)/bmm,denuminator/bmm);
}
Rational& Rational::operator-=(const Rational& R)
{
	int i;
	if(denuminator == R.denuminator)
		{
			numerator -= R.numerator;
			return *this;
		}
	else if(denuminator<R.denuminator)
	{
		b=true;
		int i=(*this).calculate_common_denuminator(R);
		if(i)
		{
			numerator=i*numerator - R.numerator;
			denuminator=R.denuminator;
			return *this;
		}
	}
	else if(denuminator>R.denuminator)
	{
		b=false;
		int i=(*this).calculate_common_denuminator(R);
		if(i)
		{
			numerator -= i*R.numerator;
			return *this;
		}
	}
		numerator=numerator * R.numerator  - R.numerator * denuminator;
		denuminator*=R.denuminator;
		return *this;
}
Rational operator-(int n, Rational R)
{
	n*=R.get2();
	int denuminatorCopy=R.get2();
	int numeratorCopy=R.get1();
	int bmm=BMM(n - numeratorCopy,denuminatorCopy);
	return Rational((n - R.get1())/bmm,R.get2()/bmm);	
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
Rational Rational::operator*(const Rational& R) const
{
	int numeratorTemp,denuminatorTemp;
	numeratorTemp=numerator * R.numerator;
	denuminatorTemp=denuminator * R.denuminator;
	int bmm=BMM(numerator * R.numerator,denuminator * R.denuminator);
	return 	Rational(numeratorTemp/bmm,denuminatorTemp/bmm);
}
Rational Rational::operator*(int n)const
{
	int bmm=BMM(n * numerator,denuminator);
	return Rational((n * numerator) / bmm,denuminator/bmm);
}
Rational& Rational::operator*=(const Rational& R)
{
	int bmm=BMM(numerator * R.numerator,denuminator * R.denuminator);
	numerator=(numerator * R.numerator) / bmm;
	denuminator=(denuminator * R.denuminator) / bmm;
	return *this;
}
Rational operator*(int n, Rational R)
{
	int bmm=BMM(n * R.get1(),R.get2());
	return Rational((n * R.get1()) / bmm,R.get2() / bmm);
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
Rational Rational::operator/(const Rational& R) const
{
	int numeratorTemp,denuminatorTemp;
	numeratorTemp=numerator * R.denuminator;
	denuminatorTemp=denuminator * R.numerator;
	int bmm=BMM(numerator * R.denuminator,denuminator * R.numerator);
	return 	Rational(numeratorTemp/bmm,denuminatorTemp/bmm);
}
Rational Rational::operator/(int n)const
{
	int bmm=BMM(n * denuminator,numerator);
	return Rational((n * denuminator) / bmm,numerator/bmm);
}
Rational& Rational::operator/=(const Rational& R)
{
	int bmm=BMM(numerator / R.numerator,denuminator / R.denuminator);
	numerator=(numerator / R.numerator) / bmm;
	denuminator=(denuminator / R.denuminator) / bmm;
	return *this;
}
Rational operator/(int n, Rational R)
{
	int bmm=BMM(n * R.get2(),R.get1());
	return Rational((n * R.get2()) / bmm,R.get1() / bmm);
}
/***********************************************************************************************************************************************************/
void Rational::print() const
{
	if(numerator==0)
	{
		cout<<0<<endl;
	}
	else if(numerator==denuminator)
	{
		cout<<denuminator<<endl;
	}
	else
	{
	cout<<numerator<<"/"<<denuminator<<endl;
	}
}
/**************************************************************************************************************************************************************/
ostream& operator<<(ostream& out, const Rational& R)
{
	out<<R.numerator<<"/"<<R.denuminator<<endl;
}
/*************************************************************************************************************************************************************/
int main()
{
	Rational a(2,8);
	Rational b(5,72);
	Rational c= a * 5;
	a.print();
	b.print();
	c.print();
	cout<<c + a;
    return 0;
}

