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

class BST
{
public:
	BST();

	~BST();

	void insert(const string& newString);

	void inorderSave(vector<string>& names);
	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();

private:
	void insert(BSTNode* pTree,
		const string& newString);

	void chopTree(BSTNode* pTree);

	void inorderSave(BSTNode* pTree, vector<string>& names);

	void inorderTraversal(BSTNode* pTree);

	void preorderTraversal(BSTNode* pTree);

	void postorderTraversal(BSTNode* pTree);

	BSTNode* mpRoot;
};
