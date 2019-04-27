// Driver code
// CS 1410
// Project 9
// Author: Roger deBry
// Date last modified: April 2017 (CDA)
// -----------------------------------------

#include <iostream>
#include "dynarray.h"
using namespace std;

int main( )
{
	const char START = 'A';
	const int MAX = 12;

	// create a vector of chars
	DynArray<char> vectD;

	// push some values into the vector
	for (int i = 0; i < MAX; i++)
	{
		vectD.push_back(START + i);
	}

	// remove the last element
	vectD.pop_back();

	// add another value
	vectD.push_back('Z');

	// test memory management
	DynArray<char> vectD2 = vectD;
	// display the contents
	cout << "\n[";
	for (int i = 0; i < vectD2.size() - 1; i++)
	{
		cout << vectD2.at(i) << ", ";
	}

	cout << "..., " << vectD2.back() << "]\n";

	DynArray<char> vectD3;
	vectD3 = vectD2;
	cout << "\n[";
	for (int i = 0; i < vectD3.size() - 1; i++)
	{
		cout << vectD3.at(i) << ", ";
	}
	cout << "..., " << vectD3.back() << "]\n";

	vectD3.front() = '{';
	vectD3.back() = '}';
	cout << vectD3.front();
	for (int i = 1; i < vectD3.size() - 2; i++)
	{
		cout << vectD3.at(i) << ", ";
	}
	cout << vectD3.at(vectD3.size()-2) << vectD3.back() << endl;
}

