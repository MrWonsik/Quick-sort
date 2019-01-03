//============================================================================
// Name        : Sortowanie.cpp
// Author      : Tomasz Wasacz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



int find_piwot(int *table, int left, int right)
{
	int piwot=table[right];
	int position=0;

	for(int i=0; i<=right-1; i++)
	{
		if(table[i] <= piwot)
		{
			swap(table[i], table[position]);
			position++;
		}
	}

	swap(table[position], table[right]);
	return position;
}

void quick_sort(int *table, int left, int right)
{
	if(left<right)
	{
		int p=find_piwot(table, left, right);
		quick_sort(table, left, p-1);
		quick_sort(table, p+1, right);
	}
}



void show_table(int *table, int table_size)
{
	for(int i=0;i<table_size;i++)
		cout << table[i] << endl;
}

int main() {
	srand(time(NULL));
	long int table_size=1000;
	int *table = new int[table_size];

	for(int i=0; i<table_size; i++)
		table[i]=rand() % table_size;

	cout << "Before sort: " << endl;
	show_table(table, table_size);

	quick_sort(table, 0, table_size-1);

	cout << "After sort: " << endl;
	show_table(table, table_size);
	return 0;
}
