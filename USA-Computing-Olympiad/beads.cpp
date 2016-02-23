/*
NAME: phn101
LANG: C++
PROG: beads
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	
	vector<int> count;      
	string array;
	int size;

	fin >> size >> array;

	array = array + array;
	size = size * 2;
	
	int countChar = 0;
	char firstChar;
	char secondChar = array[0];

	for (int i = 1; i < size - 1; i++)
	{
		firstChar = secondChar;
		secondChar = array[i];
		countChar++;
		if (firstChar != secondChar)
		{
			count.push_back(countChar);
			countChar = 0;
		}
	}

	int firstBeads = 0;
	int secondBeads = 0;
	int biggestBeads = 0;

	for (int i = 0; i < count.size() - 1; i++)
	{
		firstBeads = count[i];
		secondBeads = count[i + 1];

		if (biggestBeads < firstBeads + secondBeads)
			biggestBeads = firstBeads + secondBeads;
	}

	fout << biggestBeads;
	return 0;
}
