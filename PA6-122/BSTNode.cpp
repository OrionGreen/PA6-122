#include "BSTNode.h"


BSTNode::BSTNode(const string& newString) {
	this->mString = newString;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

string BSTNode::getString() const {
	return this->mString;
}

BSTNode* BSTNode::getLeftPtr() const {
	return this->mpLeft;
}
BSTNode* BSTNode::getRightPtr() const {
	return this->mpRight;
}

void BSTNode::setLeftPtr(BSTNode* newPtr) {
	this->mpLeft = newPtr;
}
void BSTNode::setRightPtr(BSTNode* newPtr) {
	this->mpRight = newPtr;
}

std::ostream& operator<< (std::ostream& lhs, const BSTNode& rhs) {
	lhs << rhs.getString() << endl;
	return lhs;
}