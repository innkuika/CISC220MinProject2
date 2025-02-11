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
/* Parameter:a string pointer
 *
 * Return: None.
 *
 * This method sets the heights of the nodes in a tree.
 * Once a node is inserted, only the node’s ancestors can have their height changed.
 * Thus you should set the height of the node being inserted (to 1) and then adjust the
 * heights of the node’s parent, grandparent, etc. up until either the height of the
 * node doesn’t change or you hit the root.
 */
{
	n->height = calcHeight(n);
	while (n->parent != NULL)
	{
		n = n->parent;
		n->height = calcHeight(n);
	}
}

int BST::calcHeight(TNode *node)
/* Parameter:a string pointer
 *
 * Return: INT.
 *
 * This method is used to calculate the height of each node after each change,
 */
{
	if (node == NULL)
		return 0;
	else
	{
		int leftHeight = calcHeight(node->left);
		int rightHeight = calcHeight(node->right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
}

void BST::printTreePre(TNode *n)
/* Parameter:a string pointer
 *
 * Return: None.
 *
 * prints out the data in the tree in pre-order.
 */
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
/* Parameter:a string pointer
 *
 * Return: None.
 *
 * prints out the data in the tree in pre-order.
 */
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
 /* Parameter: string
  *
  * Return: boolean.
  *
  * this method takes as an input parameter a string (which will go
  * into the phrase field of the data when a node is created to be inserted) and returns
  * true if the data is inserted successfully, false otherwise.
  */
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
/* Parameter:a string pointer
 *
 * Return: None.
 *
 * prints out the data in the tree in order
 */
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
/* Parameter:a string pointer
 *
 * Return: None.
 *
 * prints out the data in the tree in order
 */
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
/* Parameter:a string pointer
 *
 * Return: None.
 *
 * prints out the data in the tree in post-order.
 */
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
/* Parameter:a string pointer
 *
 * Return: None.
 *
 * prints out the data in the tree in post-order.
 */
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
/* Parameter: string
 *
 * Return: a string pointer.
 *
 * finds whether s is in the phrase part of the data in the
 * tree,and, if it is, returns the node holding s. Otherwise it returns NULL.
 */
{
	return recursiveFind(root, s);
}

TNode *BST::recursiveFind(TNode *n, string s)
/* Parameter:a string pointer, string
 *
 * Return: a string pointer.
 *
 * finds whether s is in the phrase part of the data in the
 * tree,and, if it is, returns the node holding s. Otherwise it returns NULL.
 */
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
/* Parameter:a string pointer
 *
 * Return: a string pointer.
 *
 * this method removes a node from the tree, and returns
 * a string pointer. This function contains three ways to
 * remove the node which has no children, one child, two children
 */
{
	TNode *removeNode = find(s);
	int childrenNum = 0;
	if (removeNode->left != NULL)
		childrenNum++;
	if (removeNode->right != NULL)
		childrenNum++;

	switch (childrenNum)
	{
	case 0:
		removeNoKids(removeNode);
		break;
	case 1:
		removeOneKid(removeNode, removeNode->parent->left == removeNode);
		break;
	case 2:
		removeTwoKids(removeNode);
		break;

	default:
		break;
	}
	return removeNode;
}
TNode *BST::removeOneKid(TNode *tmp, bool leftFlag)
/* Parameter:a string pointer, a boolean

 *
 * Return: a string pointer.
 *
 * for removing a node with one child, with the leftFlag indicating
 * whether the node’s child is either the left child or the right child.
 */
{
	TNode *kid = tmp->left != NULL ? tmp->left : tmp->right;
	TNode *parent = tmp->parent;
	cout << tmp->right->data->phrase << endl;

	kid->parent = parent;
	leftFlag ? parent->left = kid : parent->right = kid;
	setHeight(kid);

	return tmp;
}

TNode *BST::removeNoKids(TNode *tmp)
/* Parameter:a string pointer
 *
 * Return: a string pointer.
 *
 * This function is for removing a node with no children.
 */
{
	TNode *parent = tmp->parent;
	parent->left == tmp ? parent->left = NULL : parent->right = NULL;
	setHeight(tmp);

	return tmp;
}

TNode *BST::removeTwoKids(TNode *tmp)
/* Parameter:a string pointer
 *
 * Return: a string pointer.
 *
 * This function is for removing a node with two children.
 */
{
	TNode *replace = tmp->left;
	bool rightKidExist = false;

	while (replace->right != NULL)
	{
		replace = replace->right;
		rightKidExist = true;
	}

	rightKidExist ? replace->parent->right = NULL : replace->parent->left = NULL;
	replace->parent = NULL;
	if (tmp->parent != NULL)
	{
		tmp->parent->left == tmp ? tmp->parent->left = replace : tmp->parent->right = replace;
		replace->parent = tmp->parent;
		tmp->parent = NULL;
	}
	else{
		root = replace;
	}
	tmp->right->parent = replace;

	replace->right = tmp->right;
	tmp->right = NULL;

	if (rightKidExist)
	{
		tmp->left->parent = replace;
		replace->left = tmp->left;
		tmp->left = NULL;
	}

	TNode *reset = rightKidExist ? replace->parent : replace;
	setHeight(reset);
	return tmp;
}


