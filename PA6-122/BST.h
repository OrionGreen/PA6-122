#pragma once
#include "BSTNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;
using std::string;

//class template for a BST
template <class CLASSTYPE, class S>
class BST
{
public:
	BST();

	~BST();

	void insert(const CLASSTYPE& newMorse, const S& newchar);

	void inorderTraversal(const S& Letter);

	void convertText(fstream& infile);

	void inorderPrint();

private:
	void inorderPrint(BSTNode<CLASSTYPE, S>* pTree);

	void insert(BSTNode<CLASSTYPE, S>* pTree,
		const CLASSTYPE& newMorse, const S& newChar);

	void chopTree(BSTNode<CLASSTYPE, S>* pTree);

	void inorderTraversal(BSTNode<CLASSTYPE, S>* pTree, const S& Letter);

	void convertText(fstream& infile, BSTNode<CLASSTYPE, S>* pTree);

	BSTNode<CLASSTYPE, S>* mpRoot;
};

//populate the BST on creation with the morse table
template<class CLASSTYPE, class S>
BST<CLASSTYPE, S>::BST() {
	this->mpRoot = nullptr;
	fstream table;
	if (!table.is_open()) {
		table.open("MorseTable.txt", std::ios::in);
		while (!table.eof()) {
			S morse[100] = "";
			S character = '\0';
			S throwaway[20] = "";
			table.get(character);
			table.getline(throwaway, 100);
			table.getline(morse, 100);
			insert(morse, character);
		}
		table.close();
	}
}

//destroys the tree using a chop tree helper function
template<class CLASSTYPE, class S>
BST<CLASSTYPE, S>::~BST() {
	chopTree(this->mpRoot);
}

//public insert
template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::insert(const CLASSTYPE& newMorse, const S& newchar) {
	insert(this->mpRoot, newMorse, newchar);
}

//public inorder traversal 
template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::inorderTraversal(const S& Letter) {
	
	inorderTraversal(this->mpRoot, Letter);
}

//private versions
template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::chopTree(BSTNode<CLASSTYPE, S>* pTree) {
	if (pTree != nullptr) {
		chopTree(pTree->getLeftPtr());
		chopTree(pTree->getRightPtr());
		delete pTree;
	}
}

//private insert
template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::insert(BSTNode<CLASSTYPE, S>* pTree, const CLASSTYPE& newMorse, const S& newChar) {
	if (pTree == nullptr)
	{
		this->mpRoot = new BSTNode<CLASSTYPE, S>(newMorse, newChar);
	}
	else
	{
		if (pTree->getmLetter() > newChar)
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new BSTNode<CLASSTYPE, S>(newMorse, newChar));
			}
			else
			{
				insert(pTree->getLeftPtr(), newMorse, newChar);
			}
		}

		else if (pTree->getmLetter() < newChar)
		{

			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new BSTNode<CLASSTYPE, S>(newMorse, newChar));
			}
			else
			{
				insert(pTree->getRightPtr(), newMorse, newChar);
			}
		}
	}

}

//private inorderTraversal which prints out the morse code of the letter entere
template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::inorderTraversal(BSTNode<CLASSTYPE, S>* pTree, const S& Letter) {
	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeftPtr(), Letter);
		if (Letter == pTree->getmLetter()) {
			cout << pTree->getmMorse()<< " ";
		}
		inorderTraversal(pTree->getRightPtr(), Letter);
	}
	
}

//prints which prints in order of the tree which starts leftmost starting with my space character
template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::inorderPrint() {
	inorderPrint(this->mpRoot);
}

template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::inorderPrint(BSTNode<CLASSTYPE, S>* pTree) {
	if (pTree != nullptr)
	{
		inorderPrint(pTree->getLeftPtr());
			cout << pTree->getmLetter() << endl;
			cout << pTree->getmMorse() << endl;
		inorderPrint(pTree->getRightPtr());
	}

}

//converting text from a file take lines to upper case and insert each char into the traversal function which then prints the stuff.
template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::convertText(fstream& infile, BSTNode<CLASSTYPE, S>* pTree) {
	char data[100] = "";
	CLASSTYPE dat;
	while (!infile.eof()) {
		infile.getline(data, 100);
		int i = 0;
		while (data[i] != '\0') {
			data[i] = toupper(data[i]);
			inorderTraversal(data[i]);
			i++;
		}
		cout << endl;
	}
}

template<class CLASSTYPE, class S>
void BST<CLASSTYPE, S>::convertText(fstream& infile) {
	
	convertText(infile ,this->mpRoot);
}