#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;


class BSTNode
{
public:
	BSTNode(const string& newString = "");

	string getString(void) const;

	BSTNode* getLeftPtr(void) const;
	BSTNode* getRightPtr(void) const;

	void setLeftPtr(BSTNode* newPtr);
	void setRightPtr(BSTNode* newPtr);

private:
	char mLetter;
	string mMorse;
	BSTNode* mpLeft;
	BSTNode* mpRight;
};

std::ostream& operator<< (std::ostream& lhs, const BSTNode& rhs);

