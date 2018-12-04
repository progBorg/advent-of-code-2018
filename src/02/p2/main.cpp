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
#include <string>

using namespace std;

bool findDoubles(string inputLine);
bool findTriples(string inputLine);

int main(int argc, char **argv)
{
	// Open input file for reading
	// Realize that the input differs per user
	ifstream inputFile;
	inputFile.open("input");

	// Set up variables for the while loop
	string inputLine;
	string compareLine;
	bool thisIsTheBox;
	// Repeat for all lines in inputFile until EOF is reached
	while (inputFile >> inputLine) {
		//cout << endl << "Next inputLine" << endl;
		// Store file pointer of current line
		int headFilePointer = inputFile.tellg();

		// For clarity's sake: the file pointer is set at the next line
		//	by the expression in the above while-loop statement

		// Compare the current inputLine to all following lines until EOF is reached
		while (inputFile >> compareLine) {
			//cout << "compareLine: " << compareLine << endl;
			thisIsTheBox = false;

			// For each character in the line
			for (int i = 0; i < (int) inputLine.length(); i++) {
				//cout << "Current check: " << inputLine[i] << " != " << compareLine[i] << endl;
				// If the characters are different
				if (inputLine[i] != compareLine[i]) {
					// Firstly, invert state
					thisIsTheBox = !thisIsTheBox;
					// If there already is another different character
					if (!thisIsTheBox) {
						// ...then this is definitely not the box we want
						thisIsTheBox = false;
						break; // break out of for-loop
					}
					// Else this is the first different character
				}
			}

			if (thisIsTheBox) {
				// Print both box serials
				cout << "Box serial numbers matching requirements:" << endl << inputLine << endl << compareLine << endl << endl;
			}

		}

		// Set file pointer back to what it was at the start of the current loop
		inputFile.clear(); // First clear eof flags and such
		inputFile.seekg(headFilePointer, ios::beg);

	}

	// Be nice and close the inputFile
	inputFile.close();

	return 0;
}
