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

	void insert(const CLASSTYPE& newMorse, const CLASSTYPE& newchar);

	
	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();

private:
	void insert(BSTNode<CLASSTYPE>* pTree,
		const CLASSTYPE& newMorse, const CLASSTYPE& newChar);

	void chopTree(BSTNode<CLASSTYPE>* pTree);

	void inorderTraversal(BSTNode<CLASSTYPE>* pTree);

	void preorderTraversal(BSTNode<CLASSTYPE>* pTree);

	void postorderTraversal(BSTNode<CLASSTYPE>* pTree);

	BSTNode<CLASSTYPE>* mpRoot;
};

template<class CLASSTYPE>
BST<CLASSTYPE>::BST() {

}

template<class CLASSTYPE>
BST<CLASSTYPE>::~BST() {
	chopTree(this->mpRoot);
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::insert(const CLASSTYPE& newMorse, const CLASSTYPE& newchar) {
	insert(this->mpRoot, newMorse, newChar);
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::inorderTraversal() {
	inorderTraversal(this->mpRoot);
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::preorderTraversal() {
	preorderTraversal(this->mpRoot);
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::postorderTraversal() {
	postorderTraversal(this->mpRoot);
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
void BST<CLASSTYPE>::insert(BSTNode<CLASSTYPE>* pTree, const CLASSTYPE& newMorse, const CLASSTYPE& newChar) {
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
void BST<CLASSTYPE>::inorderTraversal(BSTNode<CLASSTYPE>* pTree) {

	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeftPtr());
		cout << pTree->getString() << endl;
		inorderTraversal(pTree->getRightPtr());
	}
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::preorderTraversal(BSTNode<CLASSTYPE>* pTree) {
	if (pTree != nullptr)
	{
		cout << pTree->getString() << endl;
		preorderTraversal(pTree->getLeftPtr());
		preorderTraversal(pTree->getRightPtr());
	}
}

template<class CLASSTYPE>
void BST<CLASSTYPE>::postorderTraversal(BSTNode<CLASSTYPE>* pTree) {
	if (pTree != nullptr)
	{
		postorderTraversal(pTree->getLeftPtr());
		postorderTraversal(pTree->getRightPtr());
		cout << pTree->getString() << endl;
	}

}