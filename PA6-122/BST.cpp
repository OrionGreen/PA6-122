#include "BST.h"

BST::BST() {

}

BST::~BST() {
	chopTree(this->mpRoot);
}

void BST::insert(const string& newString) {
	insert(this->mpRoot, newString);
}

void BST::inorderTraversal() {
	inorderTraversal(this->mpRoot);
}

void BST::preorderTraversal() {
	preorderTraversal(this->mpRoot);
}

void BST::postorderTraversal() {
	postorderTraversal(this->mpRoot);
}

//private versions
void BST::chopTree(BSTNode* pTree) {
	if (pTree != nullptr) {
		chopTree(pTree->getLeftPtr());
		chopTree(pTree->getRightPtr());
		delete pTree;
	}
}

void BST::insert(BSTNode* pTree, const string& newString) {
	if (pTree == nullptr)
	{
		this->mpRoot = new BSTNode(newString);
	}
	else
	{
		if (pTree->getString() > newString)
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new BSTNode(newString));
			}
			else
			{
				insert(pTree->getLeftPtr(), newString);
			}
		}

		else if (pTree->getString() < newString)
		{

			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new BSTNode(newString));
			}
			else
			{
				insert(pTree->getRightPtr(), newString);
			}
		}
	}

}

void BST::inorderSave(vector<string>& names) {
	inorderSave(this->mpRoot, names);
}

void BST::inorderSave(BSTNode* pTree, vector<string>& names) {
	if (pTree != nullptr)
	{
		inorderSave(pTree->getLeftPtr(), names);
		names.push_back(pTree->getString());
		inorderSave(pTree->getRightPtr(), names);
	}
}

void BST::inorderTraversal(BSTNode* pTree) {

	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeftPtr());
		cout << pTree->getString() << endl;
		inorderTraversal(pTree->getRightPtr());
	}
}

void BST::preorderTraversal(BSTNode* pTree) {
	if (pTree != nullptr)
	{
		cout << pTree->getString() << endl;
		preorderTraversal(pTree->getLeftPtr());
		preorderTraversal(pTree->getRightPtr());
	}
}

void BST::postorderTraversal(BSTNode* pTree) {
	if (pTree != nullptr)
	{
		postorderTraversal(pTree->getLeftPtr());
		postorderTraversal(pTree->getRightPtr());
		cout << pTree->getString() << endl;
	}

}