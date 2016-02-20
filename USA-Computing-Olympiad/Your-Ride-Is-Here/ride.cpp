/*
 * Name: phn101
 * PROG: Ride
 * LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		             'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
			     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	ifstream fin("ride.in");
	string comet, group;
	int num1 = 1,
	    num2 = 1;
	fin >>  comet >> group;

	for (int i = 0; i < comet.length(); i++)
	{
		int j = 0;
		while (j < 26 && comet[i] != alphabet[j])
			j++;
		
		num1 *= (j + 1);
	}	

	for (int i = 0; i < group.length(); i++)
	{
		int j = 0;
		while (j < 26 && group[i] != alphabet[j])
			j++;

		num2 *= (j + 1);
	}

	
	if (num1 % 47 == num2 % 47)
		cout << "GO" << endl;
	else
		cout << "STAY" << endl;

	return 0;
}
