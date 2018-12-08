/*
 * area.cpp
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

#include "area.h"

Area::Area(string input) {
	// Parse string contents and store them in their respective variables
	const char *inputArr = input.c_str();
	sscanf(inputArr, "#%d @ %d,%d: %dx%d", &id, &hori, &vert, &width, &height);
}

int Area::getId() {
	return id;
}

int Area::getWidth() {
	return width;
}

int Area::getHeight() {
	return height;
}

int Area::getVert() {
	return vert;
}

int Area::getHori() {
	return hori;
}
