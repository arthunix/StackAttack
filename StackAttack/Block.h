#ifndef BLOCK_H
#define	BLOCK_H

/* These is the most basic instance of the game, the block */
class block {
private:
	/* It's just the atributte for color
	* 1 for orange
	* 2 for blue
	* 3 for pink
	* 4 for red
	* 5 for yellow
	* 6 for green
	*/
	unsigned short int color = 0;

	/// <Position and column/line paradigma>
	/// I think this position refers to the position inside the column
	/// These values can then be within 0 and 50 (block size too)
	/// it moves from 0 to 50 at the defined velocity when it reach in
	/// next or previus this value will be reset, it is an internal
	/// position value
	/// </we set an internal position value for the block flutuancy>
	unsigned short int line = 0;
	unsigned short int column = 0;
public:
	/* Related to the block color */
	bool setcolor(unsigned short int color) {
		this->color = color;
		return true;
	}
	unsigned short int getcolor() {
		return color;
	}

	/* Related to the block matrix control */

	/* For the line control */
	bool setline(unsigned short int line) {
		this->line = line;
		return true;
	}
	unsigned short int getline() {
		return line;
	}
	/*For the column control*/
	bool setcolumn(unsigned short int column) {
		this->column = column;
		return true;
	}
	unsigned short int getcolumn() {
		return column;
	}
};

#endif /* BLOCK_H */