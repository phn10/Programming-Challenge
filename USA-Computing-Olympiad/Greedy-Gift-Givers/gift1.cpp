#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string *member;
	int *money;

	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	int size = 0;
	fin >> size;
	member = new string[size];
	money = new int[size];
	
	for (int i = 0; i < size; i++)
		money[i] = 0;

	for (int i = 0; i < size; i++)
	{
		string name;
		fin >> name;
		member[i] = name;
	}
	
	for (int i = 0; i < size; i++)
	{
		string name;
		int sum, number;
		fin >> name >> sum >> number;
		
		int s = 0;
		while (name.compare(member[s]) != 0)
			s++;

		money[s] -= sum;

		if (number != 0)
		{
			sum = sum / number;
			for (int j = 0; j < number; j++)
			{
				int k = 0;
				string nameSingle;

				fin >> nameSingle;
				while (nameSingle.compare(member[k]) != 0)
					k++;

				money[k] += sum;
			}
		}
	}
	
	for (int i = 0; i < size; i++)
	{
		fout << member[i] << " " << money[i] << endl;
	}

	return 0;
}
