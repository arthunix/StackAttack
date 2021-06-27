#ifndef BLOCK_H
#define	BLOCK_H

/* These is the most basic instance of the game, the block */
class block {
private:
	/* It's just the atributte for color
	* 0 for void block
	* 1 for orange
	* 2 for blue
	* 3 for pink
	* 4 for red
	* 5 for yellow
	* 6 for green
	*/
	
	/// <Position and column/line paradigma>
	/// I think this position refers to the line and the column internal
	/// position... the main method will call this for drawing they need
	/// to be update every time in every change
	/// </we set an internal position value for the block flutuancy>
	unsigned short int color = 0;
	unsigned short int line = 0;
	unsigned short int column = 0;
public:
	/* Related to the block color */
	bool setcolor(unsigned short int color) {
		this->color = color;
		return true;
	}
	unsigned short int getcolor() {
		return this->color;
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