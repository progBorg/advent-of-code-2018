#ifndef AREA_H
#define AREA_H

#include <string>
using namespace std;

class Area {
private:
	int id;
	int width;
	int height;
	int vert;
	int hori;

public:
	/**
	 * Constructor.
	 * @param input The input string with dimension and location info
	 */
	Area(string input);

	/**
	 * Get the area id
	 */
	int getId();

	/**
	 * Get the width.
	 */
	int getWidth();

	/**
	 * Get the height.
	 */
	int getHeight();

	/**
	 * Get the vertical placement
	 */
	int getVert();

	/**
	 * Get the horizontal placement
	 */
	int getHori();
};

#endif // AREA_H
