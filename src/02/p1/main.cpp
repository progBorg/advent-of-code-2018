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

	// Set up variables to be used in loop
	string inputLine;
	int doubles = 0; // Number of found double characters
	int triples = 0; // Number of found triple characters

	// Find doubles and triples separately for each inputLine
	while (inputFile >> inputLine) {
		doubles += (int) findDoubles(inputLine);
		triples += (int) findTriples(inputLine);
	}

	// Display checksum
	cout << "Checksum: " << doubles << '*' << triples << '=' << doubles * triples << endl;

	// Be nice and close the inputFile
	inputFile.close();

	return 0;
}

bool findDoubles(string inputLine) {

	// For each character in inputLine
	for (int i = 0; i < (int) inputLine.length(); i++) {

		// For each following character after i in inputLine
		for (int j = i+1; j < (int) inputLine.length(); j++) {

			// Compare the two characters
			if (inputLine[i] == inputLine[j]) {

				// If the characters match, check if it's an exact double
				int charsFound = 0;
				// We'll have to loop through the entire string again, to see
				//	if there aren't the same characters before or after the current one
				for (int k = 0; k < (int) inputLine.length(); k++) {
					charsFound += (int) (inputLine[i] == inputLine[k]);
				}

				// If exactly a double was found, return true
				if (charsFound == 2) {
					return true;
				}

			}
		}
	}

	// If no double was ever found, return false
	return false;
}

bool findTriples(string inputLine) {

	// For each character in inputLine
	for (int i = 0; i < (int) inputLine.length(); i++) {

		// For each following character after i in inputLine
		for (int j = i+1; j < (int) inputLine.length(); j++) {

			// If a double was found, continue search for triple
			if (inputLine[i] == inputLine[j]) {

				// For each following character after j in inputLine
				for (int k = j+1; k < (int) inputLine.length(); k++) {
					// If an additional match is found, celebrate
					if (inputLine[i] == inputLine[k]) {
						// If the characters match, check if it's an exact triple
						int charsFound = 0;
						// We'll have to loop through the entire string again, to see
						//	if there aren't the same characters before or after the current one
						for (int k = 0; k < (int) inputLine.length(); k++) {
							charsFound += (int) (inputLine[i] == inputLine[k]);
						}

						// If exactly a double was found, return true
						if (charsFound == 3) {
							return true;
						}
					}

				}
			}

		}
	}

	// If no triple was ever found, return false
	return false;
}
