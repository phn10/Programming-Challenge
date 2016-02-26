/*
NAME: phn101
PROB: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int mod(int n, int m)
{
	if (n < 0)
		n += m;
	return n % m;
}

int main()
{
	int size = 0;
	string array = "";
	
	ifstream fin ("beads.in");
	ofstream fout ("beads.out");
	int sum = 0;
	int index = 0;
	fin >> size >> array;

	for (int i = 0; i < size; i++)
	{
		int index1 = mod(i + 1, size);
		int index2 = i;
		char color = 'w';
		int count1 = 0;
		int count2 = 0;

		for (count1 = 0; count1 < size; count1++, index1 = mod(index1 + 1, size))
		{

			if (color == 'w' && array[index1] != 'w')
				color = array[index1];
			
			// condition to break the loop
			if (color != 'w' && array[index1] != 'w' && array[index1] != color)
				break;
		}

		color = 'w';

		for (count2 = 0; count2 < size; count2++, index2 = mod(index2 - 1, size))
		{
			if (color == 'w' && array[index2] != 'w')
				color = array[index2];

			if (color != 'w' && array[index2] != 'w' && array[index2] != color)
				break;
		}


		if (sum < count1 + count2)
		{
			sum = count1 + count2;
			index = index2; 
		}
	}
	if (sum > size)
		sum = size;
	
	fout << sum << "\n";
	return 0;
}
