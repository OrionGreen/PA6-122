#include "BST.h"

int main(void) {
	
	BST<string> morsetable;
	morsetable.inorderPrint();
	fstream conversion;
	conversion.open("Convert.txt", std::ios::in);
	morsetable.convertText(conversion);

	return 0;
}