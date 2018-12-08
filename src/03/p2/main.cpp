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
#include <vector>
#include "area.h"

using namespace std;

int main(int argc, char **argv)
{
	// Open input file for reading
	// Realize that the input differs per user
	ifstream inputFile;
	inputFile.open("input");

	// Set up variables to be used in loop
	string inputLine;
	vector<Area> patches; // The collection of patches

	// Loop through inputFile until eof is reached
	// This will extract all patches and parse them into objects
	while (getline(inputFile, inputLine)) {
		// Basically push_back, but memory efficient
		// Creates a new Area() in place at the end of patches
		patches.emplace_back(inputLine);
	}

	// Set up some variables for use during the upcoming loops
	bool isThisTheClaim;
	// Check each claim for whether any following patches overlap
	// For each available claim
	for (Area claim : patches) {
		// Reset claim state to default to true
		isThisTheClaim = true;

		// Loop through all following claims
		for (Area compClaim : patches) {
			//fcout << compClaim.getId() << endl;
			// If compClaim is not the current claim
			if (compClaim.getId() != claim.getId()) {
				// If compClaim is within the range of claim horizontally
				if (compClaim.getHori() < (claim.getHori() + claim.getWidth()) &&
						(compClaim.getHori() + compClaim.getWidth()) >= claim.getHori()) {
					// ..And compClaim is within the range of claim vertically
					if (compClaim.getVert() < (claim.getVert() + claim.getHeight()) &&
							(compClaim.getVert() + compClaim.getHeight()) >= claim.getVert()) {
						// ..Then there is overlap, so this is not the unique claim
						// Therefore, advance to the next claim
						isThisTheClaim = false;
						break;
					}
				}
			}
		}

		// If claim state wasn't changed, this claim is unique, so print it to screen
		if (isThisTheClaim) {
			cout << "Unique claim found: " << claim.getId() << endl;
		}
	}

	// Be nice and close the inputFile
	inputFile.close();

	return 0;
}
