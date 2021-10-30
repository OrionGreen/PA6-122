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
template <typename NODETYPE, typename S>
class BSTNode
{
public:
	BSTNode(const NODETYPE& newString, const S& newChar);

	S getmLetter(void) const;
	
	NODETYPE getmMorse(void) const;
	
	BSTNode<NODETYPE, S>* getLeftPtr(void) const;
	
	BSTNode<NODETYPE, S>* getRightPtr(void) const;

	void setmLetter(S const newLetter);
	
	void setmMorse(NODETYPE const newMorse);
	
	void setLeftPtr(BSTNode<NODETYPE, S>* newPtr);
	
	void setRightPtr(BSTNode<NODETYPE, S>* newPtr);

private:
	//NODETYPE with a char and 2 extra child nodes
	S mLetter;
	NODETYPE mMorse;
	BSTNode<NODETYPE, S>* mpLeft;
	BSTNode<NODETYPE, S>* mpRight;
};


template<typename NODETYPE, typename S>
BSTNode<NODETYPE, S>::BSTNode(const NODETYPE& newString, const S& newChar) {
	this->mLetter = newChar;
	this->mMorse = newString;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

//getters
template<typename NODETYPE, typename S>
S BSTNode<NODETYPE, S>::getmLetter() const {
	return this->mLetter;
}

template<typename NODETYPE, typename S>
NODETYPE BSTNode<NODETYPE, S>::getmMorse() const {
	return this->mMorse;
}

template<typename NODETYPE, typename S>
BSTNode<NODETYPE, S>* BSTNode<NODETYPE, S>::getLeftPtr() const {
	return this->mpLeft;
}

template<typename NODETYPE, typename S>
BSTNode<NODETYPE, S>* BSTNode<NODETYPE, S>::getRightPtr() const {
	return this->mpRight;
}

//setters
template<typename NODETYPE, typename S>
void BSTNode<NODETYPE, S>::setmLetter(S const newLetter) {
	this->mLetter = newLetter;
}

template<typename NODETYPE, typename S>
void BSTNode<NODETYPE, S>::setmMorse(NODETYPE const newMorse) {
	this->mMorse = newMorse;
}

template<typename NODETYPE, typename S>
void BSTNode<NODETYPE, S>::setLeftPtr(BSTNode<NODETYPE, S>* newPtr) {
	this->mpLeft = newPtr;
}
template<typename NODETYPE, typename S>
void BSTNode<NODETYPE, S>::setRightPtr(BSTNode<NODETYPE, S>* newPtr) {
	this->mpRight = newPtr;
}

//Not necessary and never used but its an overload
template<typename NODETYPE, typename S>
std::fstream& operator >> (std::fstream& lhs, const BSTNode<std::string, char>& rhs) {
	char data[100] = "";
	lhs.getline(data, 100);
	rhs.setmLetter(data[0]);
	lhs.getline(data, 100);
	rhs.setmMorse(data);

	return lhs;
}

