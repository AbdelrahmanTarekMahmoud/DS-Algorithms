#include <iostream>
#include <string>
#include <vector>
#include<queue>
#include <stdlib.h>

//Construct Node
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};

//Make A new Node for our BST
BSTNode* GetNewNode(int value)
{
	BSTNode* NewNode = new BSTNode;
	NewNode->data = value;
	NewNode->left = nullptr;
	NewNode->right = nullptr;

	return NewNode;
}
//insert data with given value
BSTNode* Insert(BSTNode* root, int value)
{
	if (root == nullptr) { root = GetNewNode(value); }
	else if (value < root->data)
	{
		root->left = Insert(root->left, value);
	}
	else if (value > root->data)
	{
		root->right = Insert(root->right, value);
	}

	return root;
}
//Search for A node 
bool Search(BSTNode* root, int data)
{
	if (root == nullptr) return false;
	else if (data == root->data) return true;
	else if (data < root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}
}
//Find Minimum elemtn int BSt And return its (Value)
int FindMin(BSTNode* root)
{
	if (root == nullptr) return -1;
	if (root->left == nullptr) return root->data;
	return FindMin(root->left);
}
//Find Minimum elemtn int BSt And return the (Node)
BSTNode* FindMinNode(BSTNode* root)
{
	if (root == nullptr) return nullptr;
	if (root->left == nullptr) return root;
	 
	return FindMinNode(root->left);
}
//Find Maximum elemtn int BSt And return its (Value)
int  FindMax(BSTNode* root)
{
	if (root == nullptr) return -1;
	if (root->right == nullptr) return root->data;

	return FindMax(root->right);
}
// Find The Height Of The BST
int FindHeight(BSTNode* root)
{
	if (root == nullptr) return -1;

	return std::max(FindHeight(root->left), FindHeight(root->right)) + 1;
}
//Print In BFS
void PrintBFS(BSTNode* root)
{
	std::queue<BSTNode*> Q;
	if (root == nullptr) return;
	Q.push(root);
	while (!Q.empty())
	{
		BSTNode* current = Q.front();
		std::cout << current->data << " ";
		if (current->left != nullptr) Q.push(current->left);
		if (current->right != nullptr) Q.push(current->right);
		Q.pop();
	}
	std::cout << std::endl;
}
//Check if its BST (helper Function)
bool IsBetween(BSTNode* root, int min, int max)
{
	if (root == nullptr) return true;
	if (root->data > min && root->data < max
		&& IsBetween(root->left, min, root->data)
		&& IsBetween(root->right, root->data, max))
		return true;
	else return false;
}
//Check if its BST
bool IsBST(BSTNode* root)
{
	return IsBetween(root, INT_MIN, INT_MAX);
}
//Delete Node 
BSTNode* Delete(BSTNode* root, int value)
{
	if (root == nullptr) return nullptr;

	else if (value < root->data) root->left = Delete(root->left, value);
	else if (value > root->data) root->right = Delete(root->right, value);
	else //FOUND
	{
		//Case 1 : Leaf
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root; //dangling pointer
			root = nullptr;
		}
		//case 2 : 1 Child
		else if (root->left == nullptr)
		{
			BSTNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			BSTNode* temp = root;
			root = root->left;
			delete temp;
		}
		//case 3 : 2 Childs
		else
		{
			BSTNode* temp = FindMinNode(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

int main()
{
	BSTNode* root = nullptr;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 12);
	root = Insert(root, 8);
	root = Insert(root, 9);
	root = Insert(root, 5);
	root = Insert(root, 7);
	root = Insert(root, 23);
	root = Insert(root, 16);
	root = Insert(root, 44);
	root = Insert(root, 2);
	root = Insert(root, 32);

	int min = FindMin(root);
	int max = FindMax(root);
	int height = FindHeight(root);

	std::cout << "Min : " << min << std::endl;
	std::cout << "Max : " << max << std::endl;
	std::cout << "Height : " << height << std::endl;

	 PrintBFS(root);

	 std::cout << "Is it BST ?! " << IsBST(root) << std::endl;

	 root = Delete(root, 23);
	 PrintBFS(root);


}



