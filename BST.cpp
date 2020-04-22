#include <iostream>
#include "BST.hpp"

using namespace std;

BST::BST()
{
	root = NULL;
}
BST::BST(string s)
{
	root = new TNode(s);
}

void BST::clearTree()
{
	if (root == NULL)
	{
		cout << "Tree already empty" << endl;
	}
	else
	{
		cout << endl
			 << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(TNode *tmp)
{
	if (tmp == NULL)
	{
		return;
	}
	else
	{
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete (tmp);
	}
}

void BST::setHeight(TNode *n)
{
	n->height = 1;
	int newHeight = 1;
	while (n->parent != NULL)
	{
		n = n->parent;
		newHeight++;
		if (newHeight > n->height)
		{
			n->height = newHeight;
		}
		else
		{
			break;
		}
	}
}

void BST::printTreePre(TNode *n)
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void BST::printTreePre()
{
	if (root == NULL)
	{
		cout << "Empty Tree" << endl;
	}
	else
	{
		cout << endl
			 << "Printing PreOrder:" << endl;
		printTreePre(root);
	}
}

bool BST::insert(string s)
// /* Parameter: string
//  *
//  * Return: boolean.
//  *
//  * this method takes as an input parameter a string (which will go
//  * into the phrase field of the data when a node is created to be inserted) and returns
//  * true if the data is inserted successfully, false otherwise.
//  */
{
	bool inserted = false;
	TNode *tmp = root;

	if (root == NULL)
	{
		root = new TNode(s);
		setHeight(root);
		inserted = true;
		return inserted;
	}

	while (true)
	{
		if (s > tmp->data->phrase && tmp->right != NULL)
		{
			tmp = tmp->right;
			continue;
		}
		if (s < tmp->data->phrase && tmp->left != NULL)
		{
			tmp = tmp->left;
			continue;
		}
		if ((s > tmp->data->phrase && tmp->right == NULL) || (s < tmp->data->phrase && tmp->left == NULL))
		{
			break;
		}

		return inserted;
	}
	inserted = true;
	TNode *insertNode = new TNode(s);
	insertNode->parent = tmp;
	if (s > tmp->data->phrase)
	{
		tmp->right = insertNode;
	}
	else
	{
		tmp->left = insertNode;
	}
	setHeight(insertNode);

	return inserted;
}

void BST::printTreeIO()
{
	if (root == NULL)
	{
		cout << "Empty Tree" << endl;
	}
	else
	{
		cout << endl
			 << "Printing In Order:" << endl;
		printTreeIO(root);
	}
}

void BST::printTreeIO(TNode *n)
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BST::printTreePost()
{
	if (root == NULL)
	{
		cout << "Empty Tree" << endl;
	}
	else
	{
		cout << endl
			 << "Printing PostOrder:" << endl;
		printTreePost(root);
	}
}

void BST::printTreePost(TNode *n)
{
	if (n == NULL)
	{
		return;
	}
	else
	{
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}

TNode *BST::find(string s)
{
	return recursiveFind(root, s);
}

TNode *BST::recursiveFind(TNode *n, string s)
{
	if (n->data->phrase == s)
	{
		cout << "the node holding " << s << endl;
		return n;
	}
	if (n->data->phrase < s)
	{
		if (n->right != NULL)
			return recursiveFind(n->right, s);
	}
	if (n->data->phrase > s)
	{
		if (n->left != NULL)
			return recursiveFind(n->left, s);
	}
	return NULL;
}
TNode *BST::remove(string s)
{
	TNode *removeNode = find(s);
	int childrenNum = 0;
	if (removeNode->left != NULL)
		childrenNum++;
	if (removeNode->right != NULL)
		childrenNum++;

	if (childrenNum == 0)
		removeNoKids(removeNode);
}
TNode* BST::removeOneKid(TNode *tmp, bool leftFlag)
{
	TNode *kid = leftFlag ? tmp->left : tmp->right;
	

	// if (tmp->left == nullptr && tmp->right != nullptr) {
	// 	leftFlag = false;
	// 	TNode *tmp = root;
	// 	root = root->left;
	// 	delete tmp;
	// 	tmp = NULL;
	// } else if (tmp->left != nullptr && tmp->right == nullptr) {
	// 	TNode *tmp = root;
	// 	root = root->right;
	// 	delete tmp;
	// 	tmp = NULL;
	// }
	return tmp;
}

TNode *BST::removeNoKids(TNode *tmp)
{
	delete tmp;
	return tmp;
}

// TNode *BST::find(TNode *n, string s);
// /* Parameter:a string pointer, string
//  *
//  * Return: a string pointer.
//  *
//  * finds whether s is in the phrase part of the data in the
//  * tree,and, if it is, returns the node holding s. Otherwise it returns NULL.
//  */
// void BST::printTreeIO(TNode *n);
// /* Parameter:a string pointer
//  *
//  * Return: None.
//  *
//  * prints out the data in the tree in order
//  */
// void BST::printTreePre(TNode *n);
// /* Parameter:a string pointer
//  *
//  * Return: None.
//  *
//  * prints out the data in the tree in pre-order.
//  */
// void BST::printTreePost(TNode *n);
// /* Parameter:a string pointer
//  *
//  * Return: None.
//  *
//  * prints out the data in the tree in post-order.
//  */
// TNode *BST::remove(string s);
// /* Parameter:a string pointer
//  *
//  * Return: a string pointer.
//  *
//  * this method removes a node from the tree, and returns
//  * a string pointer. This function contains three ways to
//  * remove the node which has no children, one child, two children
//  */
// TNode *BST::removeNoKids(TNode *tmp);
// /* Parameter:a string pointer
//  *
//  * Return: a string pointer.
//  *
//  * removing a node with no children.
//  */
// TNode *BST::removeOneKids(TNode *tmp, bool leftFlag);
// /* Parameter:a string pointer, a boolean

//  *
//  * Return: a string pointer.
//  *
//  * for removing a node with one child, with the leftFlag indicating
//  * whether the node’s child is either the left child or the right child.
//  */

// void BST::setHeight(TNode *n);
// /* Parameter:a string pointer
//  *
//  * Return: None.
//  *
//  * This method sets the heights of the nodes in a tree.
//  * Once a node is inserted, only the node’s ancestors can have their height changed.
//  * Thus you should set the height of the node being inserted (to 1) and then adjust the
//  * heights of the node’s parent, grandparent, etc. up until either the height of the
//  * node doesn’t change or you hit the root.
//  */


