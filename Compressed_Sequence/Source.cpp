#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::stoi;
using std::vector;
using std::count;


int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		istringstream iss(line);
		vector<unsigned int> list_of_numbers;
		string s_int;

		// Convert each number from string to an int, and load into vector
		while (getline(iss, s_int, ' '))
		{
			unsigned int number = stoi(s_int);
			list_of_numbers.push_back(number);
		}

		// Cycle through list of unique numbers
		// Count number of occurrences of each value in the vector
		// Output the number of occurrences and the value
		auto beg = list_of_numbers.begin();
		auto end = list_of_numbers.end();

		while (beg != end)
		{
			int search_number = *beg;
			int counter = 1;
			++beg;
			if (beg == end)
			{
				cout << counter << " " << search_number << " ";
				break;
			}
			while (beg != end && search_number == *beg)
			{
				++counter;
				++beg;
			}
			cout << counter << " " << search_number << " ";
		}
		cout << endl;
	}

	return 0;
}