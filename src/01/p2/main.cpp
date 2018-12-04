/*
 * main.cpp
 *
 * Copyright 2018 Tom Veldman <t.c.veldman@student.utwente.nl>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char **argv)
{
	// Open input file for reading
	// Realize that the input differs per user
	ifstream inputFile;
	inputFile.open("input");

	// Some variables needed for the while loop
	int inputLine; // Each inputFile line needs to be cast to an int
	int sum; // Contains the sum of each inputLine
	vector<int> frequencyList; // A log of the sums we've had
	bool done = false; // Whether or not the double frequency has been found

	while (!done) {
		// Reset file pointer to beginning of file
		inputFile.clear();
		inputFile.seekg(0, ios::beg);

		// Loop through inputFile lines until EOF is reached
		while (inputFile >> inputLine) {
			// Search for the current sum in the log of sums
			auto result = find(begin(frequencyList), end(frequencyList), sum);

			// Because of the way find() works, check for whether the result is not the last vector index
			if ( result != end(frequencyList) ) {
				// If the sum has occured earlier, exit loops
				done = true;
				break;
			}
			frequencyList.push_back(sum);
			sum += inputLine;

			//cout << sum << endl;
		}

		//cout << "Reiterating through file" << endl;
	}

	// Print final sum to screen
	cout << "The double frequency is: " << sum << endl;

	// Be nice and close the inputFile
	inputFile.close();

	return 0;
}

