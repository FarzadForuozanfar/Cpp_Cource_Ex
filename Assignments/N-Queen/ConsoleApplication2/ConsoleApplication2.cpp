// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
const int m = 20;
int k[m][m];
int Count = 0;
int v = 0, n = 0, i = 0, j = 0, state = 0;

void remove(int i, int j)
{
	int p, q;
	k[i][j] = 0;
	Count--;
	for (p = 0; p<n; p++)
		if (p != i)
			k[p][j]--;
	for (p = 0; p<n; p++)
		if (p != j)
			k[i][p]--;
	p = i + 1;
	q = j + 1;
	while (p<n && q<n)
	{
		k[p++][q++]--;
	}
	p = i - 1;
	q = j - 1;
	while (p >= 0 && q >= 0)
	{
		k[p--][q--]--;
	}
	p = i + 1;
	q = j - 1;
	while (p<n && q >= 0)
	{
		k[p++][q--]--;
	}
	p = i - 1;
	q = j + 1;
	while (p >= 0 && q<n)
	{
		k[p--][q++]--;
	}
}

int apply(int i, int j)
{
	int p, q;
	k[i][j] = 1;
	Count++;
	for (p = 0; p<n; p++)
		if (p != i)
			k[p][j]++;
	for (p = 0; p<n; p++)
		if (p != j)
			k[i][p]++;
	p = i + 1;
	q = j + 1;
	while (p<n && q<n)
	{
		k[p++][q++]++;
	}
	p = i - 1;
	q = j - 1;
	while (p >= 0 && q >= 0)
	{
		k[p--][q--]++;
	}
	p = i + 1;
	q = j - 1;
	while (p<n && q >= 0)
	{
		k[p++][q--]++;
	}
	p = i - 1;
	q = j + 1;
	while (p >= 0 && q<n)
	{
		k[p--][q++]++;
	}
	return 0;
}

void draw()
{
	system("cls");
	for (int p = 0; p<n; p++)
	{
		for (int q = 0; q<n; q++)
		{
			if (k[p][q] != 1)
				cout << setw(3) << '*';
			else
				cout << setw(3) << 'Q';
		}
		cout << endl << endl;
	}
	cout << endl << endl << "Total states founded for " << n << "*" << n << " boards and " << v << " Queens: " << state << endl;
}

int check()
{
	if (Count == v)
	{
		state++;
		draw();
		cout << endl << endl << "Press q to exit or any key to continue...";
		char str;
		cin >> str;
		switch (str)
	{
		case 'q':
			system("cls");
			cout << "exit";
			system("pause");
			break;
			return 0;
	}
		//system("pause");









	}
}

void move(int p, int q)
{
	apply(p, q);
	check();
	for (int i = p; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			if (k[i][j] == 0)
				move(i, j);
	}
	remove(p, q);
}

int main()
{
	cout << "**************Queens******************" << endl << endl;
	cout << "Enter size of board :";
	cin >> n;
	cout << "Enter number of queens:";
	cin >> v;
	system("cls");
	draw();
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			move(i, j);

	system("cls");
	cout << "Total states:" << state << endl;
	system("pause>0");
	return 0;
}