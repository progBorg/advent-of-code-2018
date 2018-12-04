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
using namespace std;

int main(int argc, char **argv)
{
	// Open input file for reading
	// Realize that the input differs per user
	ifstream inputFile;
	inputFile.open("input");

	// Loop through inputFile lines until EOF is reached
	int inputLine; // Each inputFile line needs to be cast to an int
	int sum; // Contains the sum of each inputLine
	while (inputFile >> inputLine) {
		sum += inputLine;
	}

	// Print final sum to screen
	cout << sum << endl;

	// Be nice and close the inputFile
	inputFile.close();

	return 0;
}
