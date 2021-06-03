#ifndef BLOCK_H
#define	BLOCK_H

class block {
private:
	/* It's just the atributte for color
	* 1 for red
	* 2 for green
	* 3 for blue
	* 4 for yellow
	* 5 for orange
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