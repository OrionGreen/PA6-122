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

template <class CLASSTYPE>
class BST
{
public:
	BST();

	~BST();

	void insert(const CLASSTYPE& newMorse, const char& newchar);

	
	void inorderTraversal(const char& Letter);
	void convertText();

private:
	void insert(BSTNode<CLASSTYPE>* pTree,
		const CLASSTYPE& newMorse, const char& newChar);

	void chopTree(BSTNode<CLASSTYPE>* pTree);

	void inorderTraversal(fstream& outfile, BSTNode<CLASSTYPE>* pTree, const char& Letter);

	void convertText(fstream& infile, BSTNode<CLASSTYPE>* pTree);

	BSTNode<CLASSTYPE>* mpRoot;
};

template<class CLASSTYPE>
BST<CLASSTYPE>::BST() {
	fstream table;
	if (!table.is_open()) {
		table.open("MorseTable.txt", std::ios::in);
		while (!table.eof()) {
			char morse[100] = "";
			char character = '\0';
			table.getline(character, 1);
			table.getline(morse, 100);
			insert(morse, character);
		}
		table.close();
	}
}

template<class CLASSTYPE>
BST<CLASSTYPE>::~BST() {
	chopTree(this->mpRoot);
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::insert(const CLASSTYPE& newMorse, const char& newchar) {
	insert(this->mpRoot, newMorse, newChar);
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::inorderTraversal(const char& Letter) {
	fstream outfile;
	if (!outfile.is_open()) {
		outfile.open("MorseOutput.txt", std::ios::out);
	}
	inorderTraversal(outfile,this->mpRoot, Letter);
}

//private versions
template<class CLASSTYPE>
void BST<CLASSTYPE>::chopTree(BSTNode<CLASSTYPE>* pTree) {
	if (pTree != nullptr) {
		chopTree(pTree->getLeftPtr());
		chopTree(pTree->getRightPtr());
		delete pTree;
	}
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::insert(BSTNode<CLASSTYPE>* pTree, const CLASSTYPE& newMorse, const char& newChar) {
	if (pTree == nullptr)
	{
		this->mpRoot = new BSTNode(newMorse, newChar);
	}
	else
	{
		if (pTree->getString() > newChar)
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new BSTNode(newMorse, newChar));
			}
			else
			{
				insert(pTree->getLeftPtr(), newMorse, newChar);
			}
		}

		else if (pTree->getString() < newChar)
		{

			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new BSTNode(newMorse, newChar));
			}
			else
			{
				insert(pTree->getRightPtr(), newMorse, newChar);
			}
		}
	}

}

template<class CLASSTYPE>
void BST<CLASSTYPE>::inorderTraversal(fstream& outfile, BSTNode<CLASSTYPE>* pTree, const char& Letter) {
	if (pTree != nullptr)
	{
		inorderTraversal(outfile, pTree->getLeftPtr(), Letter);
		if (Letter == pTree->getmLetter) {
			cout << pTree->getmMorse() << " ";
			outfile << pTree->getmMorse() << " ";
		}
		inorderTraversal(outfile, pTree->getRightPtr(), Letter);
	}
	
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::convertText(fstream& infile, BSTNode<CLASSTYPE>* pTree) {
	char data[100] = "";

	while (!lhs.eof()) {
		infile.getline(data, 100);
		int i = 0;
		while (data[i] != '\n') {
			toupper(data[i]);
			inorderTraversal(data[i]);
			i++;
		}
		cout << endl;
	}
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::convertText() {
	convertText(this->mpRoot);
}