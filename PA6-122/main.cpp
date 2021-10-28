#include "BST.h"

int main(void) {
	
	//make the morsetable BST
	BST<string> morsetable;
	//print the morse table
	morsetable.inorderPrint();
	fstream conversion;
	conversion.open("Convert.txt", std::ios::in);

	//convert from file
	morsetable.convertText(conversion);

	return 0;
}