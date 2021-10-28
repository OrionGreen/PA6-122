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

//BSTNODE class template
template <typename NODETYPE>
class BSTNode
{
public:
	BSTNode(const NODETYPE& newString, const char& newChar);

	char getmLetter(void) const;
	
	NODETYPE getmMorse(void) const;
	
	BSTNode<NODETYPE>* getLeftPtr(void) const;
	
	BSTNode<NODETYPE>* getRightPtr(void) const;

	void setmLetter(char const newLetter);
	
	void setmMorse(NODETYPE const newMorse);
	
	void setLeftPtr(BSTNode<NODETYPE>* newPtr);
	
	void setRightPtr(BSTNode<NODETYPE>* newPtr);

private:
	//NODETYPE with a char and 2 extra child nodes
	char mLetter;
	NODETYPE mMorse;
	BSTNode<NODETYPE>* mpLeft;
	BSTNode<NODETYPE>* mpRight;
};


template<typename NODETYPE>
BSTNode<NODETYPE>::BSTNode(const NODETYPE& newString, const char& newChar) {
	this->mLetter = newChar;
	this->mMorse = newString;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

//getters
template<typename NODETYPE>
char BSTNode<NODETYPE>::getmLetter() const {
	return this->mLetter;
}

template<typename NODETYPE>
NODETYPE BSTNode<NODETYPE>::getmMorse() const {
	return this->mMorse;
}

template<typename NODETYPE>
BSTNode<NODETYPE>* BSTNode<NODETYPE>::getLeftPtr() const {
	return this->mpLeft;
}

template<typename NODETYPE>
BSTNode<NODETYPE>* BSTNode<NODETYPE>::getRightPtr() const {
	return this->mpRight;
}

//setters
template<typename NODETYPE>
void BSTNode<NODETYPE>::setmLetter(char const newLetter) {
	this->mLetter = newLetter;
}

template<typename NODETYPE>
void BSTNode<NODETYPE>::setmMorse(NODETYPE const newMorse) {
	this->mMorse = newMorse;
}

template<typename NODETYPE>
void BSTNode<NODETYPE>::setLeftPtr(BSTNode<NODETYPE>* newPtr) {
	this->mpLeft = newPtr;
}
template<typename NODETYPE>
void BSTNode<NODETYPE>::setRightPtr(BSTNode<NODETYPE>* newPtr) {
	this->mpRight = newPtr;
}

//Not necessary and never used but its an overload
template<typename NODETYPE>
std::fstream& operator >> (std::fstream& lhs, const BSTNode<std::string>& rhs) {
	char data[100] = "";
	lhs.getline(data, 100);
	rhs.setmLetter(data[0]);
	lhs.getline(data, 100);
	rhs.setmMorse(data);

	return lhs;
}

