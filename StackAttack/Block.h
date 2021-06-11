#ifndef BLOCK_H
#define	BLOCK_H

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
	unsigned short int color = 1;
public:
	bool setcolor(unsigned short int color) {
		this->color = color;
		return true;
	}
	unsigned short int getcolor() {
		return color;
	}
};

#endif /* BLOCK_H */