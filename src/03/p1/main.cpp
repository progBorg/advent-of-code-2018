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

	// Find the maximum distance from point zero
	// i.e. the dimension of the superarea
	int fullWidth = 0;
	int fullHeight = 0;
	for (Area patch : patches) {
		if ((patch.getVert() + patch.getHeight()) > fullHeight) {
			fullHeight = patch.getVert() + patch.getHeight();
		}
		if ((patch.getHori() + patch.getWidth()) > fullWidth) {
			fullWidth = patch.getHori() + patch.getWidth();
		}
	}
	cout << "Superarea dimensions: " << fullWidth << 'x' << fullHeight << endl;

	// Sweep over the superarea, checking each point for overlap
	// Claims/patches are 0-indexed
	bool isPointClaimed;
	int multipleClaimedSpace = 0;
	for (int x = 0; x < fullWidth; x++) {
		for (int y = 0; y < fullHeight; y++) {

			// Reset point status
			isPointClaimed = false;
			// For the current point in the superarea, loop through all patches
			for (Area claim : patches) {

				// If the current patch encapsulates the current x
				if (claim.getHori() <= x && (claim.getHori() + claim.getWidth()) > x) {

					// If the current patch also encapsulates the current y
					if (claim.getVert() <= y && (claim.getVert() + claim.getHeight()) > y) {

						// If the current point has already been claimed before
						if (isPointClaimed) {
							// Increment the counter
							multipleClaimedSpace++;
							// Retrieve the next point in the superarea
							// We need to break out of multiple for-loops,
							//	so using a goto is our best option
							goto nextAreaPoint;
						} else {
							// ..else claim the point
							isPointClaimed = true;
						}
					}
				}
			}

		nextAreaPoint:
			continue; // Each label needs at least one command
		}
	}

	cout << "Square inches of space with multiple claims: " << multipleClaimedSpace << endl;

	// Be nice and close the inputFile
	inputFile.close();

	return 0;
}
